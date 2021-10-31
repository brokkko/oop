#include "PlayerControl.h"

PlayerControl::PlayerControl(Player* Player) : player(Player){
	
	CheckHat = 30;
	CheckWidth = 10;
}

void PlayerControl::MovingUpdate(Map& map, float time)
{
	if ( player->GetDirection() == "Right") { player->SetDx(player->GetSpeed()); player->SetDy(0);}
	if (player->GetDirection() == "Left") { player->SetDx(-player->GetSpeed()); player->SetDy(0); }
	if (player->GetDirection() == "Down") { player->SetDx(0); player->SetDy(player->GetSpeed()); }
	if (player->GetDirection() == "Up") { player->SetDx(0); player->SetDy(-player->GetSpeed()); }

	player->SetPositionX(player->GetPositionX() + float(player->GetDx() * time)); 
	player->SetPositionY(player->GetPositionY() + float(player->GetDy() * time));
	player->SetSpeed(0);

	InteractionWithMap(map, player->GetDx(), player->GetDy());
}

void PlayerControl::InteractionWithMap(Map& map, double Dx, double Dy)
{
	for (int i = int((player->GetPositionY() + CheckHat) / 66); i < (player->GetPositionY() + player->GetEntityHeight()) / 66; i++) {
		for (int j = int((player->GetPositionX() + CheckWidth) / 66); j < (player->GetPositionX() + player->GetEntityWidth()) / 66; j++) {
			if (Dx < 0 && player->GetPositionX() < 10) {
				player->SetPositionX(float(j * 66 + 10));
				player->SetDx(0);
			}
			if (Dx > 0 && player->GetPositionX() > map.GetMapWidth() * 66 - 50) {
				player->SetPositionX(float(j * 66 - 10));
				player->SetDx(0);
			}
			if (map.GetCellFromMap(i, j) == Cell::Type::Wall) {
				if (Dy > 0) { player->SetPositionY(float(i * 66 - player->GetEntityHeight())); player->SetDy(0); }		
				if (Dy < 0) { player->SetPositionY(float(i * 66 + 66 - CheckHat)); player->SetDy(0); }
				if (Dx > 0) { player->SetPositionX(float(j * 66 - player->GetEntityWidth())); player->SetDx(0); }
				if (Dx < 0) { player->SetPositionX(float(j * 66 + 66 - CheckWidth)); player->SetDx(0); }
			}

		}
	}
}

PlayerControl::~PlayerControl()
{
	if (player) delete player;
}
