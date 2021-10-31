#include "EnemyWizardRendering.h"

EnemyWizardRendering::EnemyWizardRendering(std::string PathToSprite, EnemyWizard* Wizard) : WizardImagePNG(PathToSprite), wizard(Wizard)
{
	wizard->SetDirection("Right");
	CurrentFrame = 0;
	SetTexture();
}

void EnemyWizardRendering::SetTexture() {
	WizardTexture.loadFromFile(WizardImagePNG);
	WizardSprite.setTexture(WizardTexture);

	WizardSprite.setTextureRect(sf::IntRect(0, 348, 105, 148));
	WizardSprite.setScale(0.5, 0.5);
	//wizard->SetEntityHeight(wizard->GetEntityHeight() * 0.5);
	//wizard->SetEntityWidth(wizard->GetEntityWidth() * 0.5);
	WizardSprite.setPosition(wizard->GetPositionX(), wizard->GetPositionY());
}

void EnemyWizardRendering::KeyControl(float time) {
	if (wizard->GetDirection() == "Left") {
		wizard->SetSpeed(0.1);
		wizard->SetDirection("Left");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 8) CurrentFrame -= 8;
		WizardSprite.setTextureRect(sf::IntRect(109 * int(CurrentFrame), 182, 104, 150));
	}
	if (wizard->GetDirection() == "Right") {
		wizard->SetSpeed(0.1);
		wizard->SetDirection("Right");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 8) CurrentFrame -= 8;
		WizardSprite.setTextureRect(sf::IntRect(109 * int(CurrentFrame), 342, 104, 150));
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		varg->SetSpeed(0.1);
		varg->SetDirection("Up");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		VargSprite.setTextureRect(sf::IntRect(41 * int(CurrentFrame), 100, 41, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		varg->SetSpeed(0.1);
		varg->SetDirection("Down");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		VargSprite.setTextureRect(sf::IntRect(41 * int(CurrentFrame), 0, 41, 95));
	}*/
}

void EnemyWizardRendering::SetPosition() {
	WizardSprite.setPosition(wizard->GetPositionX(), wizard->GetPositionY());
}

void EnemyWizardRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(WizardSprite);
}