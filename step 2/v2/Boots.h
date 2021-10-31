#pragma once
#include "iPickable.h"

class Boots : public iPickable {
private:
	Map* map;
	double NewSpeed;
public:
	Boots(std::string name, Map* map);

	void Generation(Map* map) override;

	float GetPositionX();
	float GetPositionY();

};