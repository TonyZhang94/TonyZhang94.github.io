#ifndef __BBox__
#define __BBox__

#include <iostream>
using namespace std;

#include "Point3D.h"
#include "Ray.h"
#include "Constants.h"

class BBox {
public:
	double x0;
	double x1;
	double y0;
	double y1;
	double z0;
	double z1;

public:

	BBox(void);
	BBox(double x0, double x1, double y0, double y1, double z0, double z1);
	BBox(const Point3D &p0, const Point3D &p1);
	BBox(const BBox &copy);

	~BBox(void);

	BBox&
		operator= (const BBox &rhs);

	// �����Ƿ񴩹���Χ��
	bool
		hit(const Ray &ray) const;

	// �ж��Ƿ��ڰ�Χ����
	bool
		inside(const Point3D &p) const;

	void
		print(void) const;
};

#endif