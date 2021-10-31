#include "GameRendering.h"

GameRendering::GameRendering(){

	CreateMap = new MapSetting("C:/Visual Code/sfmlProject/Maps/lvl1.txt");
	map = new Map(*CreateMap);
	MapRender = new MapRendering("C:/Visual Code/sfmlProject/sources/try66.png", "C:/Visual Code/sfmlProject/sources/ground66.png", 66, 66);
   
    player = new Player("Hobbit", 85, 60, float(map->GetEnterenceX() * 66), float(map->GetEnterenceY() * 66), 100);
    Varg = new EnemyVarg("Varg", 47, 88, 100, *map);
    wizard = new EnemyWizard("Wizard", int(150*0.5), int(104*0.5), 100, *map);
    ogre = new EnemyOgre("Ogre", int(145 * 0.6), int(107 * 0.6), 100, *map);

    apple = new Food("Apple", map);
    pipe = new TobaccoPipe("TobaccoPipe", map);
    boots = new Boots("Boots", map);

    info = new InfoRendering();
    battle = new Battle();
    pick = new PickUp();

    Initialization();
}

float GameRendering::SetTime() {
    time = float(clock.getElapsedTime().asMicroseconds());
    clock.restart();
    time = time / 800; 
    return time;
}

void GameRendering::Initialization()
{
    PControl = new PlayerControl(player);
    PRendering = new PlayerRendering("C:/Visual Code/sfmlProject/sources/hobbitsSprites_.png", player);

    VControl = new EnemyVargControl(Varg);
    VRendering = new EnemyVargRendering("C:/Visual Code/sfmlProject/sources/Vargs2.png", Varg);

    WControl = new EnemyWizardControl(wizard);
    WRendering = new EnemyWizardRendering("C:/Visual Code/sfmlProject/sources/wizard.png", wizard);

    OControl = new EnemyOgreControl(ogre);
    ORendering = new EnemyOgreRendering("C:/Visual Code/sfmlProject/sources/ogre.png", ogre);

    FRendering = new FoodRendering("C:/Visual Code/sfmlProject/sources/apple.png", apple);
    PipeRendering = new TobaccoPipeRendering("C:/Visual Code/sfmlProject/sources/TobaccoPipe.png", pipe);
    BootsRend = new BootsRendering("C:/Visual Code/sfmlProject/sources/boots2.png", boots);
}

void GameRendering::UpdatePosition(float time)
{
    if (player->GetLife() == true) {
        PRendering->KeyControl(time);
        PControl->MovingUpdate(*map, time);
        PRendering->SetPosition();
    }

    if (Varg->GetLife() == true) {
        VRendering->KeyControl(time);
        VControl->MovingUpdate(*map, time);
        VRendering->SetPosition();
    }

    if (wizard->GetLife() == true) {
        WRendering->KeyControl(time);
        WControl->MovingUpdate(*map, time);
        WRendering->SetPosition();
    }

    if (ogre->GetLife() == true) {
        ORendering->KeyControl(time);
        OControl->MovingUpdate(*map, time);
        ORendering->SetPosition();
    }
}

void GameRendering::Rendering(sf::RenderWindow& window)
{
    if (apple->GetState() == false) FRendering->SetDrawSprite(window);      
    if (pipe->GetState() == false) PipeRendering->SetDrawSprite(window);
    if (boots->GetState() == false) BootsRend->SetDrawSprite(window);

    if (player->GetLife() == true) PRendering->SetDrawSprite(window);

    if (Varg->GetLife() == true) VRendering->SetDrawSprite(window);
    if (wizard->GetLife() == true) WRendering->SetDrawSprite(window);
    if (ogre->GetLife() == true) ORendering->SetDrawSprite(window);

    if (player->GetLife() == true) info->Update(*player, window);

    if (player->GetLife() == false) {
        info->AfterAll(window);
    }
}

void GameRendering::Display() {

  
    Enemies.push_back(Varg);
    Enemies.push_back(wizard);
    Enemies.push_back(ogre);

    objects.push_back(apple);
    objects.push_back(boots);
    objects.push_back(pipe);
    
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
        UpdatePosition(time);
       
        for (it = Enemies.begin(); it != Enemies.end();) {
            if (abs(player->GetPositionX() - (*it)->GetPositionX()) <= 1 * 66 &&
                abs(player->GetPositionY() - (*it)->GetPositionY()) <= 1 * 66 && (*it)->GetLife() == true) {
                
                battle->AttackPlayer(*player, *it);

                if ((*it)->GetLife() == false) {
                    Enemy* DeadEnemy = *it;
                    it = Enemies.erase(it);
                    delete DeadEnemy;
                }
                else it++;
            }
            else it++;
        }
        
        for (itObj = objects.begin(); itObj != objects.end();) {
            if (abs(player->GetPositionX() - (*itObj)->GetPosX() * 66) <= (1 * 66 / 2) &&
                abs(player->GetPositionY() - (*itObj)->GetPosY() * 66) <= (1 * 66 / 2) && (*itObj)->GetState() == false) {

                pick->PickUpObject(*player, *itObj);
                iPickable* PickedObj = *itObj;
                itObj = objects.erase(itObj);
                delete PickedObj;

            }
            else itObj++;
        }
        
        if (map->GetCellFromMap(player->GetPositionY()/66, player->GetPositionX()/66) == Cell::Type::Exit) {
            player->SetLife(false);
        }

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
        Rendering(window);
        window.display();
    }
}

GameRendering::~GameRendering()
{
    for (it = Enemies.begin(); it != Enemies.end(); it++) { delete* it; (*it) = nullptr; }
    for (itObj = objects.begin(); itObj != objects.end(); itObj++) { delete* itObj; (*itObj) = nullptr; }

    delete map;
    delete MapRender;
    delete player;
    delete info;
    delete battle;
    delete pick;
    delete PRendering;
    delete VRendering;
    delete WRendering;
    delete ORendering;
    delete FRendering;
    delete PipeRendering;
    delete BootsRend;
}
