#include "EnemyExplosionState.h"
#include "Enemy.h"

US_NS_JK

EnemyExplosionState::EnemyExplosionState()
{
}

EnemyExplosionState::EnemyExplosionState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Walk)
{
	_enemy = enemy;
	_enemy->setActionName("Enemy-Explosion");
	_enemy->setTexture("Resources/Enemies/enemy_explosion_strip10_89_114.png");
	_enemy->setScale(Vec2(0.5,0.5));
	_enemy->getRigidBody()->setActive(false);
}

EnemyExplosionState::~EnemyExplosionState()
{
}

void EnemyExplosionState::onUpdate()
{

}

void EnemyExplosionState::onExit()
{
}

EnemyState * EnemyExplosionState::checkTransition()
{
	return nullptr;
}
 