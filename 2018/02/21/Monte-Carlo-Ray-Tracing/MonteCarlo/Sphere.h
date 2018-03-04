#ifndef __SPHERE
#define __SPHERE

#include "GeometricObject.h"

class Sphere : public GeometricObject {
public:

	Sphere(void);
	Sphere(Point3D _center, double _radius);
	Sphere(const Sphere &copy);

	virtual												
		~Sphere(void);

	Sphere&
		operator= (const Sphere &rhs);

	// 设置球心
	void
		set_center(const Point3D &_center);

	// 设置半径
	void
		set_radius(double _radius);

	// 判断光线是否和阴影部分相交
	bool
		shadow_hit(const Ray &ray, double &tmin);

	// 判断光纤和三角形是否相交
	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec *sr) const;

	// 克隆一个新的指针
	virtual Sphere*
		clone(void) const;

	void
		print(void) const;

private:

	Point3D center; // 球心
	double radius; // 半径

	static const double kEpsilon; // Epsilon
};

// 设置球心
inline void
	Sphere::set_center(const Point3D &_center) {
		center = _center;
}

// 设置半径
inline void
	Sphere::set_radius(double _radius) {
		radius = _radius;
}

#endif