#include "Lv1Scene.h"
#include "Framework/Camera.h"
#include "GameObject/Enemies/Enemy.h"
#include "GameObject/Weapons/AppleToThrow.h"
#include "GameObject/Wall/Wall.h"
#include "GameObject/BackgroundSky.h"
#include "Framework/Text.h"
#include "GameObject/Aladdin.h"
#include "Framework/Audio.h"
#include "Framework/Input.h"
#include "GameObject/TitleMenuScene.h"
#include "GameObject/Items/AladdinHealth.h"
#include "Framework/GameManager.h"
#include "Framework/PhysicsManager.h"
#include "DeathScene.h"

US_NS_JK




Lv1Scene::Lv1Scene()
{

}



Lv1Scene::~Lv1Scene()
{
	_gameMap->~GameMap();
}


void Lv1Scene::init()
{


#pragma region Sound 
	_soundBackground = new Sound("Resources/Audio/AgrabahMarket.wav");
	_soundAbu = new Sound("Resources/Audio/Abu.wav");
	_soundSlash = new Sound("Resources/Audio/High Sword.wav");
	_soundSitSlash = new Sound("Resources/Audio/Low Sword.wav");
	_soundGrounding = new Sound("Resources/Audio/Aladdin Oof.wav");
	_soundPushing = new Sound("Resources/Audio/Aladdin Push.wav");
	_soundThrowing = new Sound("Resources/Audio/Object Throw.wav");
	_soundHurt = new Sound("Resources/Audio/Aladdin Hurt.wav");
	_soundAppleCollect = new Sound("Resources/Audio/Apple Collect.wav");
	_soundAppleCrush = new Sound("Resources/Audio/Apple Splash.wav");
	_soundCamel = new Sound("Resources/Audio/Camel Spit.wav");
	_soundSpring = new Sound("Resources/Audio/Spring Doing 1.wav");

	Audio::get()->load(_soundAbu);
	Audio::get()->load(_soundBackground);
	Audio::get()->load(_soundSlash);
	Audio::get()->load(_soundSitSlash);
	Audio::get()->load(_soundGrounding);
	Audio::get()->load(_soundPushing);
	Audio::get()->load(_soundThrowing);
	Audio::get()->load(_soundHurt);
	Audio::get()->load(_soundAppleCollect);
	Audio::get()->load(_soundAppleCrush);
	Audio::get()->load(_soundCamel);
	Audio::get()->load(_soundSpring);
	//Audio::get()->play(_soundBackground, true);

#pragma endregion 

	mAladdin = new Aladdin(Vec2(300, 600), Size(10, 60));
	mAladdin->setCurrentScene(this);
	_vectNode.push_back(mAladdin);



	_gameMap = new GameMap("Resources/AgrabahMarket.tmx", mQuadTree, mAladdin);


	Camera::getInstance()->follow(mAladdin);
	Camera::getInstance()->setScaleFactor(Vec2(2, 2));
	_vectNode.push_back(Camera::getInstance());

	_bg1 = new BackgroundSky("Resources/background.png", 0);
	_bg1->setPosition(Vec2(Camera::getInstance()->getCameraX(), Camera::getInstance()->getCameraY()));
	_bg1->setScale(Vec2(0.9, 1.3));
	_vectNode.push_back(_bg1);

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


	_alaLifeUnit = new SpriteText("Resources/Menu/text.png", SpriteText::THREE, 4);
	_alaLifeUnit->setType(SpriteText::SpriteTextType::ALA_LIFE);
	_alaLifeUnit->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_alaLifeUnit);



	_appleUnit = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_appleUnit->setType(SpriteText::SpriteTextType::APPLE_UNIT);
	_appleUnit->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_appleUnit);


	_alaAppleTens = new SpriteText("Resources/Menu/text.png", SpriteText::ONE, 4);
	_alaAppleTens->setType(SpriteText::SpriteTextType::APPLE_TENS);
	_alaAppleTens->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_alaAppleTens);


	_rubyUnit = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_rubyUnit->setType(SpriteText::SpriteTextType::RUBY_UNIT);
	_rubyUnit->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_rubyUnit);


	_rubyTens = new SpriteText("Resources/Menu/text.png", SpriteText::ZERO, 4);
	_rubyTens->setType(SpriteText::SpriteTextType::RUBY_TENS);
	_rubyTens->setScale(Vec2(0.5, 0.7));
	_vectNode.push_back(_rubyTens);


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


	_alaHealth = new AladdinHealth(mAladdin);
	_alaHealth->setPosition(Vec2(Camera::getInstance()->getCameraX() - 150, Camera::getInstance()->getCameraY() - 80));

	_vectNode.push_back(_alaHealth);

	for (auto ground : _gameMap->getListGround())
	{
		_vectNode.push_back(ground);
	}

	_gameMap->init();

	_alaLife = new Text("Arial", "3", Camera::getInstance()->getCameraX(), Camera::getInstance()->getCameraX(), 20, 30, FW_BOLD, Color(255, 255, 255, 255));
	_vectNode.push_back(_alaLife);
	//for (auto object : staticobject)
	//{
	//	object->init();
	//	mQuadTree->insertObject(object);
	//}

	PhysicsManager::getIntance()->setInBoss(false);
	_isInitialized = true;
	Scene::init();

}

