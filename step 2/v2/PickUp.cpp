#include "PickUp.h"

void PickUp::PickUpObject(Player& player, iPickable* obj)
{
	obj->SetState(true);

	if (obj->GetName() == "Boots") {
		player.SetSpeedControl(float(player.GetSpeedControl() + 0.3));
	}
	if (obj->GetName() == "Apple") {
		player.SetHealth(player.GetHealth() + 5);
	}
	if (obj->GetName() == "TobaccoPipe") {
		player.SetHealth(player.GetHealth() + 15);
		player.SetSpeedControl(float(player.GetSpeedControl() - 0.2));
	}
}
