#include "HideEnemyIdleState.h"
#include "HideEnemy.h"

US_NS_JK

HideEnemyIdleState::HideEnemyIdleState()
{
}

HideEnemyIdleState::HideEnemyIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	auto knifeEnemy = static_cast<HideEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	knifeEnemy->setActionName("HideEnemy-Idle");
}

HideEnemyIdleState::~HideEnemyIdleState()
{
}

void HideEnemyIdleState::onExit()
{
}

EnemyState * HideEnemyIdleState::checkTransition()
{
	return nullptr;
}
 