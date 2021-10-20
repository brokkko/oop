#include "MapRendering.h"

MapRendering::MapRendering(std::string WallPNGPath, std::string GroundPNGPath, int H, int W) : WallPNG(WallPNGPath), 
                                GroundPNG(GroundPNGPath), SpriteHeight(H), SpriteWidth(W)
{
    SetSpriteOfGround();
    SetSpriteOfWall();
}

void MapRendering::SetSpriteOfGround()
{
    GroundImage.loadFromFile(GroundPNG);
    GroundTexture.loadFromImage(GroundImage);
    GroundMap.setTexture(GroundTexture);

}

void MapRendering::SetPositionOfGround(int X, int Y) 
{
    GroundMap.setTextureRect(sf::IntRect(0, 0, SpriteWidth, SpriteHeight));
    GroundMap.setPosition(float(Y) * SpriteWidth, float(X) * SpriteHeight);
}

void MapRendering::SetSpriteOfWall()
{
    WallImage.loadFromFile(WallPNG);
    WallTexture.loadFromImage(WallImage);
    WallMap.setTexture(WallTexture);

}

void MapRendering::SetPositionOfWall(int X, int Y) 
{
    WallMap.setTextureRect(sf::IntRect(0, 0, SpriteWidth, SpriteHeight));
    WallMap.setPosition(float(Y) * SpriteWidth, float(X) * SpriteHeight);
}

void MapRendering::SetDrawSpriteOfGround(sf::RenderWindow& window) 
{
    window.draw(GroundMap);
}

void MapRendering::SetDrawSpriteOfWall(sf::RenderWindow& window) 
{
    window.draw(WallMap);
}

