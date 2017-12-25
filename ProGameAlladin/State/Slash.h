#ifndef __SLASH_H__

#define __SLASH_H__
#include "State.h"
#include "../GameObject/Weapons/Weapon.h"


NS_JK_BEGIN

class Slash : public State
{
public:
	Slash(Node* node);
	~Slash() override;

	void onEnter() override;
	void onExit() override;
	State* checkTransition() override;

private:
	Weapon* _weapon;
};

NS_JK_END

#endif __SLASH_H__