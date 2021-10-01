#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

Game::Game() : WallPNG("C:/Visual Code/sfmlProject/sources/wall1.png"), GroundPNG("C:/Visual Code/sfmlProject/sources/ground1.png"),
               GrassPNG("C:/Visual Code/sfmlProject/sources/grass.png"), SpriteHeight(58), SpriteWidth(58){
    Display();
}

void Game::SetSprites() {

    wall_image.loadFromFile(WallPNG);
    wall_texture.loadFromImage(wall_image);
    WallMap.setTexture(wall_texture);

    ground_image.loadFromFile(GroundPNG);
    ground_texture.loadFromImage(ground_image);
    GroundMap.setTexture(ground_texture);

    grass_image.loadFromFile(GrassPNG);
    grass_texture.loadFromImage(grass_image);
    GrassMap.setTexture(grass_texture);

}

void Game::Display() {

    Map map;
    map.CreateMap();
    //map.CreateStatus();

    sf::RenderWindow window(sf::VideoMode(1160, 696), "Game");

    SetSprites();

    while (window.isOpen())
    {
        sf::Event event;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < map.GetHeight(); i++) {
            for (int j = 0; j < map.GetWidth(); j++) {
                if (map.GetCellFromMap(i, j) == '0') {
                    WallMap.setTextureRect(sf::IntRect(0, 0, SpriteWidth, SpriteHeight));
                    WallMap.setPosition(float(j) * SpriteWidth, float(i) * SpriteHeight);
                    window.draw(WallMap);
                }
                if (map.GetCellFromMap(i, j) == 'o' || map.GetCellFromMap(i, j) == 'i') {
                    GroundMap.setTextureRect(sf::IntRect(0, 0, SpriteWidth, SpriteHeight));
                    GroundMap.setPosition(float(j) * SpriteWidth, float(i) * SpriteHeight);
                    window.draw(GroundMap);
                }
                if (map.GetCellFromMap(i, j) == '1') {
                    GrassMap.setTextureRect(sf::IntRect(0, 0, SpriteWidth, SpriteHeight));
                    GrassMap.setPosition(float(j) * SpriteWidth, float(i) * SpriteHeight);
                    window.draw(GrassMap);
                }
            }
        }

        window.display();

    }

}
