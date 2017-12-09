#include "SpringBoardState.h"

US_NS_JK

SpringBoardState::SpringBoardState()
{
}

SpringBoardState::SpringBoardState(SpringBoard * springBoard, StateName name)
{
	_name = name;
	_springBoard = springBoard;

	_totalDuration = 0;

	//special for attack state
	_isAttackedPlayer = false;
}


SpringBoardState::~SpringBoardState()
{

}

void SpringBoardState::onUpdate()
{
}

void SpringBoardState::onExit()
{
}

SpringBoardState::StateName SpringBoardState::GetName()
{
	return _name;
}

bool SpringBoardState::IsAttackedPlayer()
{
	return _isAttackedPlayer;
}

void SpringBoardState::SetIsAttackedPlayer(bool value)
{
	_isAttackedPlayer = value;
}
