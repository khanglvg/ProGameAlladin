#include "MenuSelectorScene.h"
#include "GameObject/BackgroundMenu.h"
#include "Framework/Text.h"
#include "GameObject/TitleMenuScene.h"
#include "GameObject/KnifeMenuSelector.h"
#include "Framework/Input.h"
#include "Framework/GameManager.h"
#include "Lv1Scene.h"
#include "Framework/Camera.h"
US_NS_JK


MenuSelector::MenuSelector()
{
	
}

MenuSelector::~MenuSelector()
{
}

void MenuSelector::init()
{
	_knife = new KnifeMenuSelector("Resources/Menu/menuknife.png", 2);
	_vectNode.push_back(new BackgroundMenu("Resources/Menu/backgroundMenu.png", 0));
	_vectNode.push_back(new TitleMenuScene("Resources/Menu/title.png", 1));
	_vectNode.push_back(_knife);

	_textPressStart		=	new Text("Arial", "Press Start",	JK_DRAW_X_1, JK_DRAW_Y_1, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 255));
	_textMarket			=	new Text("Arial", "Market",			JK_DRAW_X_1, JK_DRAW_Y_1, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 0));
	_textJafar			=	new Text("Arial", "Jafar Boss",		JK_DRAW_X_1, JK_DRAW_Y_2, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 0));
	
	_textOptions		=	new Text("Arial", "Options",		JK_DRAW_X_1, JK_DRAW_Y_2, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 255));
	_textSound			=	new Text("Arial", "Sound",			JK_DRAW_X_1, JK_DRAW_Y_1, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 0));
	_textExit			=	new Text("Arial", "Exit",			JK_DRAW_X_1, JK_DRAW_Y_2, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 0));

	_textStateSound		=	new Text("Arial", "ON",				JK_DRAW_X_2, JK_DRAW_Y_1, JK_FONT_WIDTH, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 0));
	
	_textRecommend1 =	new Text("Arial", "(C) 1993 SEGA. (C) 1993 VIRGIN GAMES", 30, 450, 14, JK_FONT_HEIGHT, FW_EXTRALIGHT, Color(255, 255, 255, 255));
	_textRecommend2 =	new Text("Arial", "(C) 1993 THE WALT DISNEY COMPANY", 30, 490, 14, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 255));

	_vectNode.push_back(_textPressStart);
	_vectNode.push_back(_textMarket);
	_vectNode.push_back(_textJafar);

	_vectNode.push_back(_textOptions);
	_vectNode.push_back(_textSound);
	_vectNode.push_back(_textExit);
	_vectNode.push_back(_textStateSound);

	_stateSound = true;
				
	_vectNode.push_back(_textRecommend1);
	_vectNode.push_back(_textRecommend2);


	Camera::getInstance()->setScaleFactor(Vec2(0.8, 0.8));
	_vectNode.push_back(Camera::getInstance());
	Scene::init();

}

void MenuSelector::update()
{
	Scene::update();
	if (_knife->getState() == PRESS_START)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			_textPressStart->setColor(Color(255, 255, 255, 0));
			_textOptions->setColor(Color(255, 255, 255, 0));
			_textMarket->setColor(Color(255, 255, 255, 255));
			_textJafar->setColor(Color(255, 255, 255, 255));
			_textExit->setColor(Color(255, 255, 255, 255));

			_knife->setState(MARKET);
			_knife->setPosition(_knife->getPressStartPosition());
			_textExit->setPosition(Vec2(JK_DRAW_X_1, JK_DRAW_Y_3));
		}
	}
	else if (_knife->getState() == OPTIONS)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			_textPressStart->setColor(Color(255, 255, 255, 0));
			_textOptions->setColor(Color(255, 255, 255, 0));
			_textSound->setColor(Color(255, 255, 255, 255));
			_textExit->setColor(Color(255, 255, 255, 255));
			_textStateSound->setColor(Color(255, 255, 255, 255));

			_knife->setState(SOUND);
			_knife->setPosition(_knife->getPressStartPosition());
		}
	}
	else if (_knife->getState() == SOUND)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			if (_stateSound)
			{
				_textStateSound->setText("OFF");
				_stateSound = false;
			}
			else
			{
				_textStateSound->setText("ON");
				_stateSound = true;
			}
		}
	}
	else if (_knife->getState() == EXIT_OPTIONS || _knife->getState() == EXIT_CHOOSE_SCENE)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			_textPressStart->setColor(Color(255, 255, 255, 255));
			_textOptions->setColor(Color(255, 255, 255, 255));
			_textSound->setColor(Color(255, 255, 255, 0));
			_textExit->setColor(Color(255, 255, 255, 0));
			_textStateSound->setColor(Color(255, 255, 255, 0));
			_textMarket->setColor(Color(255, 255, 255, 0));
			_textJafar->setColor(Color(255, 255, 255, 0));

			_knife->setState(PRESS_START);
			_knife->setPosition(_knife->getPressStartPosition());

			_textExit->setPosition(Vec2(JK_DRAW_X_1, JK_DRAW_Y_2));
		}
	}
	else if (_knife->getState() == MARKET)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			// Go to Lv1Scene
			GameManager::getInstance()->changeScene(new Lv1Scene);
		}
	}
	else if (_knife->getState() == JAFAR)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			// Go to Boss;
		}
	}


	
}

void MenuSelector::render()
{
	Scene::render();
}

void MenuSelector::release()
{
	Scene::release();
}

bool MenuSelector::getStateSound() const
{
	return _stateSound;
}
