#include "RGB.h"

RGB::RGB(CuColour colour) {
    unsigned int blueByte = (colour >> (8 * 0)) & 0xFF;
    unsigned int greenByte = (colour >> (8 * 1)) & 0xFF;
    unsigned int redByte = (colour >> (8 * 2)) & 0xFF;
    r = static_cast<int>(redByte);
    g = static_cast<int>(greenByte);
    b = static_cast<int>(blueByte);
}

CuColour RGB::getColour() const{
    CuColour colour = 0;
    colour |= (static_cast<CuColour>(b) & 0xFF) << (8 * 0);
    colour |= (static_cast<CuColour>(g) & 0xFF) << (8 * 1);
    colour |= (static_cast<CuColour>(r) & 0xFF) << (8 * 2);
    return colour;
}

void RGB::setColour(CuColour colour) {
    unsigned int blueByte = (colour >> (8 * 0)) & 0xFF;
    unsigned int greenByte = (colour >> (8 * 1)) & 0xFF;
    unsigned int redByte = (colour >> (8 * 2)) & 0xFF;
    r = static_cast<int>(redByte);
    g = static_cast<int>(greenByte);
    b = static_cast<int>(blueByte);
}

int RGB::getR() {
    return r;
}

int RGB::getG() {
    return g;
}

int RGB::getB() {
    return b;
}

RGB RGB::WHITE() {
    return RGB((CuColour)0xFFFFFF);
}

RGB RGB::BLACK() {
    return RGB((CuColour)0x000000);
}

RGB RGB::RED() {
    return RGB((CuColour)0xFF0000);
}

RGB RGB::GREEN() {
    return RGB((CuColour)0x00FF00);
}

RGB RGB::BLUE() {
    return RGB((CuColour)0x0000FF);
}