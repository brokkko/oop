#include "Cell.h"

Cell::Cell() : type(Cell::Type::empty), state(Cell::State::Available), Name("empty"), object(nullptr){}

Cell::Cell(enum Cell::Type state) : type(Cell::Type::empty), state(Cell::State::Available), Name("empty"), object(nullptr){
	this->type = state;
}
void  Cell::SetType(enum Cell::Type state) {
	this->type = state;
}

enum Cell::Type Cell::GetType() {
	return type;
}

void  Cell::SetState(enum Cell::State state) {
	this->state = state;
}

enum Cell::State Cell::GetState() {
	return state;
}

void Cell::SetObject(Entity* entity)
{
	object = entity;
	this->state = State::Unavailable;
}

void Cell::RemoveObject()
{
	if (object != nullptr) {
		object = nullptr;
		this->state = Cell::Available;
	}
}
