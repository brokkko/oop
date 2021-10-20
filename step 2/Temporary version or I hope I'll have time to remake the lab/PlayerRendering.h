#pragma once
#pragma once
#include "Player.h"
#include "Map.h"
#include "iControlObject.h"
#include <iostream>
//#include "PlayerControl.h"

class PlayerRendering : public iControlObject, public Player {
private:
	std::string PlayerImagePNG;
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	float CurrentFrame; // счётчик кадров

	//int CellHeight, CellWidth;
	int CheckHat, CheckWidth;


public:
	//PlayerView(float X, float Y, int Height, int Width, std::string name, int health);
	PlayerRendering(std::string PathToSprite, std::string name, float PosX, float PosY, int H, int W, int Health);

	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;

	void SetTexture();
	void KeyControl(float time);
	void SetDrawSprite(sf::RenderWindow& window);

};
