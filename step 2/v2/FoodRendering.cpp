#include "FoodRendering.h"

FoodRendering::FoodRendering(std::string PathToSprite, Food* Apple) : apple(Apple), AppleImagePNG(PathToSprite)
{
	SetTexture();
}

void FoodRendering::SetTexture()
{
	AppleTexture.loadFromFile(AppleImagePNG);
	AppleSprite.setTexture(AppleTexture);
	AppleSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
	AppleSprite.setPosition(apple->GetPositionX() * 66 + 25 , apple->GetPositionY() * 66 + 25);
}

void FoodRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(AppleSprite);
}
