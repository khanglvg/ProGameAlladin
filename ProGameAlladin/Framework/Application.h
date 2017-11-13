#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "definitions.h"
#include "Windows.h"
#include "Graphics.h"
#include "Input.h"
#include "GameManager.h"

NS_JK_BEGIN
class Application
{
public:
	Application();
	Application(const HINSTANCE& hInstance, const LPCSTR& appName, const int& iWidth, const int& iHeight, const bool& isFullScreen);


	void run();

	void initWindow();
	void gameLoop();
	void initComponents() const;
	void processGame();
	void updateGame();
	void renderGraphics();



	bool isFullScreen() const;
	int getWidth() const;
	int getHeight() const;
	HWND getWindow() const;
	HINSTANCE getHInstance() const;
	static HRESULT CALLBACK winProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void setFps(const int fps);
	void setAnimationInterval(float interval);
	float getAnimationInterval() const;
	~Application();

	void processMessage();
private:
	HINSTANCE _hInstance;
	HWND _hWnd;
	LPCSTR _windowClassName;
	bool _isFullScreen;
	int _width;
	int _height;
	bool _exiting;
	LARGE_INTEGER _animationInterval;
	long _frameCount; // Count frames in debug
	MSG _msg;

	LARGE_INTEGER _freq; // so tick tren 1 giay, tuy thuoc vao tung may
	LARGE_INTEGER _currentTimestamp; // thoi gian vong lap hien tai
	LARGE_INTEGER _lastTimestamp; // thoi gian vong lap trc
	LARGE_INTEGER _startTimestamp; // thoi gian bat dau game

	float _deltaTime; // khoang cach giua vong lap trc va vong lap sau: current - last

};
NS_JK_END
#endif __APPLICATION_H__