#include "CamelState.h"

US_NS_JK

CamelState::CamelState()
{
}

CamelState::CamelState(Camel * camel, StateName name)
{
	_name = name;
	_camel = camel;

	_totalDuration = 0;

	//special for attack state
	_isAttackedPlayer = false;
}


CamelState::~CamelState()
{

}

void CamelState::onUpdate()
{
}

void CamelState::onExit()
{
}

CamelState::StateName CamelState::GetName()
{
	return _name;
}

bool CamelState::IsAttackedPlayer()
{
	return _isAttackedPlayer;
}

void CamelState::SetIsAttackedPlayer(bool value)
{
	_isAttackedPlayer = value;
}
