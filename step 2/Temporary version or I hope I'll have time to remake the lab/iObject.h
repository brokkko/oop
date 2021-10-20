#pragma once

class iObject {
public:
	virtual ~iObject() {}

	virtual void HasObject() = 0;
	virtual void NoObject() = 0;

};