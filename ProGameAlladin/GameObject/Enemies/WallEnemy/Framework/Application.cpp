#include "Application.h"
#include "PhysicsManager.h"

US_NS_JK




Application::Application(
	const HINSTANCE& hInstance, 
	const LPCSTR& appName,
	const int& width, 
	const int& height,
	const bool& isFullScreen,
	Scene* startScene)
{
	this->_hInstance = hInstance;
	this->_windowClassName = appName;
	this->_width = width;
	this->_height = height;
	this->_isFullScreen = isFullScreen;
	this->_startScene = startScene;
}


void Application::setFps(const int fps)
{
	setAnimationInterval(1.0f / fps);
}

void Application::setAnimationInterval(float interval)
{
	QueryPerformanceFrequency(&_freq);
	_animationInterval.QuadPart = LONGLONG(interval * _freq.QuadPart);
}

float Application::getAnimationInterval() const
{
	return (float(_animationInterval.QuadPart))/ (_freq.QuadPart);
}

Application::~Application ( )
{
	GameManager::getInstance()->release();
	Graphics::getInstance()->release();
	Input::getInstance()->release();
	Camera::getInstance()->release();
}

void Application::processMessage()
{
	//read messages from Message queue
	if(PeekMessage(&_msg,0,0,0,PM_REMOVE))
	{
		if(_msg.message == WM_QUIT)
		{
			//exit
			_exiting = true;
			return;
		}
		if(_msg.message == WM_ACTIVATE)
		{
			//backgroundtoForeground();
			_msg.message = 0;
		}

		//process message:
		TranslateMessage(&_msg);
		DispatchMessage(&_msg);
	}
}

void Application::run ()
{
	setFps(60);

	initWindow();

	initComponents();

	gameLoop();
}

Application::Application ( )
{

}

void Application::initWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = _hInstance;
	wc.lpfnWndProc = (WNDPROC)winProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = nullptr;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = _windowClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);
	DWORD style;

	if (this->_isFullScreen)
	{
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	}

	else
	{
		style = WS_OVERLAPPEDWINDOW;
	}

	_hWnd = CreateWindow(
		_windowClassName,
		_windowClassName,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		_width,
		_height,
		NULL,
		NULL,
		this->_hInstance,
		NULL);

	if (_hWnd == NULL)
	{
		throw exception("Cannot create Window");
	}

	ShowWindow(this->_hWnd, SW_SHOWNORMAL);
	UpdateWindow(this->_hWnd);
}

void Application::gameLoop()
{
	//initial timestamp
	QueryPerformanceCounter(&_startTimestamp);
	_lastTimestamp = _startTimestamp;
	_currentTimestamp = _lastTimestamp;

	LONGLONG interval = 0LL; // Count ticks between two frames
	LONGLONG waitMS = 0L; // Time waiting

	//main loop
	while(!_exiting)
	{
		QueryPerformanceCounter(&_currentTimestamp);
		interval = (_currentTimestamp.QuadPart - _lastTimestamp.QuadPart);
		if(interval >= _animationInterval.QuadPart)
		{
			_lastTimestamp.QuadPart = _currentTimestamp.QuadPart;
			_deltaTime = (float(interval)) / _freq.QuadPart;
			_frameCount++;
			GameManager::getInstance()->setDeltaTime(_deltaTime);
			processMessage(); //update what message in win32
			processGame();  //update Game
		}
		else
		{
			waitMS = (_animationInterval.QuadPart - interval) * 1000L / _freq.QuadPart - 1L;
			if(waitMS > 1L)
			{
				Sleep(static_cast<DWORD>(waitMS));
			}
		}
		
	}
}

void Application::initComponents()
{
	// Graphics
	Graphics* graphics = Graphics::getInstance();
	graphics->_hInstance = _hInstance;
	graphics->_hWnd = _hWnd;
	graphics->_screenWidth = _width;
	graphics->_screenHeight = _height;
	graphics->init();

	// Audio


	// Input
	Input *input = Input::getInstance();
	input->_hInstance = _hInstance;
	input->_hWnd = _hWnd;
	input->initialize();

	// GameManager
	GameManager *gameManager = GameManager::getInstance();
	gameManager->setScreenWidth(_width);
	gameManager->setScreenHeight(_height);
	gameManager->init(_startScene);

	// Camera
	/*Camera *camera = Camera::getInstance();
	if(camera)
	{
		camera->setTransform(graphics);
	}*/
}

void Application::processGame()
{
	//update input
	updateInput();

	//update Game
	updateGame();

	//update Physics
	updatePhysicsManager();


	//update Camera
	updateCamera(Camera::getInstance()->nodeIsFollowing());

	//render
	renderGraphics();

}

void Application::updateInput()
{
	Input::getInstance()->update();
}

void Application::updateGame()
{
	GameManager::getInstance()->update();
}

void Application::renderGraphics()
{
	
	Graphics::getInstance()->beginRender();
	//render running scene
	GameManager::getInstance()->render();
	
	Graphics::getInstance()->endRender();
}

void Application::updatePhysicsManager()
{
	PhysicsManager::getIntance()->update();
}

void Application::updateCamera(Node *follow)
{
	Camera* camera = Camera::getInstance();
	if(camera)
	{
		if(!camera->isFollowing())
		{
			camera->follow(follow);
		}
	}

	camera->update();
}

float Application::getDeltaTime() const
{
	return _deltaTime;
}

bool Application::isFullScreen() const
{
	return _isFullScreen;
}

int Application::getWidth() const
{
	return _width;
}

int Application::getHeight() const
{
	return _height;
}

HWND Application::getWindow() const
{
	return _hWnd;
}

HINSTANCE Application::getHInstance() const
{
	return _hInstance;
}

HRESULT Application::winProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

