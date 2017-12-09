#include "BigEnemyIdleState.h"
#include "BigEnemy.h"

US_NS_JK

BigEnemyIdleState::BigEnemyIdleState()
{
}

BigEnemyIdleState::BigEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	auto bigEnemy = static_cast<BigEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	bigEnemy->setActionName("BigEnemy-Idle");
}

BigEnemyIdleState::~BigEnemyIdleState()
{
}

void BigEnemyIdleState::onExit()
{
}

EnemyState * BigEnemyIdleState::checkTransition()
{
	return nullptr;
}
 