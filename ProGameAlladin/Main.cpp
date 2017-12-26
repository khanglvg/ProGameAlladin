#include "Framework/Application.h"
#include "Lv1Scene.h"
#include "MenuSelectorScene.h"
#include "BossScene.h"
#include "CompleteScene.h"

US_NS_JK

int WINAPI WinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR    lpCmdLine,
  int       nCmdShow)
{
  Application app = Application::Application(hInstance, "Aladdin", SCREEN_WIDTH, SCREEN_HEIGHT, false, new Lv1Scene);
  app.run();

}

