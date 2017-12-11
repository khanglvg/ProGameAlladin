#include "ThinEnemyAttackState.h"
#include "ThinEnemy.h"

US_NS_JK

ThinEnemyAttackState::ThinEnemyAttackState()
{
}

ThinEnemyAttackState::ThinEnemyAttackState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	auto thinEnemy = static_cast<ThinEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	thinEnemy->setActionName("KnifeEnemy-Attack");
}

ThinEnemyAttackState::~ThinEnemyAttackState()
{
}

void ThinEnemyAttackState::onExit()
{
}

EnemyState * ThinEnemyAttackState::checkTransition()
{
	return nullptr;
}
 