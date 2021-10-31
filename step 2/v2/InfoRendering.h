#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Player.h"

class InfoRendering {
private:
	sf::Font font;
	sf::Text* text;
	sf::Text* health_text;

	sf::Texture Texture;
	sf::Sprite Sprite;

public:
	InfoRendering();

	void Update(Player& player, sf::RenderWindow& win);
	void ShowHealth(Player& player, sf::RenderWindow& win);
	void AfterAll(sf::RenderWindow& win);
};