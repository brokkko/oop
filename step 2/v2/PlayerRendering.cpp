#include "PlayerRendering.h"

PlayerRendering::PlayerRendering(std::string PathToSprite, Player *Player) :
															PlayerImagePNG(PathToSprite), player(Player)
{
	
	CurrentFrame = 0;
	SetTexture();
}

void PlayerRendering::SetTexture() {
	PlayerTexture.loadFromFile(PlayerImagePNG);
	PlayerSprite.setTexture(PlayerTexture);

	PlayerSprite.setTextureRect(sf::IntRect(60, 0, 60, 85));
	PlayerSprite.setPosition(player->GetPositionX() , player->GetPositionY() );
}

void PlayerRendering::KeyControl(float time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player->SetSpeed(player->GetSpeedControl());
		player->SetDirection("Left");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 185, 60, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->SetSpeed(player->GetSpeedControl());
		player->SetDirection("Right");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 90, 60, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->SetSpeed(player->GetSpeedControl());
		player->SetDirection("Up");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 280, 60, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player->SetSpeed(player->GetSpeedControl());
		player->SetDirection("Down");
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 0, 60, 85));
	}
}

void PlayerRendering::SetPosition() {
	PlayerSprite.setPosition(player->GetPositionX(), player->GetPositionY());
}



void PlayerRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(PlayerSprite);
}
