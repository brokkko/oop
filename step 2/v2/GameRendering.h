#pragma once
#include "Map.h"
#include "MapRendering.h"

#include "PlayerRendering.h"
#include "PlayerControl.h"
#include "Player.h"

#include "EnemyVarg.h"
#include "EnemyVargControl.h"
#include "EnemyVargRendering.h"

#include "EnemyWizard.h"
#include "EnemyWizardControl.h"
#include "EnemyWizardRendering.h"

#include "EnemyOgre.h"
#include "EnemyOgreControl.h"
#include "EnemyOgreRendering.h"

#include "Food.h"
#include "FoodRendering.h"

#include "TobaccoPipe.h"
#include "TobaccoPipeRendering.h"

#include "Boots.h"
#include "BootsRendering.h"

#include "InfoRendering.h"
#include "Battle.h"
#include "PickUp.h"

#include <list>

class GameRendering {
private:

	InfoRendering* info;
	Battle* battle;
	PickUp* pick;

	MapSetting* CreateMap;
	Map* map;
	MapRendering* MapRender;

	Player* player;
	PlayerControl* PControl;
	PlayerRendering* PRendering;

	EnemyVarg* Varg;
	EnemyVargControl* VControl;
	EnemyVargRendering* VRendering;

	EnemyWizard* wizard;
	EnemyWizardControl* WControl;
	EnemyWizardRendering* WRendering;

	EnemyOgre* ogre;
	EnemyOgreControl* OControl;
	EnemyOgreRendering* ORendering;

	Food* apple;
	FoodRendering* FRendering;

	TobaccoPipe* pipe;
	TobaccoPipeRendering* PipeRendering;

	Boots* boots;
	BootsRendering* BootsRend;

	sf::Clock clock;
	float time;

	std::list<Enemy*> Enemies;
	std::list<Enemy*>::iterator it;

	std::list<iPickable*> objects;
	std::list<iPickable*>::iterator itObj;

public:
	GameRendering();
	float SetTime();
	void Initialization();
	void UpdatePosition(float time);
	void Rendering(sf::RenderWindow& window);
	void Display();

	~GameRendering();
	
};
