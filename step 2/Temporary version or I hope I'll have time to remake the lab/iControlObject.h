#pragma once
#include "Map.h"

class iControlObject {
public:
	virtual ~iControlObject(){}

	virtual void MovingUpdate(Map& map, float time) = 0;
	virtual void InteractionWithMap(Map& map, double dx, double dy) = 0;
};
