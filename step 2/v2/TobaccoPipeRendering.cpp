#include "TobaccoPipeRendering.h"

TobaccoPipeRendering::TobaccoPipeRendering(std::string PathToSprite, TobaccoPipe* Pipe) : pipe(Pipe), PipeImagePNG(PathToSprite)
{
	SetTexture();
}

void TobaccoPipeRendering::SetTexture()
{
	PipeTexture.loadFromFile(PipeImagePNG);
	PipeSprite.setTexture(PipeTexture);
	PipeSprite.setTextureRect(sf::IntRect(0, 0, 464, 372));
	PipeSprite.setScale(0.1, 0.1);
	PipeSprite.setPosition(pipe->GetPositionX() * 66 + 25, pipe->GetPositionY() * 66 + 25);
}

void TobaccoPipeRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(PipeSprite);
}