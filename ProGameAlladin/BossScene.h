#ifndef __BOSSSCENE_H__

#define __BOSSSCENE_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"
#include "GameObject/GameObject.h"

NS_JK_BEGIN

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
	GameObject* _aladdin;
	GameObject* _jafar;

	Node* _bgCenter;
	Node* _bgRight;
	Node* _bgLeft;
	Node* _map;

};

NS_JK_END

#endif //!__BOSSSCENE_H__
