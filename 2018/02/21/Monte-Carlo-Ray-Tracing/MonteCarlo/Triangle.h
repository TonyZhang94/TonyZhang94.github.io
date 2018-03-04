#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "Constants.h"
#include "GeometricObject.h"

class Triangle : public GeometricObject {
public:

	Triangle(void);
	Triangle(const Point3D &_v0, const Point3D &_v1, const Point3D &_v2);
	Triangle(const Triangle &copy);

	~Triangle(void);

	Triangle&
		operator= (const Triangle &rhs);

	// 设置采样器
	virtual void
		set_sampler(Sampler *sampler);

	// 采样
	virtual Point3D
		sample(void);

	// 计算单位法向量
	void
		compute_normal(void);

	// 判断光线是否和阴影部分相交
	virtual bool
		shadow_hit(const Ray &ray, double &tmin);

	// 判断光纤和三角形是否相交
	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec *sr) const;

	// 克隆一个新的指针
	virtual Triangle*
		clone(void) const;

	void
		print(void) const;

public:

	Sampler *sampler_ptr;
	Point3D	v0, v1, v2; // 三角形三个顶点
	Normal normal; // 三角形法线
};

#endif