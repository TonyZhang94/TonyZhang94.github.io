#ifndef __NORMAL__
#define __NORMAL__

#include "Point3D.h"
#include "Vector3D.h"

class Normal {
public:
	double x;
	double y;
	double z;

public:

	Normal(void);
	Normal(double c);
	Normal(double _x, double _y, double _z);
	Normal(const Normal &n);
	Normal(const Point3D &p);
	Normal(const Vector3D &v);

	~Normal(void);

	Normal&
		operator= (const Normal &rhs);

	Normal&
		operator= (const Vector3D &rhs);

	Normal&
		operator= (const Point3D &rhs);

	Normal
		operator- (void) const;

	Normal
		operator+ (const Normal &n) const;

	Normal&
		operator+= (const Normal &n);

	double
		operator* (const Vector3D &v) const;

	Normal
		operator* (const double c) const;

	// 将法向量变为单位法向量
	void
		normalize(void);

	// 将法向量变为单位法向量
	Normal&
		hat(void);

	void
		print(void) const;
};

inline Normal&
	Normal::operator= (const Normal &rhs) {
		if (this == &rhs) return (*this);
		x = rhs.x; y = rhs.y; z = rhs.z;
		return (*this);
}

inline Normal&
	Normal::operator= (const Vector3D &rhs) {
		x = rhs.x; y = rhs.y; z = rhs.z;
		return (*this);
}

inline Normal&
	Normal::operator= (const Point3D &rhs) {
		x = rhs.x; y = rhs.y; z = rhs.z;
		return (*this);
}

inline Normal
	Normal::operator- (void) const {
		return (Normal(-x, -y, -z));
}

inline Normal
	Normal::operator+ (const Normal &n) const {
		return (Normal(x+n.x, y+n.y, z+n.z));
}

inline Normal&
	Normal::operator+= (const Normal &n) {
		x += n.x; y += n.y; z += n.z;
		return (*this);
}

inline double
	Normal::operator* (const Vector3D &v) const {
		return (x*v.x + y*v.y + z*v.z);
}

inline Normal
	Normal::operator* (const double c) const {
		return (Normal(x*c, y*c, z*c));
}

#endif