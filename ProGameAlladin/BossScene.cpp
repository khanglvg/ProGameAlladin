#include "BossScene.h"
#include "GameObject/Aladdin.h"
#include "Framework/Camera.h"
#include "GameObject/BackgroundLv1Scene.h"
#include "GameObject/Enemies/Jafar/Jafar.h"
#include "GameObject/Items/Apple/Apple.h"
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
	_aladdin = new Aladdin(Vec2(300 * scale, 610 * scale), Size(10, 30));
	_aladdin->getRigidBody()->setGravityScale(1);
	_vectNode.push_back(_aladdin);
	_aladdin->setCurrentScene(this);
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
	const float platformSizeY = 15;
	const float platformPositionY = 552;

	auto platform1 = new GameObject(Vec2((174) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM);
	platform1->setRigidTag("platform");
	_vectNode.push_back(platform1);

	auto platform2 = new GameObject(Vec2((563) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM);
	platform2->setRigidTag("platform");
	_vectNode.push_back(platform2);

	auto platform3 = new GameObject(Vec2((944) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM);
	platform3->setRigidTag("platform");
	_vectNode.push_back(platform3);

	auto platform4 = new GameObject(Vec2((1327) * scale, (platformPositionY) * scale), Size(platformSizeX * scale, platformSizeY * scale), GameObject::PLATFORM);
	platform4->setRigidTag("platform");
	_vectNode.push_back(platform4);
	// =============================================================================================================================================



	// =============================================== BOSS ========================================================================================
	_vectNode.push_back(new Jafar(Vec2(770 * scale, 550 * scale), Size(10, 60), GameObject::GameObjectType::ENEMIES, _aladdin));
	// =============================================================================================================================================



	// =============================================== APPLES ======================================================================================
	const auto apple1_X = 500;
	const auto apple1_Y = 490;
	const auto distanceFrom1to5 = 450;

	// Apple 1
	auto apple1 = new Apple(Vec2(apple1_X * scale, apple1_Y * scale), Size(5, 5), GameObject::APPLES);
	apple1->setCurrentScene(this);
	_vectNode.push_back(apple1);
	
	// Apple 2
	auto apple2 = new Apple(Vec2((apple1_X + 25) * scale, (apple1_Y - 25) * scale), Size(5, 5), GameObject::APPLES);
	apple2->setCurrentScene(this);
	_vectNode.push_back(apple2);
	
	// Apple 3
	auto apple3 = new Apple(Vec2((apple1_X + 50) * scale, (apple1_Y)* scale), Size(5, 5), GameObject::APPLES);
	apple3->setCurrentScene(this);
	_vectNode.push_back(apple3);
	
	// Apple 4
	auto apple4 = new Apple(Vec2((apple1_X + 25) * scale, (apple1_Y + 25) * scale), Size(5, 5), GameObject::APPLES);
	apple4->setCurrentScene(this);
	_vectNode.push_back(apple4);

	// Apple 5
	auto apple5 = new Apple(Vec2((apple1_X + distanceFrom1to5) * scale, (apple1_Y)* scale), Size(5, 5), GameObject::APPLES);
	apple5->setCurrentScene(this);
	_vectNode.push_back(apple5);
	
	// Apple 6
	auto apple6 = new Apple(Vec2((apple1_X + distanceFrom1to5 + 25) * scale, (apple1_Y - 25) * scale), Size(5, 5), GameObject::APPLES);
	apple6->setCurrentScene(this);
	_vectNode.push_back(apple6);
	
	// Apple 7
	auto apple7 = new Apple(Vec2((apple1_X + distanceFrom1to5 + 50) * scale, (apple1_Y)* scale), Size(5, 5), GameObject::APPLES);
	apple7->setCurrentScene(this);
	_vectNode.push_back(apple7);
	
	// Apple 8
	auto apple8 = new Apple(Vec2((apple1_X + distanceFrom1to5 + 25) * scale, (apple1_Y + 25) * scale), Size(5, 5), GameObject::APPLES);
	apple8->setCurrentScene(this);
	_vectNode.push_back(apple8);
	// =============================================================================================================================================


	Camera::getInstance()->follow(_aladdin);
	Camera::getInstance()->setScaleFactor(Vec2(2, 2));
	_vectNode.push_back(Camera::getInstance());

	Scene::init();
}

void BossScene::release()
{
	Scene::release();
}

void BossScene::update()
{
	Scene::update();
}

void BossScene::render()
{
	Scene::render();
}
 