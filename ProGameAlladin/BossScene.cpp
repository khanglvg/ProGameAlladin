#include "BossScene.h"
#include "Framework/Camera.h"
#include "GameObject/BackgroundLv1Scene.h"
#include "GameObject/Enemies/Jafar/Jafar.h"
#include "GameObject/Items/Apple/Apple.h"
#include "GameObject/Aladdin.h"
#include "GameObject/Enemies/Jafar/Jafar.h"
#include "GameObject/Ground/FireGround.h"

US_NS_JK

BossScene::BossScene()
{

}

BossScene::~BossScene()
{
}

void BossScene::init()
{
	const auto scale = 0.45;

	// =============================================== ALADDIN ==============================================================================
	_aladdin = new Aladdin(Vec2(400 * scale, 610 * scale), Size(10, 30));
	_aladdin->getRigidBody()->setGravityScale(1);
	_aladdin->setCurrentScene(this);
	_aladdin->setEScene(Aladdin::ENUM_BOSS_SCENE);
	_vectNode.push_back(_aladdin);
	// ======================================================================================================================================



	// =============================================== BACKGROUND ===========================================================================
	_bgCenter = new BackgroundLv1Scene("Resources/Boss/pillars.png", 0);
	_bgRight = new BackgroundLv1Scene("Resources/Boss/pillars.png", 0);
	_bgLeft = new BackgroundLv1Scene("Resources/Boss/pillars.png", 0);
	_map = new BackgroundLv1Scene("Resources/Boss/palace_back.png", 1);
	
	_bgCenter->setPosition(Vec2(0, 100));
	_bgRight->setPosition(Vec2(340, 100));
	_bgLeft->setPosition(Vec2(-340, 100));

	_bgCenter->setScale(Vec2(scale, scale));
	_bgRight->setScale(Vec2(scale, scale));
	_bgLeft->setScale(Vec2(scale, scale));
	_map->setScale(Vec2(scale, scale));

	_vectNode.push_back(_bgLeft);
	_vectNode.push_back(_bgCenter);
	_vectNode.push_back(_bgRight);
	
	_vectNode.push_back(_map);
	// ======================================================================================================================================



	// =============================================== GROUND & WALL =========================================================================
	auto ground = new GameObject(Vec2(750 * scale, (816 - 63 - 15) * scale), Size(1500* scale, 126* scale), GameObject::GROUND);
	ground->setRigidTag("ground");
	_vectNode.push_back(ground);

	auto wallLeft = new GameObject(Vec2((50) * scale, (408) * scale), Size(100 * scale, 815 * scale), GameObject::WALL);
	wallLeft->setRigidTag("wall");
	_vectNode.push_back(wallLeft);

	auto wallRight = new GameObject(Vec2((1500 - 64) * scale, (408) * scale), Size(100 * scale, 815 * scale), GameObject::WALL);
	wallRight->setRigidTag("wall");
	_vectNode.push_back(wallRight);
	// ========================================================================================================================================



	// ================================================ PLATFORM ==============================================================================
	const float platformSizeX = 176;
	const float platformSizeY = 50;
	const float platformPositionY = 573;

	_platform1 = new FireGround(Vec2((174) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM, _aladdin);
	_platform1->setRigidTag("platform");
	_platform1->getRigidBody()->setActive(false);
	_platform1->setCurrentScene(this);
	_vectNode.push_back(_platform1);

	_platform2 = new FireGround(Vec2((563) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM, _aladdin);
	_platform2->setRigidTag("platform");
	_platform2->getRigidBody()->setActive(false);
	_platform2->setCurrentScene(this);
	_vectNode.push_back(_platform2);

	_platform3 = new FireGround(Vec2((944) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM, _aladdin);
	_platform3->setRigidTag("platform");
	_platform3->getRigidBody()->setActive(false);
	_platform3->setCurrentScene(this);
	_vectNode.push_back(_platform3);

	_platform4 = new FireGround(Vec2((1327) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM, _aladdin);
	_platform4->setRigidTag("platform");
	_platform4->getRigidBody()->setActive(false);
	_platform4->setCurrentScene(this);
	_vectNode.push_back(_platform4);
	// =============================================================================================================================================



	// =============================================== BOSS ========================================================================================
	_jafar = new Jafar(Vec2(770 * scale, 550 * scale), Size(10, 60), GameObject::GameObjectType::ENEMIES, _aladdin);
	_jafar->setCurrentScene(this);
	_vectNode.push_back(_jafar);
	// =============================================================================================================================================



	// =============================================== APPLES ======================================================================================
	const auto apple1_X = 500;
	const auto apple1_Y = 490;
	const auto distanceFrom1to5 = 450;

	// Apple 1
	auto apple1 = new Apple(Vec2(apple1_X * scale, apple1_Y * scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple1->setRigidTag("apple");
	apple1->setScale(Vec2(0.9,0.9));
	apple1->setCurrentScene(this);
	apple1->getRigidBody()->setActive(false);
	apple1->setOnCollision(true);
	_listAppleLeft.push_back(apple1);
	
	// Apple 2
	auto apple2 = new Apple(Vec2((apple1_X + 25) * scale, (apple1_Y - 25) * scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple2->setRigidTag("apple");
	apple2->setScale(Vec2(0.9, 0.9));
	apple2->setCurrentScene(this);
	apple2->getRigidBody()->setActive(false);
	apple2->setOnCollision(true);
	_listAppleLeft.push_back(apple2);
	
	// Apple 3
	auto apple3 = new Apple(Vec2((apple1_X + 50) * scale, (apple1_Y)* scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple3->setRigidTag("apple");
	apple3->setScale(Vec2(0.9, 0.9));
	apple3->setCurrentScene(this);
	apple3->getRigidBody()->setActive(false);
	apple3->setOnCollision(true);
	_listAppleLeft.push_back(apple3);
	
	// Apple 4
	auto apple4 = new Apple(Vec2((apple1_X + 25) * scale, (apple1_Y + 25) * scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple4->setRigidTag("apple");
	apple4->setScale(Vec2(0.9, 0.9));
	apple4->setCurrentScene(this);
	apple4->getRigidBody()->setActive(false);
	apple4->setOnCollision(true);
	_listAppleLeft.push_back(apple4);

	// Apple 5
	auto apple5 = new Apple(Vec2((apple1_X + distanceFrom1to5) * scale, (apple1_Y)* scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple5->setRigidTag("apple");
	apple5->setScale(Vec2(0.9, 0.9));
	apple5->setCurrentScene(this);
	apple5->getRigidBody()->setActive(false);
	apple5->setOnCollision(true);
	_listAppleRight.push_back(apple5);
	
	// Apple 6
	auto apple6 = new Apple(Vec2((apple1_X + distanceFrom1to5 + 25) * scale, (apple1_Y - 25) * scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple6->setRigidTag("apple");
	apple6->setScale(Vec2(0.9, 0.9));
	apple6->setCurrentScene(this);
	apple6->getRigidBody()->setActive(false);
	apple6->setOnCollision(true);
	_listAppleRight.push_back(apple6);
	
	// Apple 7
	auto apple7 = new Apple(Vec2((apple1_X + distanceFrom1to5 + 50) * scale, (apple1_Y)* scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple7->setRigidTag("apple");
	apple7->setScale(Vec2(0.9, 0.9));
	apple7->setCurrentScene(this);
	apple7->getRigidBody()->setActive(false);
	apple7->setOnCollision(true);
	_listAppleRight.push_back(apple7);
	
	// Apple 8
	auto apple8 = new Apple(Vec2((apple1_X + distanceFrom1to5 + 25) * scale, (apple1_Y + 25) * scale), Size(5, 5), GameObject::APPLES, _aladdin);
	apple8->setRigidTag("apple");
	apple8->setScale(Vec2(0.9, 0.9));
	apple8->setCurrentScene(this);
	apple8->getRigidBody()->setActive(false);
	apple8->setOnCollision(true);
	_listAppleRight.push_back(apple8);

	// =============================================================================================================================================


	Camera::getInstance()->follow(_aladdin);
	Camera::getInstance()->setScaleFactor(Vec2(2, 2));
	_vectNode.push_back(Camera::getInstance());

	for (size_t i = 0; i < _listAppleLeft.size(); i++)
	{
		_listAppleLeft[i]->init();
	}
	for (size_t i = 0; i < _listAppleRight.size(); i++)
	{
		_listAppleRight[i]->init();
	}

	Scene::init();
}

void BossScene::release()
{
	for (size_t i = 0; i < _listAppleLeft.size(); i++)
	{
		if (_listAppleLeft[i])
			delete _listAppleLeft[i];
	}
	_listAppleLeft.clear();

	for (size_t i = 0; i < _listAppleRight.size(); i++)
	{
		if (_listAppleRight[i])
			delete _listAppleRight[i];
	}
	_listAppleRight.clear();
	Scene::release();
}

void BossScene::update()
{
	if(_aladdin->getRigidBody()->getPosition().getY() < _platform1->getRigidBody()->getPosition().getY() - _platform1->getRigidBody()->getSize().getHeight())
	{
		_platform1->getRigidBody()->setActive(true);
		_platform2->getRigidBody()->setActive(true);
		_platform3->getRigidBody()->setActive(true);
		_platform4->getRigidBody()->setActive(true);
	}
	else
	{
		_platform1->getRigidBody()->setActive(false);
		_platform2->getRigidBody()->setActive(false);
		_platform3->getRigidBody()->setActive(false);
		_platform4->getRigidBody()->setActive(false);
	}

	if (_jafar->isTransform())
	{
		_platform1->setTag(GameObject::FIREGROUND);
		_platform2->setTag(GameObject::FIREGROUND);
		_platform3->setTag(GameObject::FIREGROUND);
		_platform4->setTag(GameObject::FIREGROUND);
	}

	if (_aladdin->getNumApple() == 0)
	{
		if (getNumApple() == 0)
		{
			auto _distance = abs(_aladdin->getPosition().getX() - 770 * 0.45);
			if (getAladdinPosition() == -1 && _distance > 80)
			{
				for (auto apple : _listAppleRight)
				{
					apple->getRigidBody()->setActive(true);
					apple->setOnCollision(false);
				}
			}
			else if (getAladdinPosition() == 1 && _distance > 80)
			{
				for (auto apple : _listAppleLeft)
				{
					apple->getRigidBody()->setActive(true);
					apple->setOnCollision(false);
				}
			}
		}
	}

	for (size_t i = 0; i < _listAppleLeft.size(); i++)
		_listAppleLeft[i]->update();
	for (size_t i = 0; i < _listAppleRight.size(); i++)
		_listAppleRight[i]->update();
	Scene::update();
}

void BossScene::render()
{
	for (size_t i = 0; i < _listAppleLeft.size(); i++)
	{
		_listAppleLeft[i]->render();
	}
	for (size_t i = 0; i < _listAppleRight.size(); i++)
	{
		_listAppleRight[i]->render();
	}
	Scene::render();
}

int BossScene::getAladdinPosition()
{
	if (_aladdin->getPosition().getX() > 770 * 0.45)
	{
		return 1;
	}
	return -1;
}

int BossScene::getNumApple() const
{
	int _numApple = 0;
	for (size_t i = 0; i < _listAppleLeft.size(); i++)
	{
		if (_listAppleLeft[i]->getRigidBody()->isActived())
		{
			_numApple++;
		}
	}
	for (size_t i = 0; i < _listAppleRight.size(); i++)
	{
		if (_listAppleRight[i]->getRigidBody()->isActived())
		{
			_numApple++;
		}
	}
	return _numApple;
}

 