#pragma once
//#include <Windows.h>
#include "Player.h"
#include "EnemyVarg.h"
#include "EnemyWizard.h"
#include "EnemyOgre.h"
#include "Enemy.h"

class Battle {
private:

public:

	void AttackPlayer(Player& Player, Enemy* enemy);
	
};