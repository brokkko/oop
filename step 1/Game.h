#pragma once
#include "Map.h"
#include <iostream>

class Game {
private:
	std::string WallPNG;
	std::string GroundPNG; 
	std::string GrassPNG;
	int SpriteWidth;
	int SpriteHeight;

	sf::Image wall_image;
	sf::Texture wall_texture;
	sf::Sprite WallMap;

	sf::Image ground_image;
	sf::Texture ground_texture;
	sf::Sprite GroundMap;

	sf::Image grass_image;
	sf::Texture grass_texture;
	sf::Sprite GrassMap;

public:
	Game();
	void SetSprites();
	void Display();
};