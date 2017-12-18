#ifndef __THROW_H__

#define __THROW_H__
#include "State.h"


NS_JK_BEGIN

class Throw : public State
{
public:
	Throw(Node* node);
	~Throw() override;

	void onEnter() override;
	void onUpdate() override;
	void onExit() override;
	State* checkTransition() override;

	enum{THROW,DONE};
	int _state = DONE;
private:
	bool _isThrow = false;
};

NS_JK_END

#endif __THROW_H__