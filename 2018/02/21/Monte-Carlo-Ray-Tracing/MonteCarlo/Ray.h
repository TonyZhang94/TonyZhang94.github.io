#ifndef __RAY__
#define __RAY__

#include "Point3D.h"
#include "Vector3D.h"

class Ray {
public:

	Ray(void);
	Ray(const Point3D &original, const Vector3D &dir);
	Ray(const Ray &ray);

	~Ray(void);

	Ray&
		operator= (const Ray &rhs);

	void
		print(void) const;

public:

	Point3D o; // ��Դ��
	Vector3D d; // ��������
	int depth; // ���
};

#endif