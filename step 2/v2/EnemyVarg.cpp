#include "EnemyVarg.h"

EnemyVarg::EnemyVarg(std::string name, int H, int W, int Health, Map& map): Enemy(name, H, W, Health)
{
	Generation(map);
	SetDamage(30);
}

void EnemyVarg::Generation(Map& map)
{
	//PositionX = 15; PositionY = 13;
	
	PositionX = 0; PositionY = 0;
	while (map.GetCellFromMap(int(PositionY), int(PositionX)) != Cell::Type::Ground) {
		PositionX = float(rand() % (map.GetMapWidth() - 4) + 2);
		PositionY = float(rand() % (map.GetMapHeight() - 4) + 2);
	}
	PositionX = PositionX * 66; PositionY = PositionY * 66;
}
