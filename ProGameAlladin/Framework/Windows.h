#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include "definitions.h"

NS_JK_BEGIN
class Windows 
{
public:
  Windows(HINSTANCE hInstance, LPCSTR className, int width, int height, int isFullScreen);
  void initWindow();

  bool isFullScreen() const;
  int getWidth() const;
  int getHeight() const;
  HWND getWindow() const;
  HINSTANCE getInstance() const;

private:
  HINSTANCE _hInstance;
  HWND _hWnd;

  LPCSTR _windowClassName;
  bool _isFullScreen;

  int _width;
  int _height;

  static HRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
};
NS_JK_END

#endif __WINDOWS_H__
