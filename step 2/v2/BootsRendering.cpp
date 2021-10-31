#include "BootsRendering.h"

BootsRendering::BootsRendering(std::string PathToSprite, Boots* Boots) : boots(Boots), BootsImagePNG(PathToSprite)
{
	SetTexture();
}

void BootsRendering::SetTexture()
{
	BootsTexture.loadFromFile(BootsImagePNG);
	BootsSprite.setTexture(BootsTexture);
	BootsSprite.setTextureRect(sf::IntRect(0, 0, 510, 380));
	BootsSprite.setScale(0.1, 0.1);
	BootsSprite.setPosition(boots->GetPositionX() * 66 + 25, boots->GetPositionY() * 66 + 25);
}

void BootsRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(BootsSprite);
}