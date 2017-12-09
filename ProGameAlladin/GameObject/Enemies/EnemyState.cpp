#include "EnemyState.h"

US_NS_JK

EnemyState::EnemyState()
{
}

EnemyState::EnemyState(Enemy * enemy, StateName name)
{
	_name = name;
	_enemy = enemy;

	_totalDuration = 0;

	//special for attack state
	_isAttackedPlayer = false;
}


EnemyState::~EnemyState()
{

}

void EnemyState::onUpdate()
{
}

void EnemyState::onExit()
{
}

EnemyState::StateName EnemyState::GetName()
{
	return _name;
}

bool EnemyState::IsAttackedPlayer()
{
	return _isAttackedPlayer;
}

void EnemyState::SetIsAttackedPlayer(bool value)
{
	_isAttackedPlayer = value;
}
