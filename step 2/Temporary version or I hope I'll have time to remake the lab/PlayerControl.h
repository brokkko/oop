#pragma once
#include "iControlObject.h"
#include "Player.h"

class PlayerControl : public iControlObject, public Player {
private:
	int CheckHat, CheckWidth;
public:
	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;
};