#pragma once
#include "EnemyWizard.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class EnemyWizardRendering {
private:
	std::string WizardImagePNG;
	sf::Texture WizardTexture;
	sf::Sprite WizardSprite;

	EnemyWizard* wizard;

	float CurrentFrame;
public:
	EnemyWizardRendering(std::string PathToSprite, EnemyWizard* varg);

	void SetTexture();
	void KeyControl(float time);
	void SetPosition();
	void SetDrawSprite(sf::RenderWindow& window);

};
