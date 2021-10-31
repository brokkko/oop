#include "EnemyOgre.h"

EnemyOgre::EnemyOgre(std::string name, int H, int W, int Health, Map& map) : Enemy(name, H, W, Health)
{
	Generation(map);
	SetDamage(30);
}

void EnemyOgre::Generation(Map& map)
{
	//PositionX = 3; PositionY = 14;
	PositionX = 0; PositionY = 0;
	while (map.GetCellFromMap(int(PositionY), int(PositionX)) != Cell::Type::Ground) {
		PositionX = float(rand() % (map.GetMapWidth() - 4) + 2);
		PositionY = float(rand() % (map.GetMapHeight() - 4) + 2);
	}
	PositionX = PositionX * 66; PositionY = PositionY * 66;
}
