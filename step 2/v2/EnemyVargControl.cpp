#include "EnemyVargControl.h"

EnemyVargControl::EnemyVargControl(EnemyVarg* Varg) : varg(Varg) {

}

void EnemyVargControl::MovingUpdate(Map& map, float time)
{
	if (varg->GetDirection() == "Right") { varg->SetDx(varg->GetSpeed()); varg->SetDy(0); }
	if (varg->GetDirection() == "Left") { varg->SetDx(-varg->GetSpeed()); varg->SetDy(0); }
	if (varg->GetDirection() == "Down") { varg->SetDx(0); varg->SetDy(varg->GetSpeed()); }
	if (varg->GetDirection() == "Up") { varg->SetDx(0); varg->SetDy(-varg->GetSpeed()); }

	varg->SetPositionX(varg->GetPositionX() + float(varg->GetDx() * time));
	varg->SetPositionY(varg->GetPositionY() + float(varg->GetDy() * time));
	varg->SetSpeed(0);

	InteractionWithMap(map, varg->GetDx(), varg->GetDy());
}

void EnemyVargControl::InteractionWithMap(Map& map, double Dx, double Dy)
{
	for (int i = int (varg->GetPositionY() / 66); i < (varg->GetPositionY() + varg->GetEntityHeight()) / 66; i++) {
		for (int j = int(varg->GetPositionX() / 66); j < (varg->GetPositionX() + varg->GetEntityWidth()) / 66; j++) {

			if (map.GetCellFromMap(i, j) == Cell::Type::Wall || map.GetCellFromMap(i, j) == Cell::Type::Enterence 
																	|| map.GetCellFromMap(i, j) == Cell::Type::Exit) {
				if (Dx > 0) { varg->SetPositionX(float(j * 66 - varg->GetEntityWidth())); varg->SetDx(0); varg->SetDirection("Left"); }
				if (Dx < 0) { varg->SetPositionX(float(j * 66 + 66)); varg->SetDx(0); varg->SetDirection("Right"); }
			}

		}
	}
}

EnemyVargControl::~EnemyVargControl()
{
	if(varg) delete varg;
}

// down = 0		 up = 1		left = 2	right = 3
