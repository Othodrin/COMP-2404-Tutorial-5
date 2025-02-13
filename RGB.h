#ifndef RGB_H
#define RGB_H
#include "defs.h"
#include <cstdint>
class RGB{
public:
	RGB(CuColour);
	void print() const;
	CuColour getColour() const;
	void setColour(CuColour);

	int getR();
	int getG();
	int getB();

	static RGB WHITE();
	static RGB BLACK();
	static RGB RED();
	static RGB GREEN();
	static RGB BLUE();

private:
	int r;
	int g;
	int b;
};

#endif