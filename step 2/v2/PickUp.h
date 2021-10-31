#pragma once
#include "Player.h"
#include "Food.h"
#include "Boots.h"
#include "TobaccoPipe.h"

class PickUp {
public:
	void PickUpObject(Player& player, iPickable* obj);
};
