#include "BBox.h"

BBox::BBox(void)
	: x0(-1), x1(1), y0(-1), y1(1), z0(-1), z1(1) {

}	

BBox::BBox(double _x0, double _x1, double _y0, double _y1, double _z0, double _z1)
	: x0(_x0), x1(_x1), y0(_y0), y1(_y1), z0(_z0), z1(_z1) {

}

BBox::BBox(const Point3D &p0, const Point3D &p1)
	: x0(p0.x), x1(p1.x), y0(p0.y), y1(p1.y), z0(p0.z), z1(p1.z) {

}

BBox::BBox(const BBox &copy)
	: x0(copy.x0), x1(copy.x1), y0(copy.y0), y1(copy.y1), z0(copy.z0), z1(copy.z1) {

}						

BBox&
	BBox::operator= (const BBox &rhs) {
		if (this == &rhs)
			return (*this);

		x0	= rhs.x0;
		x1	= rhs.x1;
		y0	= rhs.y0;
		y1	= rhs.y1;
		z0	= rhs.z0;
		z1	= rhs.z1;

		return (*this);
}			

BBox::~BBox(void) {

}	

// 光纤是否穿过包围盒
bool 									
	BBox::hit(const Ray &ray) const {
		double ox = ray.o.x; double oy = ray.o.y; double oz = ray.o.z;
		double dx = ray.d.x; double dy = ray.d.y; double dz = ray.d.z;

		double tx_min, ty_min, tz_min;
		double tx_max, ty_max, tz_max;

		double a = 1.0 / dx;
		if (a >= 0) {
			tx_min = (x0 - ox) * a;
			tx_max = (x1 - ox) * a;
		}
		else {
			tx_min = (x1 - ox) * a;
			tx_max = (x0 - ox) * a;
		}

		double b = 1.0 / dy;
		if (b >= 0) {
			ty_min = (y0 - oy) * b;
			ty_max = (y1 - oy) * b;
		}
		else {
			ty_min = (y1 - oy) * b;
			ty_max = (y0 - oy) * b;
		}

		double c = 1.0 / dz;
		if (c >= 0) {
			tz_min = (z0 - oz) * c;
			tz_max = (z1 - oz) * c;
		}
		else {
			tz_min = (z1 - oz) * c;
			tz_max = (z0 - oz) * c;
		}

		double t0, t1; // 最大t值t0，最小t值t1
		if (tx_min > ty_min)
			t0 = tx_min;
		else
			t0 = ty_min;
		if (tz_min > t0)
			t0 = tz_min;

		if (tx_max < ty_max)
			t1 = tx_max;
		else
			t1 = ty_max;
		if (tz_max < t1)
			t1 = tz_max;

		// 光线进入平面处的最大t0值小于光纤离开平面处最小t1值则光线与包围盒相交，最小值t1应大于0
		return (t0 < t1 && kEpsilon < t1);
}

// 判断是否在包围盒内
bool
	BBox::inside(const Point3D &p) const {
		return ((x0 < p.x && p.x < x1) && (y0 < p.y && p.y < y1) && (z0 < p.z && p.z < z1));
};

void
	BBox::print(void) const {
		cout << "x0 = " << x0 << "; x1 = " << x1 << endl
			<< "y0 = " << y0 << "; y1 = " << y1 << endl
			<< "z0 = " << z0 << "; z1 = " << z1 << endl;
}