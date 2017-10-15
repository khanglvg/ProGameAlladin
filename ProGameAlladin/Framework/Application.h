#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "definitions.h"
#include "Windows.h"
#include "Graphics.h"

NS_JK_BEGIN
class Application
{
public:
  static Application* getInstance();

  void run(HINSTANCE hInstance, LPCSTR applicationName, int screenWidth, int screenHeight, int fps);

  ~Application();
private:
  static Application* _instance;
  Application();

  Windows* _window;
  Graphics* _device;
};
NS_JK_END
#endif __APPLICATION_H__