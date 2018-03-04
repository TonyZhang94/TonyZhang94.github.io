#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "GeometricObject.h"

class Rectangle : public GeometricObject {
public:

	Rectangle(void);
	Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b);
	Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b, const Normal &_normal);
	Rectangle(const Rectangle &copy);

	virtual
		~Rectangle(void);

	Rectangle&
		operator= (const Rectangle &rhs);

	// 设置采样器
	virtual void
		set_sampler(Sampler *_sampler_ptr);

	// 采样
	virtual Point3D
		sample(void);

	// 存储面积的倒数，调用pdf时返回，减少一次除法操作
	virtual float
		pdf(ShadeRec *sr);

	// 计算单位法向量
	virtual Normal
		get_normal(const Point3D &p);

	// 判断光线是否和阴影部分相交
	virtual bool
		shadow_hit(const Ray &ray, double &tmin);

	// 判断光纤和长方形是否相交
	virtual bool
		hit(const Ray &ray, double &t, ShadeRec *s) const;

	// 克隆一个新的指针
	virtual Rectangle*
		clone(void) const;

	void
		print(void) const;
	
public:

	Sampler *sampler_ptr; // 采样器
	Point3D p0; // 长方形一个顶点
	Vector3D a; // 边向量a
	Vector3D b; // 边向量b
	double a_len_squared; // 边向量a的平方
	double b_len_squared; // 边向量b的平方
	Normal normal; // 单位法向量

	float area; // 面积
	float inv_area; // 面积的倒数

	static const double kEpsilon; // Epsilon
};

#endif