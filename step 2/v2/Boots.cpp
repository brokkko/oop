#include "Boots.h"

Boots::Boots(std::string name, Map* Map) : map(Map) {
	Name = name;
	NewSpeed = 0.5;
	Generation(map);
}

void Boots::Generation(Map* map) {
	PositionX = 0; PositionY = 0;
	while (map->GetCellFromMap(int(PositionY), int(PositionX)) != Cell::Type::Ground) {
		PositionX = float(rand() % (map->GetMapWidth() - 4) + 2);
		PositionY = float(rand() % (map->GetMapHeight() - 4) + 2);
	}
}

float Boots::GetPositionX()
{
	return PositionX;
}

float Boots::GetPositionY()
{
	return PositionY;
}

