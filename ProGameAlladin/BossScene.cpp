#include "BossScene.h"
#include "Framework/Camera.h"
#include "GameObject/BackgroundLv1Scene.h"
#include "GameObject/Enemies/Jafar/Jafar.h"
#include "GameObject/Items/Apple/Apple.h"
#include "GameObject/Aladdin.h"
#include "GameObject/Enemies/Jafar/Jafar.h"
#include "GameObject/Ground/FireGround.h"
#include "Framework/Audio.h"
#include "Framework/GameManager.h"
#include "CompleteScene.h"
#include "Framework/PhysicsManager.h"
#include "GameObject/Items/AladdinHealth.h"

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

#pragma region Sound

	_soundSlash = new Sound("Resources/Audio/High Sword.wav");
	_soundSitSlash = new Sound("Resources/Audio/Low Sword.wav");
	_soundGrounding = new Sound("Resources/Audio/Aladdin Oof.wav");
	_soundPushing = new Sound("Resources/Audio/Aladdin Push.wav");
	_soundThrowing = new Sound("Resources/Audio/Object Throw.wav");
	_soundHurt = new Sound("Resources/Audio/Aladdin Hurt.wav");
	_soundAppleCollect = new Sound("Resources/Audio/Apple Collect.wav");
	_soundAppleCrush = new Sound("Resources/Audio/Apple Splash.wav");


	Audio::get()->load(_soundSlash);
	Audio::get()->load(_soundSitSlash);
	Audio::get()->load(_soundGrounding);
	Audio::get()->load(_soundPushing);
	Audio::get()->load(_soundThrowing);
	Audio::get()->load(_soundHurt);
	Audio::get()->load(_soundAppleCollect);
	Audio::get()->load(_soundAppleCrush);
#pragma  endregion 
	// =============================================== ALADDIN ==============================================================================
	_aladdin = new Aladdin(Vec2(400 * scale, 610 * scale - 100), Size(10, 30));
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

	_alaIcon = new TitleMenuScene("Resources/Items/items.png", Rect(339, 139, 22, 25), 4);
	_alaIcon->setType(TitleMenuScene::ALA);
	_alaIcon->setPosition(Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() + 80));
	_vectNode.push_back(_alaIcon);


	_appleIcon = new TitleMenuScene("Resources/Items/items.png", Rect(340, 17, 12, 12), 4);
	_appleIcon->setType(TitleMenuScene::APPLE);
	_appleIcon->setScale(Vec2(1.4, 1.4));
	_appleIcon->setPosition(Vec2(Camera::getInstance()->getCameraX() + 110, Camera::getInstance()->getCameraY() + 86));
	_vectNode.push_back(_appleIcon);


	_rubyIcon = new TitleMenuScene("Resources/Items/items.png", Rect(339, 110, 18, 17), 4);
	_rubyIcon->setType(TitleMenuScene::RUBY);
	_rubyIcon->setScale(Vec2(1, 1));
	_vectNode.push_back(_rubyIcon);

	_alaHealth = new AladdinHealth(_aladdin);
	_alaHealth->setPosition(Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() - 80));

	_vectNode.push_back(_alaHealth);

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
	_jafar = new Jafar(Vec2(790 * scale, 550 * scale), Size(60, 60), GameObject::GameObjectType::ENEMIES, _aladdin);
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


	// ============================================= SPRITE TEXT ===================================================================================
	_appleUnit = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_appleUnit->setType(SpriteText::SpriteTextType::APPLE_UNIT);
	_appleUnit->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_appleUnit);


	_appleTens = new SpriteText("Resources/Menu/text.png", SpriteText::ONE, 4);
	_appleTens->setType(SpriteText::SpriteTextType::APPLE_TENS);
	_appleTens->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_appleTens);

	_rubyUnit = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_rubyUnit->setType(SpriteText::SpriteTextType::RUBY_UNIT);
	_rubyUnit->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_rubyUnit);


	_rubyTens = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_rubyTens->setType(SpriteText::SpriteTextType::RUBY_TENS);
	_rubyTens->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_rubyTens);

	_alaLifeUnit = new SpriteText("Resources/Menu/text.png", SpriteText::THREE, 4);
	_alaLifeUnit->setType(SpriteText::SpriteTextType::ALA_LIFE);
	_alaLifeUnit->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_alaLifeUnit);

	_score1 = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_score1->setType(SpriteText::SpriteTextType::SCORE_1);
	_score1->setScale(Vec2(1.2, 1.3));
	_vectNode.push_back(_score1);

	_score2 = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_score2->setType(SpriteText::SpriteTextType::SCORE_2);
	_score2->setScale(Vec2(1.2, 1.3));
	_vectNode.push_back(_score2);

	_score3 = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_score3->setType(SpriteText::SpriteTextType::SCORE_3);
	_score3->setScale(Vec2(1.2, 1.3));
	_vectNode.push_back(_score3);

	_score4 = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_score4->setType(SpriteText::SpriteTextType::SCORE_4);
	_score4->setScale(Vec2(1.2, 1.3));
	_vectNode.push_back(_score4);
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


	PhysicsManager::getIntance()->setInBoss(true);
	_isInitialized = true;
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

	PhysicsManager::getIntance()->setInBoss(false);

	Audio::get()->release();
	Scene::release();
	
}

