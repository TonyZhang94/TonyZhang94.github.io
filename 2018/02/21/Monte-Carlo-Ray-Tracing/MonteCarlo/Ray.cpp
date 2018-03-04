#include <iostream>
using namespace std;

#include "Ray.h"

Ray::Ray(void)
	: o(0.0), d(0.0, 0.0, 1.0), depth(0) {
		
}

Ray::Ray(const Point3D &origin, const Vector3D &dir)
	: o(origin), d(dir), depth(0) {

}

Ray::Ray(const Ray &ray)
	: o(ray.o), d(ray.d), depth(0) {
	
}

Ray::~Ray (void) {

}

Ray&
	Ray::operator= (const Ray &rhs) {
		if (this == &rhs)
			return (*this);
		o = rhs.o; d = rhs.d; depth = rhs.depth;
		return (*this);
}

void
	Ray::print(void) const {
		cout << "o: x = " << o.x << "; y = " << o.y << "; z = " << o.z << endl;
		cout << "d: x = " << d.x << "; y = " << d.y << "; z = " << d.z << endl;
		cout << "depth = " << depth << endl;
}