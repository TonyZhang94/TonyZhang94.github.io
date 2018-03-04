#include <iostream>
using namespace std;

#include "Normal.h"

Normal::Normal(void)
	: x(0.0), y(0.0), z(0.0) {

}

Normal::Normal(double c)
	: x(c), y(c), z(c) {

}

Normal::Normal(double _x, double _y, double _z)
	: x(_x), y(_y), z(_z) {

}

Normal::Normal(const Normal &n)
	: x(n.x), y(n.y), z(n.z) {

}

Normal::Normal(const Point3D &p)
	: x(p.x), y(p.y), z(p.z) {

}

Normal::Normal(const Vector3D &v)
	: x(v.x), y(v.y), z(v.z) {

}

Normal::~Normal(void) {

}

// 将法向量变为单位法向量
void
	Normal::normalize(void) {
		double length = sqrt(x*x + y*y + z*z);
		x /= length; y /= length; z /= length;
}

// 将法向量变为单位法向量
Normal&
	Normal::hat(void) {
		double length = sqrt(x*x + y*y + z*z);
		x /= length; y /= length; z /= length;
		return (*this);
}

void
	Normal::print(void) const {
		cout << "x = " << x << "; y = " << y << "; z = " << z << endl;
}