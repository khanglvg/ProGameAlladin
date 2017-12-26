#ifndef __RUNANDSLASH_H__
#define __RUNANDSLASH_H__
#include "State.h"
#include "../GameObject/Weapons/Weapon.h"

NS_JK_BEGIN
class RunAndSlash:public State
{
public:
	RunAndSlash(Node* node);
	~RunAndSlash() override;
	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State* checkTransition() override;
	enum { NONE,RUN};
	int _state = NONE;

private:
	Weapon* _weapon;

};
NS_JK_END
#endif// !__RUNANDSLASH_H__
