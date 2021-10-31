#include "iPickable.h"

iPickable::iPickable() : PositionX(0), PositionY(0)
{
	PickedUp = false;
}

bool iPickable::GetState()
{
	return PickedUp;
}

void iPickable::SetState(bool val)
{
	PickedUp = val;
}

float iPickable::GetPosX()
{
	return PositionX;
}

float iPickable::GetPosY()
{
	return PositionY;
}

std::string iPickable::GetName()
{
	return Name;
}
