#include "Cell.h"

Cell::Cell() : type(Cell::Type::empty), state(Cell::State::Available), object(nullptr){
	//object = new Entity("", 0, 0, 0, 0, 0);
}

Cell::Cell(enum Cell::Type state) : type(Cell::Type::empty), state(Cell::State::Available), object(nullptr){
	this->type = state;
	//object = new Entity("", 0, 0, 0, 0, 0);
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

bool Cell::HasObject()
{
	if (object != nullptr) return true;
	else return false;
}

//void Cell::SetObject(Entity* entity)
//{
//	this->object = entity;
//	this->state = State::Unavailable;
//}
//
//void Cell::RemoveObject()
//{
//	if (object != nullptr) {
//		object = nullptr;
//		this->state = Cell::Available;
//	}
//}
//
//Entity* Cell::GetObject() {
//	if (object != nullptr)
//		return object;
//}
