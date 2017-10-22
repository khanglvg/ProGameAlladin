#include "Windows.h"

US_NS_JK



Windows::Windows(HINSTANCE hInstance, LPCSTR className, int width, int height, int isFullScreen)
{
  _hInstance = hInstance;
  _windowClassName = className;
  _width = width;
  _height = height;
  _isFullScreen = isFullScreen;
}

void Windows::initWindow()
{
  WNDCLASSEX wc;
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.hInstance = _hInstance;
  wc.lpfnWndProc = (WNDPROC)WinProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hIcon = NULL;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
  wc.lpszMenuName = NULL;
  wc.lpszClassName = _windowClassName;
  wc.hIconSm = NULL;

  RegisterClassEx(&wc);
  DWORD style;

  if(this->_isFullScreen)
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

bool Windows::isFullScreen() const
{
  return _isFullScreen;
}

int Windows::getWidth ( ) const
{
  return _width;
}

int Windows::getHeight ( ) const
{
  return _height;
}

HWND Windows::getWindow ( ) const
{
  return _hWnd;
}

HINSTANCE Windows::getInstance ( ) const
{
  return _hInstance;
}

HRESULT Windows::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
