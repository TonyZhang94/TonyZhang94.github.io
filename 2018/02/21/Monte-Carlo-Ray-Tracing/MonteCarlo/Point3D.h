#ifndef __POINT3D__
#define __POINT3D__

#include <math.h>

#include "Vector3D.h"
#include "Matrix.h"

class Point3D {
public:

	Point3D(void);
	Point3D(double c);
	Point3D(double _x, double _y, double _z);
	Point3D(const Point3D &copy);

	~Point3D(void);

	Point3D&
		operator= (const Point3D &p);

	Point3D
		operator- (void) const;

	Vector3D
		operator- (const Point3D &p) const;

	Point3D
		operator+ (const Vector3D &v) const;

	Point3D
		operator- (const Vector3D &v) const;

	Point3D
		operator+ (const double c) const;

	Point3D
		operator- (const double c) const;

	Point3D
		operator* (const double c) const;

	Point3D
		operator/ (const double c) const;

	// 两点距离平方
	double
		distance2 (const Point3D &p) const;

	// 亮点距离
	double
		distance (const Point3D &p) const;

	void
		print(void) const;

public:

	// 笛卡尔坐标
	double x;
	double y;
	double z;
};

inline Point3D&
	Point3D::operator= (const Point3D &rhs) {
		if (this == &rhs) return (*this);
		x = rhs.x; y = rhs.y; z = rhs.z;
		return (*this);
}

inline Point3D
	Point3D::operator- (void) const {
		return (Point3D(-x, -y, -z));
}

inline Vector3D
	Point3D::operator- (const Point3D &p) const {
		return (Vector3D(x-p.x, y-p.y, z-p.z));
}

inline Point3D
	Point3D::operator+ (const Vector3D &v) const {
		return (Point3D(x+v.x, y+v.y, z+v.z));
}

inline Point3D
	Point3D::operator- (const Vector3D &v) const {
		return (Point3D(x-v.x, y-v.y, z-v.z));
}

inline Point3D
	Point3D::operator+ (const double c) const {
		return (Point3D(x+c, y+c, z+c));
}

inline Point3D
	Point3D::operator- (const double c) const {
		return (Point3D(x-c, y-c, z-c));
}

inline Point3D
	Point3D::operator* (const double c) const {
		return (Point3D(x*c, y*c, z*c));
}

inline Point3D
	Point3D::operator/ (const double c) const {
		return (Point3D(x/c, y/c, z/c));
}

// 两点距离平方
inline double
	Point3D::distance2(const Point3D &p) const {
		return ((x - p.x) * (x - p.x)
			+ (y - p.y) * (y - p.y)
			+ (z - p.z) * (z - p.z));
}

// 两点距离
inline double
	Point3D::distance(const Point3D &p) const {
		return (sqrt((x - p.x) * (x - p.x)
			+ (y - p.y) * (y - p.y)
			+ (z - p.z) * (z - p.z)));
}

#endif