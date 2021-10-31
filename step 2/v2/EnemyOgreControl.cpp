#include "EnemyOgreControl.h"

EnemyOgreControl::EnemyOgreControl(EnemyOgre* Ogre) : ogre(Ogre) {

}

void EnemyOgreControl::MovingUpdate(Map& map, float time)
{
	if (ogre->GetDirection() == "Down") { ogre->SetDx(0); ogre->SetDy(ogre->GetSpeed()); }
	if (ogre->GetDirection() == "Up") { ogre->SetDx(0); ogre->SetDy(-ogre->GetSpeed()); }

	ogre->SetPositionX(ogre->GetPositionX() + float(ogre->GetDx() * time));
	ogre->SetPositionY(ogre->GetPositionY() + float(ogre->GetDy() * time));
	ogre->SetSpeed(0);

	InteractionWithMap(map, ogre->GetDx(), ogre->GetDy());
}

void EnemyOgreControl::InteractionWithMap(Map& map, double Dx, double Dy)
{
	for (int i = int(ogre->GetPositionY() / 66); i < (ogre->GetPositionY() + ogre->GetEntityHeight()) / 66; i++) {
		for (int j = int(ogre->GetPositionX() / 66); j < (ogre->GetPositionX() + ogre->GetEntityWidth()) / 66; j++) {

			if (map.GetCellFromMap(i, j) == Cell::Type::Wall || map.GetCellFromMap(i, j) == Cell::Type::Enterence
				|| map.GetCellFromMap(i, j) == Cell::Type::Exit) {
				if (Dy > 0) { ogre->SetPositionY(float(i * 66 - ogre->GetEntityHeight())); ogre->SetDy(0); ogre->SetDirection("Up");}
				if (Dy < 0) { ogre->SetPositionY(float(i * 66 + 66)); ogre->SetDy(0); ogre->SetDirection("Down");}
			}

		}
	}
}

EnemyOgreControl::~EnemyOgreControl()
{
	if(ogre) delete ogre;
}
