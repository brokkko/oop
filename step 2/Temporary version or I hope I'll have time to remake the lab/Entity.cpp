#include "Entity.h"

Entity::Entity(std::string name, int H, int W, float PosX, float PosY, int health) : speed(0), dx(0), dy(0), Life(true), Direction(" ")
{
	PositionX = PosX; PositionY = PosY;
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
