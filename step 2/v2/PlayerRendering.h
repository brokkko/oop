#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class PlayerRendering {
private:
	std::string PlayerImagePNG;
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	float CurrentFrame; // счётчик кадров

	Player* player;


public:
	PlayerRendering(std::string PathToSprite, Player *player);

	void SetTexture();
	void KeyControl(float time);
	void SetPosition();
	void SetDrawSprite(sf::RenderWindow& window);

};
