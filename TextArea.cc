#include "TextArea.h"

TextArea::TextArea() 
    : dimensions{0, 0, 10, 10}, text(""), id(""), 
      fill(RGB::WHITE()), border(RGB::BLACK()) {
}

TextArea::TextArea(int x, int y, int w, int h, std::string t, std::string i, RGB f, RGB b)
    : dimensions{x, y, w, h}, text(t), id(i), fill(f), border(b) {
}

TextArea::TextArea(Rectangle r, std::string t, std::string i, RGB f, RGB b)
    : dimensions(r), text(t), id(i), fill(f), border(b) {
}

TextArea::TextArea(const TextArea& other)
    : dimensions(other.dimensions), text(other.text), id(other.id),
      fill(other.fill), border(other.border) {
}

std::string TextArea::getID(){
    return this->text;
}

void TextArea::draw(Display* display, Window window, GC gc, int x, int y) {
	XSetForeground(display, gc, fill.getColour());
	XDrawRectangle(display, window, gc, dimensions.x, dimensions.y, dimensions.width, dimensions.height);
	XSetForeground(display, gc, border.getColour());
	XDrawRectangle(display, window, gc, dimensions.x, dimensions.y, dimensions.width, dimensions.height);
}

bool TextArea::overlaps(TextArea& other) {
	return dimensions.x < other.dimensions.x + other.dimensions.width &&
		dimensions.x + dimensions.width > other.dimensions.x &&
		dimensions.y < other.dimensions.y + other.dimensions.height &&
		dimensions.y + dimensions.height > other.dimensions.y;
}

void TextArea::print() const{
	std::cout << "TextArea: " << text << " \nID: " << id << " \nFill: " << fill.getColour() << " \nBorder: " << border.getColour() << std::endl;
}

