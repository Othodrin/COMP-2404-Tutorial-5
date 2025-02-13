#ifndef TEXTAREA_H
#define TEXTAREA_H
#include <X11/Xlib.h>
#include "RGB.h"
#include "defs.h"
#include <string>
#include <iostream>

class TextArea {
public:
	TextArea();
	TextArea(int, int, int, int, std::string, std::string, 
			RGB f = RGB::WHITE(), RGB b = RGB::BLACK());
	TextArea(Rectangle, std::string, std::string, 
			RGB f = RGB::WHITE(), RGB b = RGB::BLACK());
	TextArea(const TextArea&);


	void draw(Display*, Window, GC, int, int);
	bool overlaps(TextArea&);
    std::string getID();
	void print() const;

private:
	Rectangle dimensions;
	std::string text;
	std::string id;
	RGB fill, border;
};

#endif