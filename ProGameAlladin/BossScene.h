#ifndef __BOSSSCENE_H__

#define __BOSSSCENE_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"
#include "GameObject/GameObject.h"


NS_JK_BEGIN
class Aladdin;
class BossScene: public Scene
{
public:

	BossScene();
	~BossScene();
	void init() override;
	void release() override;
	void update() override;
	void render() override;

private:
	Aladdin* _aladdin;
	GameObject* _jafar;

	GameObject* _platform1;
	GameObject* _platform2;
	GameObject* _platform3;
	GameObject* _platform4;

	Node* _bgCenter;
	Node* _bgRight;
	Node* _bgLeft;
	Node* _map;

};

NS_JK_END

#endif //!__BOSSSCENE_H__
