#include "TobaccoPipe.h"

TobaccoPipe::TobaccoPipe(std::string name, Map* Map) : map(Map) {
	Name = name;
	Regeneration = 10;
	Generation(map);
}

void TobaccoPipe::Generation(Map* map) {
	PositionX = 0; PositionY = 0;
	while (map->GetCellFromMap(int(PositionY), int(PositionX)) != Cell::Type::Ground) {
		PositionX = float(rand() % (map->GetMapWidth() - 4) + 2);
		PositionY = float(rand() % (map->GetMapHeight() - 4) + 2);
	}
}

float TobaccoPipe::GetPositionX()
{
	return PositionX;
}

float TobaccoPipe::GetPositionY()
{
	return PositionY;
}