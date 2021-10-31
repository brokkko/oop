#pragma once
#include "Cell.h"
#include <string>
#include<ctime>

class MapSetting {
private:
	int MapHeight, MapWidth; // X and Y coordinates
	std::string PathToLevel1;
	int EnterenceX, EnterenceY;               
	int ExitX, ExitY;

	Cell** ArrayOfCells;

public:
	MapSetting(std::string Path);

	void GetMapSizeFromFile();
	void GetMapFromFile();
	void Generation();

	~MapSetting();

	friend class Map;

	void PrintStatus();
	Cell** GetMap();
};