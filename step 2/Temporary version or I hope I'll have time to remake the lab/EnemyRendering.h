#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "iControlObject.h"
#include "Map.h"

class EnemyRendering : public Enemy, public iControlObject {
private:
	std::string VargImagePNG;
	sf::Texture VargTexture;
	sf::Sprite VargSprite;

	float CurrentFrame;

public:
	EnemyRendering(std::string PathToSprite, std::string name, int X, int Y, float PosX, float PosY, int health);

	void SetTexture();

	void MovingUpdate(Map& map, float time) override;
	void InteractionWithMap(Map& map, double dx, double dy) override;

	void SetDrawSprite(sf::RenderWindow& window);
	
	void MovingControl(float time);
	/*
	void Control();
	void InteractionWithMap2(Map& map, double Dx, double Dy);

	void CheckPlayer(Map& map, Player& player);
	void Attack(Map& map, Player& player);
	void Attack2(Map& map, Player& player, float dx, float dy);
	void UpdateAttack(Map& map, Player& player);*/
};