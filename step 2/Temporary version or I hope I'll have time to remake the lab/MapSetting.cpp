#include "MapSetting.h"
#include <fstream>

MapSetting::MapSetting(std::string Path) : PathToLevel1(Path), MapHeight(0), MapWidth(0), EnterenceX(0), EnterenceY(0), ExitX(0), ExitY(0) {
    GetMapSizeFromFile();
    ArrayOfCells = new Cell * [MapHeight];
    for (int i = 0; i < MapHeight; i++) {
        ArrayOfCells[i] = new Cell[MapWidth];
    }
    GetMapFromFile();
    Generation();
}

void MapSetting::GetMapSizeFromFile(){
    std::ifstream in(PathToLevel1);
    std::string line;

    while (!in.eof()) {
        std::getline(in, line);
        MapHeight++;
    }
    MapWidth = int(line.length());
    in.close();
}

void MapSetting::GetMapFromFile()
{
    std::ifstream in(PathToLevel1);
    char sign; int num;
    for (int i = 0; i < MapHeight; i++) {
        for (int j = 0; j < MapWidth; j++) {
            in >> sign; num = sign - '0';
            ArrayOfCells[i][j].SetType(static_cast<Cell::Type>(num));
        }
    }

    in.close();
}

void MapSetting::Generation(){
    // Generation of enterance cell
    EnterenceX = 0;
    while (!EnterenceY) {
        EnterenceY = rand() % (MapHeight - 4) + 2;
        if (ArrayOfCells[EnterenceX + 1][EnterenceY].GetType() == Cell::Type::Wall)
            EnterenceY = 0;
    }
    // Generation of exit cell
    ExitX = MapWidth - 1;
    while (!ExitY) {
        ExitY = rand() % (MapHeight - 4) + 2;
        if (ArrayOfCells[ExitX - 1][ExitY].GetType() == Cell::Type::Wall)
            ExitY = 0;
    }
    // Set new type of cells
    ArrayOfCells[EnterenceY][EnterenceX].SetType(static_cast<Cell::Type>(2));
    ArrayOfCells[EnterenceY+1][EnterenceX].SetType(static_cast<Cell::Type>(2));

    ArrayOfCells[ExitY][ExitX].SetType(static_cast<Cell::Type>(3));
    ArrayOfCells[ExitY+1][ExitX].SetType(static_cast<Cell::Type>(3));
    
}

MapSetting::~MapSetting() {
    if (ArrayOfCells) {
        for (int i = 0; i < MapHeight; i++) {
            delete[] ArrayOfCells[i];
        }
        delete[] ArrayOfCells;
    }
}

void MapSetting::PrintStatus()
{
    for (int i = 0;i < MapHeight; i++) {
        for (int j = 0; j < MapWidth ; j++) {
            if (ArrayOfCells[i][j].GetType() == Cell::Type::Wall) {
                std::cout << "Wall ";
            }
            if (ArrayOfCells[i][j].GetType() == Cell::Type::Ground) {
                std::cout << "Ground ";
            }
            if (ArrayOfCells[i][j].GetType() == Cell::Type::Enterence) {
                std::cout << "Enterence ";
            }
            if (ArrayOfCells[i][j].GetType() == Cell::Type::Exit) {
                std::cout << "Exit ";
            }
        }
        std::cout << std::endl;
    }
}
Cell** MapSetting::GetMap() {
    return ArrayOfCells;
}
