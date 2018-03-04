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

	// ��������
	void
		set_center(const Point3D &_center);

	// ���ð뾶
	void
		set_radius(double _radius);

	// �жϹ����Ƿ����Ӱ�����ཻ
	bool
		shadow_hit(const Ray &ray, double &tmin);

	// �жϹ��˺��������Ƿ��ཻ
	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec *sr) const;

	// ��¡һ���µ�ָ��
	virtual Sphere*
		clone(void) const;

	void
		print(void) const;

private:

	Point3D center; // ����
	double radius; // �뾶

	static const double kEpsilon; // Epsilon
};

// ��������
inline void
	Sphere::set_center(const Point3D &_center) {
		center = _center;
}

// ���ð뾶
inline void
	Sphere::set_radius(double _radius) {
		radius = _radius;
}

#endif