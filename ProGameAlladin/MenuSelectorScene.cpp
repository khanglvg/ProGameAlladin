#include "MenuSelectorScene.h"
#include "GameObject/BackgroundMenu.h"
#include "Framework/Text.h"
#include "GameObject/TitleMenuScene.h"
#include "GameObject/KnifeMenuSelector.h"
#include "Framework/Input.h"
#include "Framework/GameManager.h"
#include "Lv1Scene.h"
#include "Framework/Camera.h"
#include "BossScene.h"
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
	_vectNode.push_back(new TitleMenuScene("Resources/Menu/title.png", Rect(0, 0, 243, 90), 1));
	_vectNode.push_back(_knife);

	_stateSound = true;
	_distance = 30;
	_errorY = 30;

	const auto scaleLetter = 1.7;
				
	// ================================= PRESS START ============================================================
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::P, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::R, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::E, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::S, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::S, 2));

	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::S, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::T, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::A, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::R, 2));
	_pressStart.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::T, 2));

	auto i = 0;
	for (auto letter : _pressStart)
	{
		letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_1 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(true);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================


	// ================================== OPTIONS ================================================================
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::O, 2));
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::P, 2));
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::T, 2));
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::I, 2));
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::O, 2));
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::N, 2));
	_options.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::S, 2));

	for (auto letter : _options)
	{
		letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_2 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(true);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== MARKET =================================================================
	_market.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::M, 2));
	_market.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::A, 2));
	_market.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::R, 2));
	_market.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::K, 2));
	_market.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::E, 2));
	_market.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::T, 2));

	for (auto letter : _market)
	{
		letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_1 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(false);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== JAFAR ==================================================================
	_jafar.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::J, 2));
	_jafar.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::A, 2));
	_jafar.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::F, 2));
	_jafar.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::A, 2));
	_jafar.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::R, 2));

	for (auto letter : _jafar)
	{
		letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_2 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(false);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== EXIT ===================================================================
	_exit.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::E, 2));
	_exit.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::X, 2));
	_exit.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::I, 2));
	_exit.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::T, 2));

	for (auto letter : _exit)
	{
		letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_2 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(false);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== SOUND ==================================================================
	_sound.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::S, 2));
	_sound.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::O, 2));
	_sound.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::U, 2));
	_sound.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::N, 2));
	_sound.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::D, 2));

	for (auto letter : _sound)
	{
		letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_1 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(false);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== ON =====================================================================
	_soundOn.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::O, 2));
	_soundOn.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::N, 2));

	for (auto letter : _soundOn)
	{
		letter->setPosition(Vec2(JK_DRAW_X_2 + i, JK_DRAW_Y_1 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(false);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== OFF =====================================================================
	_soundOff.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::O, 2));
	_soundOff.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::F, 2));
	_soundOff.push_back(new SpriteText("Resources/Menu/text.png", SpriteText::F, 2));

	for (auto letter : _soundOff)
	{
		letter->setPosition(Vec2(JK_DRAW_X_2 + i, JK_DRAW_Y_1 + _errorY));
		letter->setScale(Vec2(scaleLetter, scaleLetter));
		letter->setVisible(false);
		_vectNode.push_back(letter);
		i += _distance;
	}
	i = 0;
	// ===========================================================================================================



	// ================================== RECOMMEND 1 ============================================================
	_textRecommend1 = new Text("Arial", "(C) 1993 SEGA. (C) 1993 VIRGIN GAMES", 30, 450, 14, JK_FONT_HEIGHT, FW_EXTRALIGHT, Color(255, 255, 255, 255));
	_vectNode.push_back(_textRecommend1);
	// ===========================================================================================================



	// ================================== RECOMMEND 2 ============================================================
	_textRecommend2 = new Text("Arial", "(C) 1993 THE WALT DISNEY COMPANY", 30, 490, 14, JK_FONT_HEIGHT, FW_BOLD, Color(255, 255, 255, 255));
	_vectNode.push_back(_textRecommend2);
	// ===========================================================================================================

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
			for (auto letter : _pressStart)		letter->setVisible(false);
			for (auto letter : _options)		letter->setVisible(false);
			for (auto letter : _market)		letter->setVisible(true);
			for (auto letter : _jafar)		letter->setVisible(true);
			for (auto letter : _exit)		letter->setVisible(true);		


			_knife->setState(MARKET);
			_knife->setPosition(_knife->getPressStartPosition());

			auto i = 0;
			for (auto letter : _exit)
			{
				letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_3 + _errorY));
				i += _distance;
			}
			i = 0;
		}
	}
	else if (_knife->getState() == OPTIONS)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			for (auto letter : _pressStart)		letter->setVisible(false);
			for (auto letter : _options)		letter->setVisible(false);
			for (auto letter : _sound)		letter->setVisible(true);
			for (auto letter : _exit)		letter->setVisible(true);
			for (auto letter : _soundOn)	letter->setVisible(true);

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
				for (auto letter : _soundOn)		letter->setVisible(false);
				for (auto letter : _soundOff)		letter->setVisible(true);
				_stateSound = false;
			}
			else
			{
				for (auto letter : _soundOn)		letter->setVisible(true);
				for (auto letter : _soundOff)		letter->setVisible(false);
				_stateSound = true;
			}
		}
	}
	else if (_knife->getState() == EXIT_OPTIONS || _knife->getState() == EXIT_CHOOSE_SCENE)
	{
		if (Input::getInstance()->isKeyDown(KEY_RETURN))
		{
			for (auto letter : _pressStart)		letter->setVisible(true);
			for (auto letter : _options)		letter->setVisible(true);
			for (auto letter : _market)		letter->setVisible(false);
			for (auto letter : _jafar)		letter->setVisible(false);
			for (auto letter : _exit)		letter->setVisible(false);
			for (auto letter : _sound)		letter->setVisible(false);
			for (auto letter : _soundOn)	letter->setVisible(false);
			for (auto letter : _soundOff)	letter->setVisible(false);

			_knife->setState(PRESS_START);
			_knife->setPosition(_knife->getPressStartPosition());

			auto i = 0;
			for (auto letter : _exit)
			{
				letter->setPosition(Vec2(JK_DRAW_X_1 + i, JK_DRAW_Y_2 + _errorY));
				i += _distance;
			}
			i = 0;
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
			// Go to Boss
			GameManager::getInstance()->changeScene(new BossScene);
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