void Lv1Scene::release()
{
	_gameMap->release();
	Audio::get()->release();
	Scene::release();
}

void Lv1Scene::update()
{
	Camera::getInstance()->follow(mAladdin);
	//checkVisibility();
	_alaLife->setPosition(Vec2(Camera::getInstance()->getCameraX(), Camera::getInstance()->getCameraY()));
	_bg1->setPosition(Vec2(Camera::getInstance()->getCameraX() - 170, Camera::getInstance()->getCameraY() - 130));
	calculationSpriteText();

	_gameMap->update();
	Scene::update();
	
	if (i > 100)
	{
		PhysicsManager::getIntance()->setBeginLv1(false);
	}
	else
	{
		i++;
	}

	if (mAladdin->getNumApple() == 0)
	{
		// change Scene
		GameManager::getInstance()->changeScene(new DeathScene(this));
		
	}

}

void Lv1Scene::render()
{
	_gameMap->draw();
	Scene::render();
	//for (auto object : listVisible)
	//{
	//	object->render();
	//}
}

void Lv1Scene::calculationSpriteText() const
{
	const auto score = mAladdin->getNumApple() * 123;
	const auto score1 = score / 1000;
	const auto score2 = (score / 100)%10;
	const auto score3 = (score / 10)%10;
	const auto score4 = score % 10;

	const auto ruby = mAladdin->getNumRuby();
	const auto rUnit = ruby % 10;
	const auto rTens = ruby / 10;


	const auto apple = mAladdin->getNumApple();
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
		_alaAppleTens->setValue(SpriteText::ZERO);
		_alaAppleTens->setVisible(false);
		break;
	}
	case 1:
	{
		_alaAppleTens->setValue(SpriteText::ONE);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 2:
	{
		_alaAppleTens->setValue(SpriteText::TWO);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 3:
	{
		_alaAppleTens->setValue(SpriteText::THREE);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 4:
	{
		_alaAppleTens->setValue(SpriteText::FOUR);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 5:
	{
		_alaAppleTens->setValue(SpriteText::FIVE);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 6:
	{
		_alaAppleTens->setValue(SpriteText::SIX);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 7:
	{
		_alaAppleTens->setValue(SpriteText::SEVEN);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 8:
	{
		_alaAppleTens->setValue(SpriteText::EIGHT);
		_alaAppleTens->setVisible(true);
		break;
	}
	case 9:
	{
		_alaAppleTens->setValue(SpriteText::NINE);
		_alaAppleTens->setVisible(true);
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



	switch (mAladdin->getAlaLife())
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


Sound* Lv1Scene::getsoundAbu()
{
	return _soundAbu;
}

Sound* Lv1Scene::getsoundGrounding()
{
	return _soundGrounding;
}

Sound* Lv1Scene::getsoundSlash()
{
	return _soundSlash;
}

Sound* Lv1Scene::getsoundPushing()
{
	return _soundPushing;
}

Sound* Lv1Scene::getsoundThrowing()
{
	return _soundThrowing;
}

Sound* Lv1Scene::getsoundSitSlash()
{
	return _soundSitSlash;
}

Sound* Lv1Scene::getsoundHurt()
{
	return _soundHurt;
}

Sound* Lv1Scene::getsoundAppleCollect()
{
	return _soundAppleCollect;
}

Sound* Lv1Scene::getsoundAppleCrush()
{
	return _soundAppleCrush;
}

Sound* Lv1Scene::getsoundCamel()
{
	return _soundCamel;
}

Sound* Lv1Scene::getsoundSpring()
{
	return _soundSpring;
}


//
//void Lv1Scene::checkVisibility()
//{
//	listVisible.clear();
//
// 	mQuadTree->getObjectsVisibility(listVisible, mQuadTree->getVisibilityArea(mAladdin), 1);
//}

