#ifndef __BOSSSCENE_H__

#define __BOSSSCENE_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"
#include "GameObject/GameObject.h"
#include "Framework/Sound.h"
#include "Framework/dxaudio.h"


NS_JK_BEGIN
class Aladdin;
class Jafar;
class BossScene: public Scene
{
public:

	BossScene();
	~BossScene();
	void init() override;
	void release() override;
	void update() override;
	void render() override;

	//-1 ben trai; 1 ben phai
	int getAladdinPosition();

	int getNumApple() const;

	CSoundManager* _soundManager;
	Sound* getsoundGrounding();
	Sound* getsoundSlash();
	Sound* getsoundPushing();
	Sound* getsoundThrowing();
	Sound* getsoundSitSlash();
	Sound* getsoundHurt();
	Sound* getsoundAppleCollect();
	Sound* getsoundAppleCrush();


private:
	Aladdin* _aladdin;
	Jafar* _jafar;

	std::vector<GameObject*> _listAppleLeft;
	std::vector<GameObject*> _listAppleRight;

	GameObject* _platform1;
	GameObject* _platform2;
	GameObject* _platform3;
	GameObject* _platform4;

	Node* _bgCenter;
	Node* _bgRight;
	Node* _bgLeft;
	Node* _map;

	Sound* _soundSlash;
	Sound*_soundSitSlash;
	Sound*_soundGrounding;
	Sound*_soundPushing;
	Sound*_soundThrowing;
	Sound*_soundHurt;
	Sound*_soundAppleCollect;
	Sound*_soundAppleCrush;

};

NS_JK_END

#endif //!__BOSSSCENE_H__
