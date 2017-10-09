#include "Application.h"

US_NS_JK

Application* Application::_instance = NULL;


Application* Application::getInstance ( )
{
  if (_instance == NULL)
  {
    _instance = new Application();
  }

  return _instance;
}

Application::~Application ( )
{
  delete _window;

  _device->release();

  delete _instance;
  _instance = NULL;
}

void Application::run ( HINSTANCE hInstance, LPCSTR applicationName, int screenWidth, int screenHeight, int fps )
{
  _window = new Windows(hInstance, applicationName, screenWidth, screenHeight, false);
  _window->initWindow();

  _device = new Device();
  _device->init(_window);
}

Application::Application ( )
{
}
