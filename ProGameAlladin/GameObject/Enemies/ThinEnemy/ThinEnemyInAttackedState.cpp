#include "ThinEnemyInAttackedState.h"
#include "ThinEnemy.h"

US_NS_JK

ThinEnemyInAttackedState::ThinEnemyInAttackedState()
{
}

ThinEnemyInAttackedState::ThinEnemyInAttackedState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	auto thinEnemy = static_cast<ThinEnemy*>(enemy);
	/*if (Input::getInstance()->getKey(KEY_LEFT_ARROW))
	aladdin->setScale(Vec2(-1, 1));

	if (Input::getInstance()->getKey(KEY_RIGHT_ARROW))
	aladdin->setScale(Vec2(1, 1));*/

	//thinEnemy->setVelocity(Vec2(0, 0));

	thinEnemy->setActionName("KnifeEnemy-Attacked");
}

ThinEnemyInAttackedState::~ThinEnemyInAttackedState()
{
}

void ThinEnemyInAttackedState::onExit()
{
}

EnemyState * ThinEnemyInAttackedState::checkTransition()
{
	return nullptr;
}
 