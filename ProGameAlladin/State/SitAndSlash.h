#ifndef __SITANDSLASH_H__

#define __SITANDSLASH_H__
#include "State.h"
#include "../GameObject/Weapons/Weapon.h"

NS_JK_BEGIN

class SitAndSlash : public State
{
public:
	SitAndSlash(Node*node);
	~SitAndSlash() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State* checkTransition() override;
private:
	Weapon* _weapon;

};

NS_JK_END
#endif __SITANDSLASH_H__