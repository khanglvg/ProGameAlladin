#ifndef __MENUSELECTOR_H__

#define __MENUSELECTOR_H__
#include "Framework/definitions.h"
#include "Framework/Scene.h"

NS_JK_BEGIN
class MenuSelector: public Scene
{
public:
	MenuSelector();
	~MenuSelector();

	void init() override;
	void update() override;
	void render() override;
	void release() override;

private:
};

NS_JK_END

#endif __MENUSELECTOR_H__

