#include "EnemyWizard.h"

EnemyWizard::EnemyWizard(std::string name, int H, int W, int Health, Map& map) : Enemy(name, H, W, Health)
{
	Generation(map);
	SetDamage(50);
}

void EnemyWizard::Generation(Map& map)
{
	//PositionX = 7; PositionY = 7;
	
	PositionX = 0; PositionY = 0;
	while (map.GetCellFromMap(int(PositionY), int(PositionX)) != Cell::Type::Ground) {
		PositionX = float(rand() % (map.GetMapWidth() - 4) + 2);
		PositionY = float(rand() % (map.GetMapHeight() - 4) + 2);
	}
	PositionX = PositionX * 66; PositionY = PositionY * 66;
}
