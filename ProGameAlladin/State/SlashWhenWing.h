#ifndef __SLASHWHENWING_H__
#define __SLASHWHENWING_H__
#include "State.h"
#include "../GameObject/Weapons/Weapon.h"

NS_JK_BEGIN
class SlashWhenWing:public State
{
public:
	SlashWhenWing(Node*node);
	~SlashWhenWing() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State*checkTransition() override;
private:
	Weapon* _weapon;
};
NS_JK_END
#endif

