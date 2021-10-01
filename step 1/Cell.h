#pragma once
#include "iObject.h"

class Cell : public iObject {
public:
	void HasObject()override;
	void NoObject()override;

private:
	char status = ' '; // 0 - cell is available, 1 - cell is not available
					  // i - inlet, o - outlet

	friend class Map;
};
