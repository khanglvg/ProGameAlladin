#include "ThinEnemyIdleState.h"
#include "ThinEnemyWalkState.h"
#include "ThinEnemy.h"

US_NS_JK

ThinEnemyIdleState::ThinEnemyIdleState()
{
}

ThinEnemyIdleState::ThinEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	auto thinEnemy = static_cast<ThinEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	thinEnemy->setActionName("ThinEnemy-Idle");
}

ThinEnemyIdleState::~ThinEnemyIdleState()
{
}

void ThinEnemyIdleState::onExit()
{
}

EnemyState * ThinEnemyIdleState::checkTransition()
{
	if (_enemy->isTargetInViewRange())
	{
		return new ThinEnemyWalkState(_enemy);
	}
	return nullptr;
}
 