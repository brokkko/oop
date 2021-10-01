#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Cell.h"

class Map {
private:

    enum class MapSize{Height = 12, Width = 20};
    
    Cell** CellsArray;

    std::string FieldMap[(int)MapSize::Height] = {
        "000000000000000o0000",
        "01111101111111111100",
        "01111111111111111100",
        "00000111111111111110",
        "01111111110000011110",
        "01111111111111111110",
        "01111111111111011110",
        "01111111111111000110",
        "00011111111111110110",
        "01111111111111110110",
        "01111111111111110110",
        "0000i000000000000000"
    };

public:
    Map(); // конструктор по умолчанию

    Map(const Map& other);  // конструктор копирования
    Map& operator=(const Map& other);

    Map(Map&& other) noexcept;  // конструктор перемещения
    Map& operator=(Map&& other) noexcept;

    int GetHeight();
    int GetWidth();

    ~Map();

    char GetCellFromMap(int i, int j); 
    void CreateMap();

   // void CreateStatus();
    void CopyMap(const Map& other);

    /*void print();*/
};