#ifndef __COMPLETESCENE_H__

#define __COMPLETESCENE_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"
#include "GameObject/TitleMenuScene.h"
#include "GameObject/AladdinAndAbu.h"

NS_JK_BEGIN

class CompleteScene: public Scene
{
public:
	CompleteScene();
	~CompleteScene();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

private:
	TitleMenuScene* _title;
	AladdinAndAbu* _ala;
	AladdinAndAbu* _abu;
};

NS_JK_END

#endif //!__COMPLETESCENE_H__