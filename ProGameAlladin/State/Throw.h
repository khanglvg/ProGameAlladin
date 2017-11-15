#ifndef __THROW_H__

#define __THROW_H__

#include "StateInclude.h"

NS_JK_BEGIN

class Throw : public State
{
public:
	Throw();
	~Throw() override;

	void onEnter() override;
	State* checkTransition() override;

};

NS_JK_END

#endif __THROW_H__