#include "Entity.h"

Entity::Entity(std::string name, int H, int W, int health) : speed(0), dx(0), dy(0), Life(true), Direction(" ")
{
	EntityHeight = H, EntityWidth = W;
	Name = name;
	Health = health;

}

Entity Entity::GetEntity()
{
	return *this;
}

bool Entity::GetLife()
{
	return Life;
}

double Entity::GetDx()
{
	return dx;
}


double Entity::GetDy()
{
	return dy;
}

double Entity::GetSpeed()
{
	return speed;
}

float Entity::GetPositionX()
{
	return PositionX;
}

float Entity::GetPositionY()
{
	return PositionY;
}

int Entity::GetEntityWidth()
{
	return EntityWidth;
}

int Entity::GetEntityHeight()
{
	return EntityHeight;
}

int Entity::GetHealth()
{
	return Health;
}

std::string Entity::GetDirection()
{
	return Direction;
}

std::string Entity::GetName()
{
	return Name;
}

void Entity::SetDx(double val)
{
	dx = val;
}


void Entity::SetDy(double val)
{
	dy = val;
}

void Entity::SetSpeed(double val)
{
	speed = val;
}

void Entity::SetPositionX(float X)
{
	PositionX = X;
}

void Entity::SetPositionY(float Y)
{
	PositionY = Y;
}

void Entity::SetEntityWidth(int W)
{
	EntityWidth = W;
}

void Entity::SetEntityHeight(int H)
{
	EntityHeight = H;
}

void Entity::SetDirection(std::string dir)
{
	Direction = dir;
}

//void Entity::SetName(std::string name)
//{
//	Name = name;
//}

void Entity::SetHealth(int val)
{
	Health = val;
}

void Entity::SetLife(bool val)
{
	Life = val;
}
