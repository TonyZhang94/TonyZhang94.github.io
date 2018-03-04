//#ifndef __POINT3DOLD__
//#define __POINT3DOLD__
//
//#include <math.h>
//
//class Point3D {
//public:
//
//	// 笛卡尔坐标
//	double x;
//	double y;
//	double z;
//
//public:
//
//	Point3D(void);
//	Point3D(double c);
//	Point3D(double _x, double _y, double _z);
//	Point3D(const Point3D &copy);
//
//	~Point3D(void);
//
//	// 三维坐标的四则运算
//	Point3D&
//		operator= (const Point3D &rhs);
//
//	Point3D
//		operator- (void) const;
//
//	Point3D
//		operator+ (const Point3D &c) const;
//
//	Point3D&
//		operator+= (const Point3D &rhs);
//
//	Point3D
//		operator- (const Point3D &c) const;
//
//	Point3D&
//		operator-= (const Point3D &rhs);
//
//	Point3D
//		operator* (const Point3D &c) const;
//
//	Point3D&
//		operator*= (const Point3D &rhs);
//
//	Point3D
//		operator/ (const Point3D &c) const;
//
//	Point3D&
//		operator/= (const Point3D &rhs);
//
//	Point3D
//		operator+ (const double c) const;
//
//	Point3D&
//		operator+= (const double rhs);
//
//	Point3D
//		operator- (const double c) const;
//
//	Point3D&
//		operator-= (const double rhs);
//
//	Point3D
//		operator* (const double c) const;
//
//	Point3D&
//		operator*= (const double rhs);
//
//	Point3D
//		operator/ (const double c) const;
//
//	Point3D&
//		operator/= (const double rhs);
//
//	bool
//		operator== (const Point3D &rhs) const;
//
//	double
//		distance2 (const Point3D &c) const;
//
//	double
//		distance (const Point3D &c) const;
//
//	void print(void) const;
//};
//
//inline Point3D&
//	Point3D::operator= (const Point3D &rhs) {
//		if (this == &rhs) return (*this);
//		x = rhs.x; y = rhs.y; z = rhs.z;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator- (void) const {
//		return Point3D(-x, -y, -z);
//}
//
//inline Point3D
//	Point3D::operator+ (const Point3D &c) const {
//		return Point3D(x+c.x, y+c.y, z+c.z);
//}
//
//inline Point3D&
//	Point3D::operator+= (const Point3D &rhs) {
//		x += rhs.x; y += rhs.y; z += rhs.z;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator- (const Point3D &c) const {
//		return Point3D(x-c.x, y-c.y, z-c.z);
//}
//
//inline Point3D&
//	Point3D::operator-= (const Point3D &rhs) {
//		x -= rhs.x; y -= rhs.y; z -= rhs.z;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator* (const Point3D &c) const {
//		return Point3D(x*c.x, y*c.y, z*c.z);
//}
//
//inline Point3D&
//	Point3D::operator*= (const Point3D &rhs) {
//		x *= rhs.x; y *= rhs.y; z *= rhs.z;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator/ (const Point3D &c) const {
//		return Point3D(x/c.x, y/c.y, z/c.z);
//}
//
//inline Point3D&
//	Point3D::operator/= (const Point3D &rhs) {
//		x /= rhs.x; y /= rhs.y; z /= rhs.z;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator+ (const double c) const {
//		return Point3D(x+c, y+c, z+c);
//}
//
//inline Point3D&
//	Point3D::operator+= (const double rhs) {
//		x += rhs; y += rhs; z += rhs;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator- (const double c) const {
//		return Point3D(x-c, y-c, z-c);
//}
//
//inline Point3D&
//	Point3D::operator-= (const double rhs) {
//		x -= rhs; y -= rhs; z -= rhs;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator* (const double c) const {
//		return Point3D(x*c, y*c, z*c);
//}
//
//inline Point3D&
//	Point3D::operator*= (const double rhs) {
//		x *= rhs; y *= rhs; z *= rhs;
//		return (*this);
//}
//
//inline Point3D
//	Point3D::operator/ (const double c) const {
//		return Point3D(x/c, y/c, z/c);
//}
//
//inline Point3D&
//	Point3D::operator/= (const double rhs) {
//		x /= rhs; y /= rhs; z /= rhs;
//		return (*this);
//}
//
//inline bool
//	Point3D::operator== (const Point3D &rhs) const {
//		return (x==rhs.x && y==rhs.y && z==rhs.z);
//}
//
//inline double
//	Point3D::distance2(const Point3D &c) const {
//		return ((x - c.x) * (x - c.x)
//			+ (y - c.y) * (y - c.y)
//			+ (z - c.z) * (z - c.z));
//}
//
//inline double
//	Point3D::distance(const Point3D &c) const {
//		return (sqrt((x - c.x) * (x - c.x)
//			+ (y - c.y) * (y - c.y)
//			+ (z - c.z) * (z - c.z)));
//}
//
//#endif