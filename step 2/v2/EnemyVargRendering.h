#pragma once
#include "EnemyVarg.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class EnemyVargRendering {
private:
	std::string VargImagePNG;
	sf::Texture VargTexture;
	sf::Sprite VargSprite;

	EnemyVarg* varg;

	float CurrentFrame;
public:
	EnemyVargRendering(std::string PathToSprite, EnemyVarg* varg);

	void SetTexture();
	void KeyControl(float time);
	void SetPosition();
	void SetDrawSprite(sf::RenderWindow& window);
	
};