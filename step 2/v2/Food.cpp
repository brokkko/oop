#include "Food.h"

Food::Food(std::string name, Map* Map) : map(Map) {
	Name = name;
	Fill = 10;
	Generation(map);
}

void Food::Generation(Map *map) {
	PositionX = 0; PositionY = 0;
	while (map->GetCellFromMap(int(PositionY), int(PositionX)) != Cell::Type::Ground) {
		PositionX = float(rand() % (map->GetMapWidth() -4) + 2);
		PositionY = float(rand() % (map->GetMapHeight() -4) + 2) ;
	}
	
}

float Food::GetPositionX()
{
	return PositionX;
}

float Food::GetPositionY()
{
	return PositionY;
}
