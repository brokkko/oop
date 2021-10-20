#include "EnemyRendering.h"

EnemyRendering::EnemyRendering(std::string Path, std::string name, int H, int W, float PosX, float PosY, int health) : Enemy(name, H, W, PosX, PosY, health), VargImagePNG(Path)
{
	CurrentFrame = 0;
	SetTexture();
	Direction = "Right";
	
}

void EnemyRendering::SetTexture() {
	VargTexture.loadFromFile(VargImagePNG);
	VargSprite.setTexture(VargTexture);

	VargSprite.setTextureRect(sf::IntRect(0, 188, 88, 47));
	VargSprite.setScale(1.5, 1.5);
	EntityHeight = EntityHeight * 1.5;
	EntityWidth = EntityWidth * 1.;
	VargSprite.setPosition(PositionX, PositionY);
}


void EnemyRendering::MovingControl(float time) {
	if (Direction == "Right") {
		speed = 0.1;
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 5) CurrentFrame -= 5;
		VargSprite.setTextureRect(sf::IntRect(90 * int(CurrentFrame), 188, 88, 47));
	}
	if (Direction == "Left") {
		speed = 0.1;
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 5) CurrentFrame -= 5;
		VargSprite.setTextureRect(sf::IntRect(90 * int(CurrentFrame), 240, 88, 47));
	}
	if (Direction == "Up") {
		speed = 0.1;
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		VargSprite.setTextureRect(sf::IntRect(41 * int(CurrentFrame), 100, 41, 85));
	}
	if (Direction == "Down") {
		speed = 0.1;
		CurrentFrame += float(0.005 * time);
		if (CurrentFrame > 4) CurrentFrame -= 4;
		VargSprite.setTextureRect(sf::IntRect(41 * int(CurrentFrame), 0, 41, 95));
	}

}

void EnemyRendering::InteractionWithMap(Map& map, double Dx, double Dy)
{
	if (Direction == "Right" || Direction == "Left") {
		EntityHeight = 1.5 * 47; EntityWidth = 1.5 * 88;
	}
	/*if (Direction == "Up" || Direction == "Down") {
		EntityHeight = 1.5 * 41; EntityWidth = 1.5 * 95;
	}*/

	for (int i = int((PositionY) / 66); i < (PositionY + EntityHeight) / 66; i++) {
		for (int j = int(PositionX / 66); j < (PositionX + EntityWidth) / 66; j++) {

			if(map.GetCellFromMap(i, j) == Cell::Type::Wall) {
				if (Dy > 0) { PositionY = float(i * 66 - EntityHeight); dy = 0; Direction = "Up"; }
				if (Dy < 0) { PositionY = float(i * 66 + 66); dy = 0; Direction = "Down"; }
				if (Dx > 0) { PositionX = float(j * 66 - EntityWidth); dx = 0; Direction = "Left"; }
				if (Dx < 0) { PositionX = float(j * 66 + 66); dx = 0; Direction = "Right"; }
			}

		}
	}
}

void EnemyRendering::MovingUpdate(Map& map, float time) {

	MovingControl(time);

	if (Direction == "Right") { dx = speed; dy = 0; }
	if (Direction == "Left") { dx = -speed; dy = 0; }
	if (Direction == "Down") { dx = 0; dy = speed; }
	if (Direction == "Up") { dx = 0; dy = -speed; }

	PositionX += float(dx * time); //dx = 0;
	PositionY += float(dy * time); //dy = 0;
	speed = 0;
	InteractionWithMap(map, dx, dy);
	VargSprite.setPosition(PositionX, PositionY);

		//map.SetObject((int)(PositionY / 66), (int)(PositionX / 66), "Varg");
	//if (Life <= 0) Life = false;	
}

void EnemyRendering::SetDrawSprite(sf::RenderWindow& window) {
	window.draw(VargSprite);
}