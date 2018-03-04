#ifndef __POINT2D__
#define __POINT2D__

#include <math.h>

class Point2D {
public:

	Point2D(void);
	Point2D(double c);
	Point2D(double _x, double _y);
	Point2D(const Point2D &copy);

	~Point2D(void);

	// 二维坐标的四则运算
	Point2D&
		operator= (const Point2D &rhs);

	Point2D
		operator- (void) const;

	Point2D
		operator+ (const Point2D &c) const;

	Point2D&
		operator+= (const Point2D &rhs);

	Point2D
		operator- (const Point2D &c) const;

	Point2D&
		operator-= (const Point2D &rhs);

	Point2D
		operator* (const Point2D &c) const;

	Point2D&
		operator*= (const Point2D &rhs);

	Point2D
		operator/ (const Point2D &c) const;

	Point2D&
		operator/= (const Point2D &rhs);

	Point2D
		operator+ (const double c) const;

	Point2D&
		operator+= (const double rhs);

	Point2D
		operator- (const double c) const;

	Point2D&
		operator-= (const double rhs);

	Point2D
		operator* (const double c) const;

	Point2D&
		operator*= (const double rhs);

	Point2D
		operator/ (const double c) const;

	Point2D&
		operator/= (const double rhs);

	bool
		operator== (const Point2D &rhs) const;

	// 两点距离平方
	double
		distance2 (const Point2D &c) const;

	// 两点距离
	double
		distance (const Point2D &c) const;

	void print(void) const;

public:

	// 笛卡尔坐标
	double x;
	double y;
};

inline Point2D&
	Point2D::operator= (const Point2D &rhs) {
		if (this == &rhs) return (*this);
		x = rhs.x; y = rhs.y;
		return (*this);
}

inline Point2D
	Point2D::operator- (void) const {
		return Point2D(-x, -y);
}

inline Point2D
	Point2D::operator+ (const Point2D &c) const {
		return Point2D(x+c.x, y+c.y);
}

inline Point2D&
	Point2D::operator+= (const Point2D &rhs) {
		x += rhs.x; y += rhs.y;
		return (*this);
}

inline Point2D
	Point2D::operator- (const Point2D &c) const {
		return Point2D(x-c.x, y-c.y);
}

inline Point2D&
	Point2D::operator-= (const Point2D &rhs) {
		x -= rhs.x; y -= rhs.y;
		return (*this);
}

inline Point2D
	Point2D::operator* (const Point2D &c) const {
		return Point2D(x*c.x, y*c.y);
}

inline Point2D&
	Point2D::operator*= (const Point2D &rhs) {
		x *= rhs.x; y *= rhs.y;
		return (*this);
}

inline Point2D
	Point2D::operator/ (const Point2D &c) const {
		return Point2D(x/c.x, y/c.y);
}

inline Point2D&
	Point2D::operator/= (const Point2D &rhs) {
		x /= rhs.x; y /= rhs.y;
		return (*this);
}

inline Point2D
	Point2D::operator+ (const double c) const {
		return Point2D(x+c, y+c);
}

inline Point2D&
	Point2D::operator+= (const double rhs) {
		x += rhs; y += rhs;
		return (*this);
}

inline Point2D
	Point2D::operator- (const double c) const {
		return Point2D(x-c, y-c);
}

inline Point2D&
	Point2D::operator-= (const double rhs) {
		x -= rhs; y -= rhs;
		return (*this);
}

inline Point2D
	Point2D::operator* (const double c) const {
		return Point2D(x*c, y*c);
}

inline Point2D&
	Point2D::operator*= (const double rhs) {
		x *= rhs; y *= rhs;
		return (*this);
}

inline Point2D
	Point2D::operator/ (const double c) const {
		return Point2D(x/c, y/c);
}

inline Point2D&
	Point2D::operator/= (const double rhs) {
		x /= rhs; y /= rhs;
		return (*this);
}

inline bool
	Point2D::operator== (const Point2D &rhs) const {
		return (x==rhs.x && y==rhs.y);
}

// 两点距离平方
inline double
	Point2D::distance2(const Point2D &c) const {
		return ((x - c.x) * (x - c.x)
			+ (y - c.y) * (y - c.y));
}

// 两点距离
inline double
	Point2D::distance(const Point2D &c) const {
		return (sqrt((x - c.x) * (x - c.x)
			+ (y - c.y) * (y - c.y)));
}

#endif