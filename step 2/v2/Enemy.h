#pragma once
#include "Entity.h"
#include "Map.h"

class Enemy : public Entity {
protected:
	int Damage;
public:
	Enemy(std::string name, int H, int W, int health);

	virtual void Generation(Map& map) = 0;

	void SetDamage(int val);
	int GetDamage();

};