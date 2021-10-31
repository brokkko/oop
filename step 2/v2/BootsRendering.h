#pragma once
#include "Boots.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class BootsRendering {
private:
	std::string BootsImagePNG;
	sf::Texture BootsTexture;
	sf::Sprite BootsSprite;

	Boots* boots;

public:
	BootsRendering(std::string PathToSprite, Boots* boots);

	void SetTexture();
	void SetDrawSprite(sf::RenderWindow& window);

};