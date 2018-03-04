#ifndef __VECTOR3D__
#define __VECTOR3D__

#include <math.h>

class Matrix;
class Point3D;
class Normal;

class Vector3D {
public:

	Vector3D(void);
	Vector3D(double c);
	Vector3D(double _x, double _y, double _z);
	Vector3D(const Vector3D &v);
	Vector3D(const Point3D &p);
	Vector3D(const Normal &n);

	~Vector3D(void);

	Vector3D&
		operator= (const Vector3D &rhs);

	Vector3D&
		operator= (const Point3D &rhs);

	Vector3D&
		operator= (const Normal &rhs);

	Vector3D
		operator- (void) const;

	// double
	Vector3D
		operator+ (const double c) const;

	Vector3D
		operator- (const double c) const;

	Vector3D
		operator* (const double c) const;

	Vector3D
		operator/ (const double c) const;

	// vector
	Vector3D
		operator+ (const Vector3D &v) const;

	Vector3D&
		operator+= (const Vector3D &v);

	Vector3D
		operator- (const Vector3D &v) const;

	double
		operator* (const Vector3D &b) const;

	Vector3D
		operator^ (const Vector3D &v) const;

	// 向量长度
	double
		modeLength(void);

	// 向量长度平方
	double
		modeLengthSquart(void);

	// 点与向量距离
	double
		distance(const Point3D &p);

	// 转为单位向量
	void
		normalize(void);

	// 转为单位向量
	Vector3D&
		hat(void);

	void
		print(void) const;

public:

	double x;
	double y;
	double z;
};

inline Vector3D
	Vector3D::operator- (void) const {
		return (Vector3D(-x, -y, -z));
}

inline Vector3D
	Vector3D::operator+ (const double c) const {
		return (Vector3D(x+c, y+c, z+c));
}

inline Vector3D
	Vector3D::operator- (const double c) const {
		return (Vector3D(x-c, y-c, z-c));
}

inline Vector3D
	Vector3D::operator* (const double c) const {
		return (Vector3D(x*c, y*c, z*c));
}

inline Vector3D
	Vector3D::operator/ (const double c) const {
		return (Vector3D(x/c, y/c, z/c));
}

inline Vector3D
	Vector3D::operator+ (const Vector3D &v) const {
		return (Vector3D(x+v.x, y+v.y, z+v.z));
}

inline Vector3D&
	Vector3D::operator+= (const Vector3D &v) {
		x += v.x; y += v.y; z += v.z;
		return (*this);
}

inline Vector3D
	Vector3D::operator- (const Vector3D &v) const {
		return (Vector3D(x-v.x, y-v.y, z-v.z));
}

inline double
	Vector3D::operator* (const Vector3D &v) const {
		return (x*v.x + y*v.y + z*v.z);
}

inline Vector3D
	Vector3D::operator^ (const Vector3D &v) const {
		return (Vector3D(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x));
}

Vector3D
	operator* (const double c, const Vector3D &v);

inline Vector3D
	operator* (const double c, const Vector3D &v) {
		return (Vector3D(c*v.x, c*v.y, c*v.z));
}

Vector3D
	operator* (const Matrix &mat, const Vector3D &v);

#endif