#include "Sphere.h"

Sphere::Sphere(void)
	: GeometricObject(), center(0.0), radius(1.0) {

}

Sphere::Sphere(Point3D _center, double _radius)
	: GeometricObject(), center(_center), radius(_radius) {

}

Sphere::Sphere (const Sphere &copy)
	: GeometricObject(copy), center(copy.center), radius(copy.radius) {

}

const double Sphere::kEpsilon = 0.001;

Sphere::~Sphere(void) {
	GeometricObject::~GeometricObject();
}

Sphere&
	Sphere::operator= (const Sphere &rhs) {
		if (this == &rhs)
			return (*this);

		GeometricObject::operator= (rhs);

		center 	= rhs.center;
		radius	= rhs.radius;

		return (*this);
}

// 判断光线是否和阴影部分相交
bool
	Sphere::shadow_hit(const Ray &ray, double &tmin) {
		double t;
		Vector3D temp = ray.o - center;
		double a = ray.d * ray.d;
		double b = 2.0 * temp * ray.d;
		double c = temp * temp - radius * radius;
		double disc = b * b - 4.0 * a * c;

		if (disc < 0.0)
			return false;
		else {
			double e = sqrt(disc);
			double denom = 2.0 * a;
			t = (-b - e) / denom;

			if (t > kEpsilon) {
				tmin = t;

				return true;
			}

			t = (-b + e) / denom;

			if (t > kEpsilon) {
				tmin = t;

				return true;
			}
		}

		return false;
}

// 判断光纤和三角形是否相交
bool
	Sphere::hit(const Ray &ray, double &tmin, ShadeRec *sr) const {
		double t;
		Vector3D temp = ray.o - center;
		double a = ray.d * ray.d;
		double b = 2.0 * temp * ray.d;
		double c = temp * temp - radius * radius;
		double disc = b * b - 4.0 * a * c;

		if (disc < 0.0)
			return(false);
		else {
			double e = sqrt(disc);
			double denom = 2.0 * a;
			t = (-b - e) / denom;

			if (t > kEpsilon) {
				tmin = t;
				sr->normal 	 = (temp + t * ray.d) / radius;
				sr->local_hit_point = ray.o + t * ray.d;
				return true;
			}

			t = (-b + e) / denom;

			if (t > kEpsilon) {
				tmin = t;
				sr->normal   = (temp + t * ray.d) / radius;
				sr->local_hit_point = ray.o + t * ray.d;
				return true;
			}
		}

		return false;
}

// 克隆一个新的指针
Sphere*
	Sphere::clone(void) const {
		return new Sphere(*this);
}

void
	Sphere::print(void) const {
		GeometricObject::print();
		cout << "Sphere:" << endl;
		cout << "center:"; center.print();
		cout << "radius = " << radius << endl;
}