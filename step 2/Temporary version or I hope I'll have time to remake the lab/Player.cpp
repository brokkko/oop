#include "Player.h"
#include <iostream>

Player::Player(std::string name, int H, int W, float PosX, float PosY, int Health) : Entity(name, H, W, PosX, PosY, Health)
{
	Fullness = 0;
	Score = 0;
}

void Player::SetFullness(int value) { Fullness += value; }

int Player::GetFullness() { return Fullness; }

void Player::SetScore(int value) { Score += value; }

int Player::GetScore() { return Score; }

