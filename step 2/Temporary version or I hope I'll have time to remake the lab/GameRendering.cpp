#include "GameRendering.h"

GameRendering::GameRendering(){
	CreateMap = new MapSetting("C:/Visual Code/sfmlProject/Maps/lvl1.txt");
	map = new Map(*CreateMap);
	MapRender = new MapRendering("C:/Visual Code/sfmlProject/sources/try66.png", "C:/Visual Code/sfmlProject/sources/ground66.png", 66, 66);
    player = new PlayerRendering("C:/Visual Code/sfmlProject/sources/hobbitsSprites_.png", "Player", map->GetEnterenceX()*66, map->GetEnterenceY()*66, 85, 60, 100);
    //enemy = new EnemyRendering("C:/Visual Code/sfmlProject/sources/Vargs2.png", "Varg", 47, 88, 15 * 66, 12 * 66, 30);
}

float GameRendering::SetTime() {
    time = float(clock.getElapsedTime().asMicroseconds());
    clock.restart();
    time = time / 800; 
    return time;
}

void GameRendering::Display() {

    std::list<EnemyRendering*> Enemies;
    std::list<EnemyRendering*>::iterator it;

    int k = 1;
    for (int i = 0; i < 7; i++) {
        Enemies.push_back(new EnemyRendering("C:/Visual Code/sfmlProject/sources/Vargs2.png", "Varg", 47, 88, (15+k) * 66, (12)* 66, 30));
        //Entity a = (*it)->GetEntity();
        //a.Print();
        k+=2;
    }
    
    
    sf::RenderWindow window(sf::VideoMode(29 * 66, 14 * 66), "Hobbit", sf::Style::Fullscreen);

    
    
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

        time = SetTime();
        player->MovingUpdate(*map, time);

        for (it = Enemies.begin(); it != Enemies.end(); it++)
            (*it)->MovingUpdate(*map, time);
        
        //enemy->MovingUpdate(*map, time);

        window.clear();

        for (int i = 0; i < map->GetMapHeight(); i++) {
            for (int j = 0; j < map->GetMapWidth(); j++) {
                if (map->GetCellFromMap(i, j) == Cell::Type::Wall) {
                    MapRender->SetPositionOfWall(i, j);
                    MapRender->SetDrawSpriteOfWall(window);
                }

                if (map->GetCellFromMap(i, j) == Cell::Type::Ground || map->GetCellFromMap(i, j) == Cell::Type::Enterence
                        || map->GetCellFromMap(i, j) == Cell::Type::Exit) {
                    MapRender->SetPositionOfGround(i, j);
                    MapRender->SetDrawSpriteOfGround(window);
                }
            }
        }
        
        player->SetDrawSprite(window);
       // enemy->SetDrawSprite(window);
        for (it = Enemies.begin(); it != Enemies.end(); it++) 
            (*it)->SetDrawSprite(window);

        
        window.display();

    }
}

GameRendering::~GameRendering()
{
    delete map;
    delete MapRender;
    delete player;
    //delete enemy;
}
