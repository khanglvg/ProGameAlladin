#include "WallEnemyIdleState.h"
#include "WallEnemy.h"

US_NS_JK

WallEnemyIdleState::WallEnemyIdleState()
{
}

WallEnemyIdleState::WallEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	auto wallEnemy = static_cast<WallEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	wallEnemy->setActionName("WallEnemy-Idle");
}

WallEnemyIdleState::~WallEnemyIdleState()
{
}

void WallEnemyIdleState::onExit()
{
}

EnemyState * WallEnemyIdleState::checkTransition()
{
	return nullptr;
}
 