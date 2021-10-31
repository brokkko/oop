#pragma once
#include <iostream>
#include "iObject.h"
#include "Entity.h"

class Cell : public iObject{
public:
	enum Type { Ground, Wall, Enterence, Exit, empty };
	enum State {Available, Unavailable};

	Cell();
	Cell(enum Type state);

	void SetType(enum Type state);
	enum Type GetType();
	
	void SetState(enum State state);
	enum State GetState();

	virtual bool HasObject() override;

	//void SetObject(Entity* entity);
	//void RemoveObject();
	//Entity* GetObject();

private:
	//std::string Name;
	Type type;
	State state;

	Entity* object;

};