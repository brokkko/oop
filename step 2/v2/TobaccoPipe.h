#pragma once
#include "iPickable.h"

class TobaccoPipe : public iPickable {
private:
	Map* map;
	int Regeneration;
public:
	TobaccoPipe(std::string name, Map* map);

	void Generation(Map* map) override;

	float GetPositionX();
	float GetPositionY();

};