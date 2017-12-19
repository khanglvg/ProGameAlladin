#include "FloatGroundState.h"

US_NS_JK

FloatGroundState::FloatGroundState()
{
}

FloatGroundState::FloatGroundState(FloatGround * springBoard, StateName name)
{
	_name = name;
	_springBoard = springBoard;

	_totalDuration = 0;

	//special for attack state
	_isAttackedPlayer = false;
}


FloatGroundState::~FloatGroundState()
{

}

void FloatGroundState::onUpdate()
{
}

void FloatGroundState::onExit()
{
}

FloatGroundState::StateName FloatGroundState::GetName()
{
	return _name;
}

bool FloatGroundState::IsAttackedPlayer()
{
	return _isAttackedPlayer;
}

void FloatGroundState::SetIsAttackedPlayer(bool value)
{
	_isAttackedPlayer = value;
}
