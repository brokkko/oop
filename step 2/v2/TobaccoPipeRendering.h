#pragma once
#include "TobaccoPipe.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class TobaccoPipeRendering {
private:
	std::string PipeImagePNG;
	sf::Texture PipeTexture;
	sf::Sprite PipeSprite;

	TobaccoPipe* pipe;

public:
	TobaccoPipeRendering(std::string PathToSprite, TobaccoPipe* Pipe);

	void SetTexture();
	void SetDrawSprite(sf::RenderWindow& window);

};