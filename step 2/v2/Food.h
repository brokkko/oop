#pragma once
#include "iPickable.h"

class Food : public iPickable {
private:
	Map* map;
	int Fill;
public:
	Food(std::string name, Map* map);

	void Generation(Map* map) override;

	float GetPositionX();
	float GetPositionY();

};