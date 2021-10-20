#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class MapRendering {
private:
	std::string WallPNG;
	std::string GroundPNG;

	sf::Image WallImage;
	sf::Texture WallTexture;
	sf::Sprite WallMap;

	sf::Image GroundImage;
	sf::Texture GroundTexture;
	sf::Sprite GroundMap;

	int SpriteHeight, SpriteWidth;

public:
	MapRendering(std::string WallPNGPath, std::string GroundPNGPath, int H, int W);

	void SetSpriteOfGround();
	void SetSpriteOfWall();
	void SetPositionOfGround(int X, int Y);
	void SetPositionOfWall(int X, int Y);

	void SetDrawSpriteOfGround(sf::RenderWindow& window);
	void SetDrawSpriteOfWall(sf::RenderWindow& window);
};