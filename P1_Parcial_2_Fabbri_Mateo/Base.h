#pragma once

#include <iostream>

class Base
{
protected:
	bool isActive;

public:
	Base();
	virtual ~Base();

	virtual void start() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};