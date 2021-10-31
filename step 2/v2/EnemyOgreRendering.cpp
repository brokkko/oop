#include "EnemyOgreRendering.h"

EnemyOgreRendering::EnemyOgreRendering(std::string PathToSprite, EnemyOgre* Ogre) : OgreImagePNG(PathToSprite), ogre(Ogre)
{
	ogre->SetDirection("Up");
	CurrentFrame = 0;
	SetTexture();
}

void EnemyOgreRendering::SetTexture() {
	OgreTexture.loadFromFile(OgreImagePNG);
	OgreSprite.setTexture(OgreTexture);

	OgreSprite.setTextureRect(sf::IntRect(0, 188, 88, 47));
	OgreSprite.setScale(0.6, 0.6);
	ogre->SetEntityHeight(ogre->GetEntityHeight() * 0.6);
	ogre->SetEntityWidth(ogre->GetEntityWidth() * 0.6);
	OgreSprite.setPosition(ogre->GetPositionX(), ogre->GetPositionY());
}

void EnemyOgreRendering::KeyControl(float time) {
	if (ogre->GetDirection() == "Up") {
		ogre->SetSpeed(0.08);
		ogre->SetDirection("Up");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		OgreSprite.setTextureRect(sf::IntRect(107 * int(CurrentFrame), 433, 107, 145));
	}
	if (ogre->GetDirection() == "Down") {
		ogre->SetSpeed(0.08);
		ogre->SetDirection("Down");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		OgreSprite.setTextureRect(sf::IntRect(107 * int(CurrentFrame), 0, 107, 145));
	}
}

void EnemyOgreRendering::SetPosition() {
	OgreSprite.setPosition(ogre->GetPositionX(), ogre->GetPositionY());
}

void EnemyOgreRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(OgreSprite);
}