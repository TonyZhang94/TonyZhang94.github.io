#include <iostream>
using namespace std;

#include "RGBColor.h"

RGBColor::RGBColor(void)
	: r(0.0), g(0.0), b(0.0) {
	
}

RGBColor::RGBColor(float c)
	: r(c), g(c), b(c) {
	
}

RGBColor::RGBColor(float _r, float _g, float _b)
	: r(_r), g(_g), b(_b) {
	
}

RGBColor::RGBColor(const RGBColor &copy)
	: r(copy.r), g(copy.g), b(copy.b) {
	
}

RGBColor::~RGBColor(void) {

}

void
	RGBColor::print(void) const {
		cout << "R = " << r << "; G = " << g << "; B = " << b << endl;
}