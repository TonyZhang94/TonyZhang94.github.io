#ifndef __GEOMETRICOBJECT__
#define __GEOMETRICOBJECT__

#include <math.h>

#include "Constants.h"
#include "RGBColor.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "BBox.h"
#include "Sampler.h"

class Material;

class GeometricObject {
public:

	GeometricObject(void);
	GeometricObject(const GeometricObject &copy);

	virtual
		~GeometricObject(void);

	GeometricObject&
		operator= (const GeometricObject &rhs);

	// 设置材料
	virtual void
		set_material(Material *_material_ptr);

	// 获取材料
	Material*
		get_material(void) const;

	// 设置采样器
	virtual void
		set_sampler(Sampler *_sampler_ptr);

	//Sampler*
	//	get_sampler(void) const;

	// 加入新的物体
	virtual void
		add_object(GeometricObject *object_ptr);

	// 采样
	virtual Point3D
		sample(void);

	virtual float
		pdf(ShadeRec *sr);

	// 计算法向
	virtual Normal
		get_normal(void) const;

	// 计算法向
	virtual Normal
		get_normal(const Point3D &p);

	// 光线是否与阴影相交
	virtual bool
		shadow_hit(const Ray &ray, double &tmin);

	// 光线是否与物体相交
	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec *sr) const = 0;

	// 克隆
	virtual GeometricObject*
		clone(void) const = 0;

	void
		print(void) const;

protected:

	Material *material_ptr; // 材质指针
	Sampler *sampler_ptr; // 采样器指针
	RGBColor color; // 物体颜色
};

#endif