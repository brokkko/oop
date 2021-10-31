#pragma once

class iObject {
public:
	virtual ~iObject() {}

	virtual bool HasObject() = 0;
	//virtual void NoObject() = 0;

};