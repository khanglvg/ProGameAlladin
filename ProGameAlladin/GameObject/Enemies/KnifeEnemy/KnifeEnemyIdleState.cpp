#include "KnifeEnemyIdleState.h"
#include "KnifeEnemy.h"

US_NS_JK

KnifeEnemyIdleState::KnifeEnemyIdleState()
{
}

KnifeEnemyIdleState::KnifeEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	auto knifeEnemy = static_cast<KnifeEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	knifeEnemy->setActionName("KnifeEnemy-Idle");
}

KnifeEnemyIdleState::~KnifeEnemyIdleState()
{
}

void KnifeEnemyIdleState::onExit()
{
}

EnemyState * KnifeEnemyIdleState::checkTransition()
{
	return nullptr;
}
 