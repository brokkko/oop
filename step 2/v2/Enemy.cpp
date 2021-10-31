#include "Enemy.h"

Enemy::Enemy(std::string name, int H, int W, int health) : Entity(name, H, W, health)
{
	PositionX = 0; PositionY = 0;
	Damage = 0; 
}

void Enemy::SetDamage(int val)
{
	Damage = val;
}

int Enemy::GetDamage()
{
	return Damage;
}



