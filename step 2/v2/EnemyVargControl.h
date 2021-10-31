#pragma once
#include "iControlObject.h"
#include "EnemyVarg.h"

class EnemyVargControl : public iControlObject{
private:
	EnemyVarg* varg;

public:
	EnemyVargControl(EnemyVarg* Varg);

	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;

	~EnemyVargControl();
};
