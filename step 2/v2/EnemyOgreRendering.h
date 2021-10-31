#pragma once
#include "EnemyOgre.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class EnemyOgreRendering {
private:
	std::string OgreImagePNG;
	sf::Texture OgreTexture;
	sf::Sprite OgreSprite;

	EnemyOgre* ogre;

	float CurrentFrame;
public:
	EnemyOgreRendering(std::string PathToSprite, EnemyOgre* Ogre);

	void SetTexture();
	void KeyControl(float time);
	void SetPosition();
	void SetDrawSprite(sf::RenderWindow& window);

};
