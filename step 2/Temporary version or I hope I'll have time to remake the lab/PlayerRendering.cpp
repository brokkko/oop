#include "PlayerRendering.h"

PlayerRendering::PlayerRendering(std::string PathToSprite, std::string name, float PosX, float PosY, int H, int W, int Health) :
															Player(name, H, W, PosX, PosY, Health), PlayerImagePNG(PathToSprite)
{
	CheckHat = 30;
	CheckWidth = 10;
	CurrentFrame = 0;
	SetTexture();
}

void PlayerRendering::SetTexture() {
	PlayerTexture.loadFromFile(PlayerImagePNG);
	PlayerSprite.setTexture(PlayerTexture);

	PlayerSprite.setTextureRect(sf::IntRect(60, 0, 60, 85));
	PlayerSprite.setPosition(PositionX , PositionY );
}

void PlayerRendering::KeyControl(float time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		speed = 0.1;

		Direction = "Left";
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 185, 60, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		speed = 0.1;
		Direction = "Right";
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 90, 60, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		speed = 0.1;
		Direction = "Up";
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 280, 60, 85));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		speed = 0.1;
		Direction = "Down";
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		PlayerSprite.setTextureRect(sf::IntRect(60 * int(CurrentFrame), 0, 60, 85));
	}
}

void PlayerRendering::MovingUpdate(Map& map, float time)
{
	KeyControl(time);
	if (Direction == "Right") { dx = speed; dy = 0; }
	if (Direction == "Left") { dx = -speed; dy = 0; }
	if (Direction == "Down") { dx = 0; dy = speed; }
	if (Direction == "Up") { dx = 0; dy = -speed; }

	PositionX += float(dx * time); //dx = 0;
	PositionY += float(dy * time); //dy = 0;
	speed = 0;

	InteractionWithMap(map, dx, dy);

	PlayerSprite.setPosition(PositionX, PositionY);

	if (Health <= 0) Life = false;
}

void PlayerRendering::InteractionWithMap(Map& map, double Dx, double Dy)
{
	for (int i = int((PositionY + CheckHat) / 66); i < (PositionY + EntityHeight) / 66; i++) {
		for (int j = int((PositionX + CheckWidth) / 66); j < (PositionX + EntityWidth) / 66; j++) {
			if (Dx < 0 && PositionX < 10) {
				PositionX = float(j * 66 + 10);
				dx = 0;
			}
			if (Dx>0 && PositionX > map.GetMapWidth() * 66 - 50) {
				PositionX = float(j * 66 - 10);
				dx = 0;
			}
			if(map.GetCellFromMap(i, j) == Cell::Type::Wall){
				if (Dy > 0) { PositionY = float(i * 66 - EntityHeight); dy = 0; }			 // down
				if (Dy < 0) { PositionY = float(i * 66 + 66 - CheckHat); dy = 0; }   // up
				if (Dx > 0) { PositionX = float(j * 66 - EntityWidth); dx = 0; }             // right
				if (Dx < 0) { PositionX = float(j * 66 + 66 - CheckWidth); dx = 0; } // left
			}

		}
	}
}

void PlayerRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(PlayerSprite);
}
