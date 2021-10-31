#pragma once

#include "Food.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class FoodRendering {
private:
	std::string AppleImagePNG;
	sf::Texture AppleTexture;
	sf::Sprite AppleSprite;

	Food* apple;

public:
	FoodRendering(std::string PathToSprite, Food* apple);

	void SetTexture();
	void SetDrawSprite(sf::RenderWindow& window);

};
