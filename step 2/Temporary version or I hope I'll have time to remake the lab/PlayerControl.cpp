#include "PlayerControl.h"

void PlayerControl::MovingUpdate(Map& map, float time)
{
	
	//KeyControl();
	if (Direction == "Right") { dx = speed; dy = 0; }
	if (Direction == "Left") { dx = -speed; dy = 0; }
	if (Direction == "Down") { dx = 0; dy = speed; }
	if (Direction == "Up") { dx = 0; dy = -speed; }

	PositionX += float(dx * time); //dx = 0;
	PositionY += float(dy * time); //dy = 0;
	speed = 0;

	InteractionWithMap(map, dx, dy);

	//PlayerSprite.setPosition(PositionX, PositionY);

	// if (Health <= 0) Life = false;
}

void PlayerControl::InteractionWithMap(Map& map, double Dx, double Dy)
{
	for (int i = int((PositionY + CheckHat) / 66); i < (PositionY + EntityHeight) / 66; i++) {
		for (int j = int((PositionX + CheckWidth) / 66); j < (PositionX + EntityWidth) / 66; j++) {
			if (Dx < 0 && PositionX < 10) {
				PositionX = float(j * 66 + 10);
				dx = 0;
			}
			if (map.GetCellFromMap(i, j) == '1') {
				if (Dy > 0) { PositionY = float(i * 66 - EntityHeight); dy = 0; }			 // down
				if (Dy < 0) { PositionY = float(i * 66 + 66 - CheckHat); dy = 0; }   // up
				if (Dx > 0) { PositionX = float(j * 66 - EntityWidth); dx = 0; }             // right
				if (Dx < 0) { PositionX = float(j * 66 + 66 - CheckWidth); dx = 0; } // left
			}

		}
	}
}
