#pragma once
#include "Cell.h"
#include "MapSetting.h"

class Map : public Cell {
private:
    int Height, Width;
    int EnterenceX, EnterenceY, ExitX, ExitY;

    Cell** CellsArray;

public:
    Map(MapSetting map); // конструктор по умолчанию

    Map(const Map& other);  // конструктор копирования
    Map& operator=(const Map& other);

    Map(Map&& other) noexcept;  // конструктор перемещения
    Map& operator=(Map&& other) noexcept;

    int GetEnterenceX();
    int GetEnterenceY();
    int GetExitX();
    int GetExitY();
    int GetMapHeight();
    int GetMapWidth();

    enum Type GetCellFromMap(int H, int W);
    void SetStateOfCell(int H, int W, int val);

   // char GetCellFromMap(int i, int j);
   // void SetCellToMap(int i, int j, char NewStatus);
 
  //  std::string GetObject(int i, int j);
   // void SetObject(int i, int j, std::string name);


    ~Map();

};
