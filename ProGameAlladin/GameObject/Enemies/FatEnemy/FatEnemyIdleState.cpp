#include "FatEnemyIdleState.h"
#include "FatEnemy.h"

US_NS_JK

FatEnemyIdleState::FatEnemyIdleState()
{
}

FatEnemyIdleState::FatEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	auto fatEnemy = static_cast<FatEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	fatEnemy->setActionName("FatEnemy-Idle");
}

FatEnemyIdleState::~FatEnemyIdleState()
{
}

void FatEnemyIdleState::onExit()
{
}

EnemyState * FatEnemyIdleState::checkTransition()
{
	return nullptr;
}
 