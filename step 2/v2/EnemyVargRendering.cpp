#include "EnemyVargRendering.h"

EnemyVargRendering::EnemyVargRendering(std::string PathToSprite, EnemyVarg* Varg) : VargImagePNG(PathToSprite), varg(Varg)
{
	varg->SetDirection("Right");
	CurrentFrame = 0;
	SetTexture();
}

void EnemyVargRendering::SetTexture() {
	VargTexture.loadFromFile(VargImagePNG);
	VargSprite.setTexture(VargTexture);

	VargSprite.setTextureRect(sf::IntRect(0, 188, 88, 47));
	VargSprite.setScale(1.5, 1.5);
	varg->SetEntityHeight(varg->GetEntityHeight() * 1.5);
	varg->SetEntityWidth(varg->GetEntityWidth() * 1.5);
	VargSprite.setPosition(varg->GetPositionX(), varg->GetPositionY());
}

void EnemyVargRendering::KeyControl(float time) {
	if (varg->GetDirection() == "Left") {
		varg->SetSpeed(0.1);
		varg->SetDirection("Left");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 5) CurrentFrame -= 5;
		VargSprite.setTextureRect(sf::IntRect(90 * int(CurrentFrame), 240, 88, 47));
	}
	if (varg->GetDirection() == "Right") {
		varg->SetSpeed(0.1);
		varg->SetDirection("Right");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 5) CurrentFrame -= 5;
		VargSprite.setTextureRect(sf::IntRect(90 * int(CurrentFrame), 188, 88, 47));
	}
}

void EnemyVargRendering::SetPosition() {
	VargSprite.setPosition(varg->GetPositionX(), varg->GetPositionY());
}

void EnemyVargRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(VargSprite);
}