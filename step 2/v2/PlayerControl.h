#pragma once
#include "iControlObject.h"
#include "Player.h"

class PlayerControl : public iControlObject{
private:
	Player* player;

	int CheckHat, CheckWidth;
	
public:
	PlayerControl(Player* player);

	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;

	~PlayerControl();
};