#include "Map.h"

Map::Map(MapSetting map) : Height(0), Width(0), EnterenceX(map.EnterenceX), EnterenceY(map.EnterenceY),
                            ExitX(map.ExitX), ExitY(map.ExitY) {
    
    Height = map.MapHeight;
    Width = map.MapWidth;
    std::swap(CellsArray, map.ArrayOfCells);
}

Map::Map(const Map& other) {
    CellsArray = new Cell * [Height];
    for (size_t i = 0; i < Height; i++) {
        CellsArray[i] = new Cell[Width];
    }
    for (size_t height = 0; height < Height; height++) {
        for (size_t width = 0; width < Width; width++) {
            CellsArray[height][width] = other.CellsArray[height][width];
        }
    }
}

Map& Map::operator=(const Map& other) {
    if (this != &other) {
        for (size_t i = 0; i < Height; i++) {
            delete[] CellsArray[i];
        }
        delete[] CellsArray;
        CellsArray = new Cell * [Height];
        for (size_t i = 0; i < Width; i++) {
            CellsArray[i] = new Cell[Width];
        }
        for (size_t height = 0; height < Height; height++) {
            for (size_t width = 0; width < Width; width++) {
                CellsArray[height][width] = other.CellsArray[height][width];
            }
        }
    }
    return *this;
}

Map::Map(Map&& other) noexcept : EnterenceX(0), EnterenceY(0), ExitX(0), ExitY(0) {
    std::swap(Height, other.Height);
    std::swap(Width, other.Width);
    std::swap(CellsArray, other.CellsArray);
}

Map& Map::operator=(Map&& other) noexcept {
    if (this != &other) {
        std::swap(CellsArray, other.CellsArray);
    }
    return *this;
}
// сеттеры и геттеры
int Map::GetEnterenceX() { return EnterenceX; }
int Map::GetEnterenceY() { return EnterenceY; }
int Map::GetExitX() { return ExitX; }
int Map::GetExitY() { return ExitY; }
int Map::GetMapHeight() { return Height; }
int Map::GetMapWidth() { return Width; }

enum Cell::Type Map::GetCellFromMap(int H, int W) {
    return CellsArray[H][W].GetType();
}

void Map::SetStateOfCell(int H, int W, int val)
{
    CellsArray[H][W].SetState(static_cast<Cell::State>(val));
}

//void Map::SetObjectToCell(Entity* obj, int X, int Y){
//    CellsArray[X][Y].SetObject(obj);
//}
//
//void Map::RemoveObject(int X, int Y)
//{
//    CellsArray[X][Y].RemoveObject();
//}
//
//Entity* Map::GetCellObject(int X, int Y)
//{
//    return CellsArray[X][Y].GetObject();
//}

// деструктор
Map::~Map() {
    if (CellsArray) {
        for (int i = 0; i < Height; i++) {
            delete[] CellsArray[i];
        }
        delete[] CellsArray;
    }
}