void BossScene::update()
{
	calculationSpriteText();

	if(_aladdin->getRigidBody()->getPosition().getY() < _platform1->getRigidBody()->getPosition().getY() - _platform1->getRigidBody()->getSize().getHeight() - 2)
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

	if (_aladdin->getNumApple() <= 0)
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
	PhysicsManager::getIntance()->setBeginLv1(false);

	if (_jafar->getHealth() == 0)
	{
		GameManager::getInstance()->changeScene(new CompleteScene);
	}
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

void BossScene::calculationSpriteText() const
{
	const auto score = _jafar->getHealth();
	const auto score1 = score / 1000;
	const auto score2 = (score / 100) % 10;
	const auto score3 = (score / 10) % 10;
	const auto score4 = score % 10;

	const auto ruby = _aladdin->getNumRuby();
	const auto rUnit = ruby % 10;
	const auto rTens = ruby / 10;


	const auto apple = _aladdin->getNumApple();
	const auto aUnit = apple % 10;
	const auto aTens = apple / 10;

	switch (aUnit)
	{
	case 0:
	{
		_appleUnit->setValue(SpriteText::ZERO);
		break;
	}
	case 1:
	{
		_appleUnit->setValue(SpriteText::ONE);
		break;
	}
	case 2:
	{
		_appleUnit->setValue(SpriteText::TWO);
		break;
	}
	case 3:
	{
		_appleUnit->setValue(SpriteText::THREE);
		break;
	}
	case 4:
	{
		_appleUnit->setValue(SpriteText::FOUR);
		break;
	}
	case 5:
	{
		_appleUnit->setValue(SpriteText::FIVE);
		break;
	}
	case 6:
	{
		_appleUnit->setValue(SpriteText::SIX);
		break;
	}
	case 7:
	{
		_appleUnit->setValue(SpriteText::SEVEN);
		break;
	}
	case 8:
	{
		_appleUnit->setValue(SpriteText::EIGHT);
		break;
	}
	case 9:
	{
		_appleUnit->setValue(SpriteText::NINE);
		break;
	}

	default:
		break;
	}



	switch (aTens)
	{
	case 0:
	{
		_appleTens->setValue(SpriteText::ZERO);
		_appleTens->setVisible(false);
		break;
	}
	case 1:
	{
		_appleTens->setValue(SpriteText::ONE);
		_appleTens->setVisible(true);
		break;
	}
	case 2:
	{
		_appleTens->setValue(SpriteText::TWO);
		_appleTens->setVisible(true);
		break;
	}
	case 3:
	{
		_appleTens->setValue(SpriteText::THREE);
		_appleTens->setVisible(true);
		break;
	}
	case 4:
	{
		_appleTens->setValue(SpriteText::FOUR);
		_appleTens->setVisible(true);
		break;
	}
	case 5:
	{
		_appleTens->setValue(SpriteText::FIVE);
		_appleTens->setVisible(true);
		break;
	}
	case 6:
	{
		_appleTens->setValue(SpriteText::SIX);
		_appleTens->setVisible(true);
		break;
	}
	case 7:
	{
		_appleTens->setValue(SpriteText::SEVEN);
		_appleTens->setVisible(true);
		break;
	}
	case 8:
	{
		_appleTens->setValue(SpriteText::EIGHT);
		_appleTens->setVisible(true);
		break;
	}
	case 9:
	{
		_appleTens->setValue(SpriteText::NINE);
		_appleTens->setVisible(true);
		break;
	}

	default:
		break;
	}



	switch (rUnit)
	{
	case 0:
	{
		_rubyUnit->setValue(SpriteText::ZERO);
		break;
	}
	case 1:
	{
		_rubyUnit->setValue(SpriteText::ONE);
		break;
	}
	case 2:
	{
		_rubyUnit->setValue(SpriteText::TWO);
		break;
	}
	case 3:
	{
		_rubyUnit->setValue(SpriteText::THREE);
		break;
	}
	case 4:
	{
		_rubyUnit->setValue(SpriteText::FOUR);
		break;
	}
	case 5:
	{
		_rubyUnit->setValue(SpriteText::FIVE);
		break;
	}
	case 6:
	{
		_rubyUnit->setValue(SpriteText::SIX);
		break;
	}
	case 7:
	{
		_rubyUnit->setValue(SpriteText::SEVEN);
		break;
	}
	case 8:
	{
		_rubyUnit->setValue(SpriteText::EIGHT);
		break;
	}
	case 9:
	{
		_rubyUnit->setValue(SpriteText::NINE);
		break;
	}

	default:
		break;
	}



	switch (rTens)
	{
	case 0:
	{
		_rubyTens->setValue(SpriteText::ZERO);
		_rubyTens->setVisible(false);
		break;
	}
	case 1:
	{
		_rubyTens->setValue(SpriteText::ONE);
		_rubyTens->setVisible(true);
		break;
	}
	case 2:
	{
		_rubyTens->setValue(SpriteText::TWO);
		_rubyTens->setVisible(true);
		break;
	}
	case 3:
	{
		_rubyTens->setValue(SpriteText::THREE);
		_rubyTens->setVisible(true);
		break;
	}
	case 4:
	{
		_rubyTens->setValue(SpriteText::FOUR);
		_rubyTens->setVisible(true);
		break;
	}
	case 5:
	{
		_rubyTens->setValue(SpriteText::FIVE);
		_rubyTens->setVisible(true);
		break;
	}
	case 6:
	{
		_rubyTens->setValue(SpriteText::SIX);
		_rubyTens->setVisible(true);
		break;
	}
	case 7:
	{
		_rubyTens->setValue(SpriteText::SEVEN);
		_rubyTens->setVisible(true);
		break;
	}
	case 8:
	{
		_rubyTens->setValue(SpriteText::EIGHT);
		_rubyTens->setVisible(true);
		break;
	}
	case 9:
	{
		_rubyTens->setValue(SpriteText::NINE);
		_rubyTens->setVisible(true);
		break;
	}

	default:
		break;
	}



	switch (_aladdin->getAlaLife())
	{
	case 1:
	{
		_alaLifeUnit->setValue(SpriteText::ONE);
		break;
	}
	case 2:
	{
		_alaLifeUnit->setValue(SpriteText::TWO);
		break;
	}
	case 3:
	{
		_alaLifeUnit->setValue(SpriteText::THREE);
		break;
	}
	case 4:
	{
		_alaLifeUnit->setValue(SpriteText::FOUR);
		break;
	}
	case 5:
	{
		_alaLifeUnit->setValue(SpriteText::FIVE);
		break;
	}
	case 6:
	{
		_alaLifeUnit->setValue(SpriteText::SIX);
		break;
	}
	case 7:
	{
		_alaLifeUnit->setValue(SpriteText::SEVEN);
		break;
	}
	case 8:
	{
		_alaLifeUnit->setValue(SpriteText::EIGHT);
		break;
	}
	case 9:
	{
		_alaLifeUnit->setValue(SpriteText::NINE);
		break;
	}

	default:
		break;
	}


	switch (score1)
	{
	case 0:
	{
		_score1->setValue(SpriteText::ZERO);
		_score1->setVisible(true);
		break;
	}
	case 1:
	{
		_score1->setValue(SpriteText::ONE);
		_score1->setVisible(true);
		break;
	}
	case 2:
	{
		_score1->setValue(SpriteText::TWO);
		_score1->setVisible(true);
		break;
	}
	case 3:
	{
		_score1->setValue(SpriteText::THREE);
		_score1->setVisible(true);
		break;
	}
	case 4:
	{
		_score1->setValue(SpriteText::FOUR);
		_score1->setVisible(true);
		break;
	}
	case 5:
	{
		_score1->setValue(SpriteText::FIVE);
		_score1->setVisible(true);
		break;
	}
	case 6:
	{
		_score1->setValue(SpriteText::SIX);
		_score1->setVisible(true);
		break;
	}
	case 7:
	{
		_score1->setValue(SpriteText::SEVEN);
		_score1->setVisible(true);
		break;
	}
	case 8:
	{
		_score1->setValue(SpriteText::EIGHT);
		_score1->setVisible(true);
		break;
	}
	case 9:
	{
		_score1->setValue(SpriteText::NINE);
		_score1->setVisible(true);
		break;
	}

	default:
		break;
	}


	switch (score2)
	{
	case 0:
	{
		_score2->setValue(SpriteText::ZERO);
		_score2->setVisible(true);
		break;
	}
	case 1:
	{
		_score2->setValue(SpriteText::ONE);
		_score2->setVisible(true);
		break;
	}
	case 2:
	{
		_score2->setValue(SpriteText::TWO);
		_score2->setVisible(true);
		break;
	}
	case 3:
	{
		_score2->setValue(SpriteText::THREE);
		_score2->setVisible(true);
		break;
	}
	case 4:
	{
		_score2->setValue(SpriteText::FOUR);
		_score2->setVisible(true);
		break;
	}
	case 5:
	{
		_score2->setValue(SpriteText::FIVE);
		_score2->setVisible(true);
		break;
	}
	case 6:
	{
		_score2->setValue(SpriteText::SIX);
		_score2->setVisible(true);
		break;
	}
	case 7:
	{
		_score2->setValue(SpriteText::SEVEN);
		_score2->setVisible(true);
		break;
	}
	case 8:
	{
		_score2->setValue(SpriteText::EIGHT);
		_score2->setVisible(true);
		break;
	}
	case 9:
	{
		_score2->setValue(SpriteText::NINE);
		_score2->setVisible(true);
		break;
	}

	default:
		break;
	}


	switch (score3)
	{
	case 0:
	{
		_score3->setValue(SpriteText::ZERO);
		_score3->setVisible(true);
		break;
	}
	case 1:
	{
		_score3->setValue(SpriteText::ONE);
		_score3->setVisible(true);
		break;
	}
	case 2:
	{
		_score3->setValue(SpriteText::TWO);
		_score3->setVisible(true);
		break;
	}
	case 3:
	{
		_score3->setValue(SpriteText::THREE);
		_score3->setVisible(true);
		break;
	}
	case 4:
	{
		_score3->setValue(SpriteText::FOUR);
		_score3->setVisible(true);
		break;
	}
	case 5:
	{
		_score3->setValue(SpriteText::FIVE);
		_score3->setVisible(true);
		break;
	}
	case 6:
	{
		_score3->setValue(SpriteText::SIX);
		_score3->setVisible(true);
		break;
	}
	case 7:
	{
		_score3->setValue(SpriteText::SEVEN);
		_score3->setVisible(true);
		break;
	}
	case 8:
	{
		_score3->setValue(SpriteText::EIGHT);
		_score3->setVisible(true);
		break;
	}
	case 9:
	{
		_score3->setValue(SpriteText::NINE);
		_score3->setVisible(true);
		break;
	}

	default:
		break;
	}


	switch (score4)
	{
	case 0:
	{
		_score4->setValue(SpriteText::ZERO);
		_score4->setVisible(true);
		break;
	}
	case 1:
	{
		_score4->setValue(SpriteText::ONE);
		_score4->setVisible(true);
		break;
	}
	case 2:
	{
		_score4->setValue(SpriteText::TWO);
		_score4->setVisible(true);
		break;
	}
	case 3:
	{
		_score4->setValue(SpriteText::THREE);
		_score4->setVisible(true);
		break;
	}
	case 4:
	{
		_score4->setValue(SpriteText::FOUR);
		_score4->setVisible(true);
		break;
	}
	case 5:
	{
		_score4->setValue(SpriteText::FIVE);
		_score4->setVisible(true);
		break;
	}
	case 6:
	{
		_score4->setValue(SpriteText::SIX);
		_score4->setVisible(true);
		break;
	}
	case 7:
	{
		_score4->setValue(SpriteText::SEVEN);
		_score4->setVisible(true);
		break;
	}
	case 8:
	{
		_score4->setValue(SpriteText::EIGHT);
		_score4->setVisible(true);
		break;
	}
	case 9:
	{
		_score4->setValue(SpriteText::NINE);
		_score4->setVisible(true);
		break;
	}

	default:
		break;
	}
}

int BossScene::getAladdinPosition()
{
	if (_aladdin->getPosition().getX() >= 770 * 0.45)
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

Sound* BossScene::getsoundGrounding()
{
	return _soundGrounding;
}

Sound* BossScene::getsoundSlash()
{
	return _soundSlash;
}

Sound* BossScene::getsoundPushing()
{
	return _soundPushing;
}

Sound* BossScene::getsoundThrowing()
{
	return _soundThrowing;
}

Sound* BossScene::getsoundSitSlash()
{
	return _soundSitSlash;
}

Sound* BossScene::getsoundHurt()
{
	return _soundHurt;
}

Sound* BossScene::getsoundAppleCollect()
{
	return _soundAppleCollect;
}

Sound* BossScene::getsoundAppleCrush()
{
	return _soundAppleCrush;
}

 