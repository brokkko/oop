#pragma once
#include <iostream>
#include "Map.h"

class iPickable {
protected:
	float PositionX;
	float PositionY;

	bool PickedUp;
	std::string Name;

public:
	iPickable();

	virtual void Generation(Map* map) = 0;

	bool GetState();
	void SetState(bool val);

	float GetPosX();
	float GetPosY();
	std::string GetName();

};
