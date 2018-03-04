#ifndef __LIGHT__
#define __LIGHT__

#include <iostream>
using namespace std;

#include "Constants.h"
#include "RGBColor.h"
#include "Vector3D.h"
#include "Ray.h"

class ShadeRec;

class Light {
public:

	Light(void);
	Light(const Light &copy);

	virtual
		~Light(void);

	Light&
		operator= (const Light &rhs);

	virtual float
		G(ShadeRec *sr) const;

	// 调用物体的pdf方法
	virtual float
		pdf(ShadeRec *sr) const;

	// 计算入射辐射度
	virtual RGBColor
		L(ShadeRec *sr);

	// 检测阴影光线是否与碰撞点和采样点之间的对象发生碰撞
	virtual bool
		in_shadow(const Ray &ray, const ShadeRec *sr);

	// 克隆为Light
	virtual Light*
		clone(void) const = 0;

	// 计算碰撞点处的光线方向
	virtual Vector3D
		get_direction(const ShadeRec *sr) = 0;

	void
		print(void) const;
};

#endif