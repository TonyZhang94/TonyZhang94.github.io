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

	Point3D o; // 光源点
	Vector3D d; // 方向向量
	int depth; // 深度
};

#endif