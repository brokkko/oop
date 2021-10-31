#pragma once
#include "iControlObject.h"
#include "EnemyWizard.h"

class EnemyWizardControl : public iControlObject {
private:
	EnemyWizard* wizard;

public:
	EnemyWizardControl(EnemyWizard* Wizard);

	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;

	~EnemyWizardControl();
};
