#pragma once
#include "Map.h"
#include "MapRendering.h"
#include "PlayerRendering.h"
#include "EnemyRendering.h"

#include <list>

class GameRendering {
private:
	
	MapSetting* CreateMap;
	Map* map;
	MapRendering* MapRender;
	//Player* player;
	PlayerRendering* player;
	EnemyRendering* enemy;

	sf::Clock clock;
	float time;

public:
	GameRendering();
	float SetTime();
	void Display();

	~GameRendering();
	
};
