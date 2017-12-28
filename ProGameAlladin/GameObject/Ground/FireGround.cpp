#include "FireGround.h"
#include "../Weapons/Fire.h"
#include "../../Framework/Scene.h"
#include "../Aladdin.h"

US_NS_JK

FireGround::FireGround()
{
}

FireGround::FireGround(const Vec2 & position, const Size & size, const GameObjectType tag, Aladdin* target) : GameObject(position, size, tag)
{
	_rigid->setDensity(10000);
	_lastColliPosition = Vec2(0,0);
	_lastFrame = 0;
	_aladdin = target;
}

FireGround::~FireGround()
{
}

void FireGround::release()
{
	delete this;
}

void FireGround::init()
{
	GameObject::init();
}

void FireGround::update()
{
	if (_tag == FIREGROUND)
	{
		const auto collisionWithAladdin = std::find(std::begin(_rigid->getCollidingBodies()), std::end(_rigid->getCollidingBodies()), "aladdin");

		if (collisionWithAladdin != _rigid->getCollidingBodies().end() && _aladdin->getPosition().getY() < _position.getY()-20)
		{
			if (_aladdin->getActionName() == "Idle1" || _aladdin->getActionName() == "Idle2" || _aladdin->getActionName() == "Idle3" ||
				(_aladdin->getActionName() == "Run" && (_aladdin->getIndex() == 4 || _aladdin->getIndex() == 1 || _aladdin->getIndex() == 9 || _aladdin->getIndex() == 7))
				&& (_aladdin->getPosition().getX() + _aladdin->getRect().getWidth() > _position.getX()
					&& _aladdin->getPosition().getX() + _aladdin->getRect().getWidth()< _position.getX() + _rigid->getSize().getWidth()))
			{
				_currentColliPosition = _aladdin->getRigidPosition();
				_currentFrame = _aladdin->getIndex();
				if (abs(_lastColliPosition.getX() - _currentColliPosition.getX()) > 20 && _lastFrame != _currentFrame)
				{
					if (_aladdin->getEScene() == Aladdin::ENUM_BOSS_SCENE)
					{
						const auto flame = new Fire(this, Vec2(_aladdin->getRigidPosition().getX(), _aladdin->getRigidPosition().getY() - 15), Size(30, 56));
						flame->getRigidBody()->setGravityScale(0);

						flame->setCurrentScene(this->getCurrentScene());
						this->getCurrentScene()->addNode(flame);
						_lastColliPosition = _currentColliPosition;
						_lastFrame = _currentFrame;
					}
					else
					{
						const auto flame = new Fire(this, Vec2(_aladdin->getRigidPosition().getX(), _aladdin->getRigidPosition().getY()), Size(30, 56));
						flame->getRigidBody()->setGravityScale(0);

						flame->setCurrentScene(this->getCurrentScene());
						this->getCurrentScene()->addNode(flame);
						_lastColliPosition = _currentColliPosition;
						_lastFrame = _currentFrame;
					}
				}
			}
			else
			{
				_lastColliPosition = Vec2(0, 0);
				_lastFrame = 0;
			}
		}
	}
}

void FireGround::render()
{
	GameObject::render();
}

Aladdin* FireGround::getTarget()
{
	return _aladdin;
}
