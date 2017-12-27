#ifndef __SLASHWHENCLIMB_H__

#define __SLASHWHENCLIMB_H__
#include "State.h"
#include "../GameObject/Weapons/Weapon.h"


NS_JK_BEGIN

class SlashWhenClimb : public State
{
public:
	SlashWhenClimb(Node* node);
	~SlashWhenClimb() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State* checkTransition() override;

private:
	Weapon* _weapon;

};

NS_JK_END
#endif __SLASHWHENCLIMB_H__