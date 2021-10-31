#pragma once
#include "iControlObject.h"
#include "EnemyOgre.h"

class EnemyOgreControl : public iControlObject {
private:
	EnemyOgre* ogre;

public:
	EnemyOgreControl(EnemyOgre* Ogre);

	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;

	~EnemyOgreControl();
};