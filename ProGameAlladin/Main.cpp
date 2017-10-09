#include "Framework/Application.h"


int WINAPI WinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR    lpCmdLine,
  int       nCmdShow)
{
  JaKa::Application* app = JaKa::Application::getInstance();
  app->run(hInstance,"Hello Khang", 800, 600, 60);
}

