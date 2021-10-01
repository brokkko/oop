#include "Map.h"
#include <iostream>

char Map::GetCellFromMap(int i, int j) {
    return CellsArray[i][j].status;
}

int Map::GetHeight() {
    return (int)Map::MapSize::Height;
}

int Map::GetWidth() {
    return (int)Map::MapSize::Width;
}

//void Map::CreateStatus() {
//    for (size_t height = 0; height < (int)MapSize::Height; height++) {
//        for (size_t width = 0; width < (int)MapSize::Width; width++) {
//            CellsArray[height][width].status = '1';
//        }
//    }
//    CellsArray[1][0].status = 'i';
//    CellsArray[1][(int)MapSize::Width - 1].status = 'o';
//    
//}

void Map::CreateMap() {
    for (size_t height = 0; height < (int)MapSize::Height; height++) {
        for (size_t width = 0; width < (int)MapSize::Width; width++) {
            CellsArray[height][width].status = FieldMap[height][width];
        }
    } 
}
Map::Map() {
    CellsArray = new Cell * [(int)MapSize::Height];
    for (size_t i = 0; i < (int)MapSize::Height; i++) {
        CellsArray[i] = new Cell[(int)MapSize::Width];
    }
}

void Map::CopyMap(const Map& other) {
    CellsArray = new Cell * [(int)MapSize::Height];
    for (size_t i = 0; i < (int)MapSize::Height; i++) {
        CellsArray[i] = new Cell[(int)MapSize::Width];
    }
    for (size_t height = 0; height < (int)MapSize::Height; height++) {
        for (size_t width = 0; width < (int)MapSize::Width; width++) {
            CellsArray[height][width] = other.CellsArray[height][width];
        }
    }
}

Map::Map(const Map& other) {
    CopyMap(other);
}

Map& Map::operator=(const Map& other) {
    if (this != &other) {
        for (size_t i = 0; i < (int)MapSize::Height; i++) {
            delete[] CellsArray[i];
        }
        delete[] CellsArray;
        CopyMap(other);
    }
    return *this;
}

Map::Map(Map&& other) noexcept {
    std::swap(CellsArray, other.CellsArray);
}

Map& Map::operator=(Map&& other) noexcept {
    if (this != &other) {
        std::swap(CellsArray, other.CellsArray);
    }
    return *this;
}

Map::~Map(){
    for (size_t i = 0; i < (int)MapSize::Height; i++) {
        delete[] CellsArray[i];
    }
    delete[] CellsArray;
}

//void Map::print() {
//    for (size_t height = 0; height < (int)MapSize::Height; height++) {
//        std::cout << CellsArray[height] << std::endl;
//    }
//    std::cout << "THE END\n";
//}
