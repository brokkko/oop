#pragma once
#include <iostream>

class Entity {
protected:
	double dx, dy, speed;
	float PositionX, PositionY;
	int EntityWidth, EntityHeight;

	int Health;
	bool Life;

	std::string Name;			// typyid dinamic cast
	std::string Direction;		// enum

public:

	Entity(std::string name, int H, int W, int Health);

	//virtual void MovingUpdate(Map& map, float time) = 0;

	Entity GetEntity();
	bool GetLife();

	double GetDx();
	double GetDy();
	double GetSpeed();
	float GetPositionX();
	float GetPositionY();
	int GetEntityWidth();
	int GetEntityHeight();
	int GetHealth();
	std::string GetDirection();
	std::string GetName();

	void SetDx(double val);
	void SetDy(double val);
	void SetSpeed(double val);
	void SetPositionX(float X);
	void SetPositionY(float Y);
	void SetEntityWidth(int W);
	void SetEntityHeight(int H);
	void SetDirection(std::string dir);
	//void SetName(std::string name);
	void SetHealth(int val);
	void SetLife(bool val);
};