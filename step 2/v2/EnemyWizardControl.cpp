#include "EnemyWizardControl.h"

EnemyWizardControl::EnemyWizardControl(EnemyWizard* Wizard) : wizard(Wizard) {

}

void EnemyWizardControl::MovingUpdate(Map& map, float time)
{
	if (wizard->GetDirection() == "Right") { wizard->SetDx(wizard->GetSpeed()); wizard->SetDy(0); }
	if (wizard->GetDirection() == "Left") { wizard->SetDx(-wizard->GetSpeed()); wizard->SetDy(0); }
	if (wizard->GetDirection() == "Down") { wizard->SetDx(0); wizard->SetDy(wizard->GetSpeed()); }
	if (wizard->GetDirection() == "Up") { wizard->SetDx(0); wizard->SetDy(-wizard->GetSpeed()); }

	wizard->SetPositionX(wizard->GetPositionX() + float(wizard->GetDx() * time));
	wizard->SetPositionY(wizard->GetPositionY() + float(wizard->GetDy() * time));
	wizard->SetSpeed(0);

	InteractionWithMap(map, wizard->GetDx(), wizard->GetDy());

	//map.RemoveObject(wizard->GetPositionX() / 66, wizard->GetPositionY() / 66);
	//map.SetObjectToCell(wizard, wizard->GetPositionX()/66, wizard->GetPositionY()/66);
	// map[wizard->GetPositionX()/66][wizard->GetPositionY()/66].SetObject(wizard);
}

void EnemyWizardControl::InteractionWithMap(Map& map, double Dx, double Dy)
{
	for (int i = int(wizard->GetPositionY() / 66); i < (wizard->GetPositionY() + wizard->GetEntityHeight()) / 66; i++) {
		for (int j = int(wizard->GetPositionX() / 66); j < (wizard->GetPositionX() + wizard->GetEntityWidth()) / 66; j++) {

			if (map.GetCellFromMap(i, j) == Cell::Type::Wall || map.GetCellFromMap(i, j) == Cell::Type::Enterence
				|| map.GetCellFromMap(i, j) == Cell::Type::Exit) {
				if (Dx > 0) { wizard->SetPositionX(float(j * 66 - wizard->GetEntityWidth())); wizard->SetDx(0); wizard->SetDirection("Left"); }
				if (Dx < 0) { wizard->SetPositionX(float(j * 66 + 66)); wizard->SetDx(0); wizard->SetDirection("Right"); }
			}

		}
	}
}

EnemyWizardControl::~EnemyWizardControl()
{
	if(wizard) delete wizard;
}
