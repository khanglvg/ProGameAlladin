#ifndef __LV1SCENE_H_


#define __LV1SCENE_H_

#include "Framework/Scene.h"

#include "Aladdin.h"

NS_JK_BEGIN

class Lv1Scene: public Scene
{
public:
	Lv1Scene();
	~Lv1Scene();
	void init() override;
	void release() override;
	void update() override;
	void render() override;

private:
	
};

NS_JK_END

#endif __LV1SCENE_H__

