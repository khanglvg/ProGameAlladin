#ifndef __DEATHSCENE_H__

#define __DEATHSCENE_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"
#include "GameObject/AladdinDeath.h"

NS_JK_BEGIN

class DeathScene: public Scene
{
public:
	DeathScene(Scene* currentScene);
	~DeathScene();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

private:
	AladdinDeath* _ala;
	AladdinDeath* _abu;
};

NS_JK_END

#endif // !__DEATHSCENE_H__
