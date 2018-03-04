#include <iostream>
using namespace std;

#include "Point2D.h"

Point2D::Point2D(void)
	: x(0.0), y(0.0) {

}

Point2D::Point2D(double c)
	: x(c), y(c) {

}

Point2D::Point2D(double _x, double _y)
	: x(_x), y(_y) {

}

Point2D::Point2D(const Point2D &copy)
	: x(copy.x), y(copy.y) {

}

Point2D::~Point2D(void) {

}

void
	Point2D::print(void) const {
		cout << "x = " << x << "; y = " << y << endl;
}