#include "KnifeMenuSelector.h"
#include "../Framework/Graphics.h"
#include "../Framework/Input.h"
#include "../Framework/GameManager.h"
#include "../MenuSelectorScene.h"
US_NS_JK

KnifeMenuSelector::KnifeMenuSelector()
{
}

KnifeMenuSelector::KnifeMenuSelector(const string& srcFile, const int& layer)
{
	_srcFile = srcFile;
	_layer = layer;

	_minX = 90;
	_maxX = 120;

	_firstPosition = Vec2(_minX, JK_DRAW_Y_1 + 10);
	_secondPostion = Vec2(_minX, JK_DRAW_Y_2 + 10);
	_thirdPostion = Vec2(_minX, JK_DRAW_Y_3 + 10);

	_position = _firstPosition;
	_scale = Vec2(3, 2);
	_state = PRESS_START;

	_velocity.setX(2);

	_leftToRight = false;
}

KnifeMenuSelector::~KnifeMenuSelector()
{
}

void KnifeMenuSelector::init()
{
	_textureKnife.setSrcFile(_srcFile);
	_textureKnife.setName("KnifeMenuSelector");
	Graphics::getInstance()->loadTexture(_textureKnife);
}

void KnifeMenuSelector::update()
{
	if (Input::getInstance()->isKeyDown(KEY_UP_ARROW))
	{
		if(_state == PRESS_START)
		{
			_position = _secondPostion;
			_state = OPTIONS;
		}
		else if (_state == OPTIONS)
		{
			_position = _firstPosition;
			_state = PRESS_START;
		}
	}
	else if (Input::getInstance()->isKeyDown(KEY_DOWN_ARROW))
	{
		if (_state == PRESS_START)
		{
			_position = _secondPostion;
			_state = OPTIONS;
		}
		else if (_state == OPTIONS)
		{
			_position = _firstPosition;
			_state = PRESS_START;
		}
	}


	if (Input::getInstance()->isKeyDown(KEY_UP_ARROW))
	{
		if (_state == SOUND)
		{
			_position = _secondPostion;
			_state = EXIT_OPTIONS;
		}
		else if (_state == EXIT_OPTIONS)
		{
			_position = _firstPosition;
			_state = SOUND;
		}
	}
	else if (Input::getInstance()->isKeyDown(KEY_DOWN_ARROW))
	{
		if (_state == SOUND)
		{
			_position = _secondPostion;
			_state = EXIT_OPTIONS;
		}
		else if (_state == EXIT_OPTIONS)
		{
			_position = _firstPosition;
			_state = SOUND;
		}
	}

	if (Input::getInstance()->isKeyDown(KEY_UP_ARROW))
	{
		if (_state == MARKET)
		{
			_position = _thirdPostion;
			_state = EXIT_CHOOSE_SCENE;
		}
		else if (_state == JAFAR)
		{
			_position = _firstPosition;
			_state = MARKET;
		}
		else if (_state == EXIT_CHOOSE_SCENE)
		{
			_position = _secondPostion;
			_state = JAFAR;
		}
	}
	else if (Input::getInstance()->isKeyDown(KEY_DOWN_ARROW))
	{
		if (_state == MARKET)
		{
			_position = _secondPostion;
			_state = JAFAR;
		}
		else if (_state == JAFAR)
		{
			_position = _thirdPostion;
			_state = EXIT_CHOOSE_SCENE;
		}
		else if (_state == EXIT_CHOOSE_SCENE)
		{
			_position = _firstPosition;
			_state = MARKET;
		}
	}

	/*
	*	Make knife moving
	*/
	if (_position.getX() <= _minX)
	{
		_position.setX(_position.getX() + _velocity.getX());
		_leftToRight = true;
	}

	if (_position.getX() >= _maxX)
	{
		_position.setX(_position.getX() - _velocity.getX());
		_leftToRight = false;
	}

	if (_position.getX() > _minX && _position.getX() < _maxX)
	{
		if(_leftToRight == true)
		{
			_position.setX(_position.getX() + _velocity.getX());
		}
		else
		{
			_position.setX(_position.getX() - _velocity.getX());
		}
	}

}

void KnifeMenuSelector::render()
{
	Graphics::getInstance()->drawSprite(_textureKnife,
		Vec2(0, 0),
		getTransformMatrix(),
		Color(255, 255, 255, 255),
		Rect(0, 0, 32, 11),
		_layer);
}

string KnifeMenuSelector::getSrcFile() const
{
	return _srcFile;
}

void KnifeMenuSelector::setSrcFile(const string& srcFile)
{
	_srcFile = srcFile;
}

int KnifeMenuSelector::getLayer() const
{
	return _layer;
}

void KnifeMenuSelector::setLayer(const int& layer)
{
	_layer = layer;
}

int KnifeMenuSelector::getState() const
{
	return _state;
}

void KnifeMenuSelector::setState(const int& state)
{
	_state = state;
}

Vec2 KnifeMenuSelector::getPressStartPosition() const
{
	return _firstPosition;
}

Vec2 KnifeMenuSelector::getOptionsPosition() const
{
	return _secondPostion;
}
