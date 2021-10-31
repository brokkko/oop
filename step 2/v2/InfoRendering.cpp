#include "InfoRendering.h"

InfoRendering::InfoRendering()
{
    font.loadFromFile("C:/Visual Code/sfmlProject/sources/CyrilicOld.ttf");
    text = new sf::Text("", font, 25);
    text->setFillColor(sf::Color(0, 0, 0));
    text->setStyle(sf::Text::Bold);

    health_text = new sf::Text("", font, 15);
    health_text->setFillColor(sf::Color::Black);
    health_text->setStyle(sf::Text::Bold);
}

void InfoRendering::ShowHealth(Player& player, sf::RenderWindow& win){
    std::ostringstream player_health;

    int health = player.GetHealth();

    player_health << health;

    text->setString("Health: " + player_health.str());
    health_text->setString("hp " + player_health.str());

    text->setPosition(10, 10);
    health_text->setPosition(player.GetPositionX() - player.GetEntityWidth() / 4, player.GetPositionY() - player.GetEntityHeight() / 2);
    win.draw(*text);
    win.draw(*health_text);
}

void InfoRendering::AfterAll(sf::RenderWindow& win)
{
    Texture.loadFromFile("C:/Visual Code/sfmlProject/sources/TheEnd.png");
    Sprite.setTexture(Texture);
    Sprite.setTextureRect(sf::IntRect(0, 0, 465, 334));
    Sprite.setPosition(1*66, 1*66);

    win.draw(Sprite);
}

void InfoRendering::Update(Player& player, sf::RenderWindow& win) {
    ShowHealth(player, win);
}