#include "Framework/Application.h"
#include "Lv1Scene.h"


int WINAPI WinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR    lpCmdLine,
  int       nCmdShow)
{
  JaKa::Application app = JaKa::Application::Application(hInstance, "Hello Khang", 800, 600, false, new JaKa::Lv1Scene);
  app.run();

}

