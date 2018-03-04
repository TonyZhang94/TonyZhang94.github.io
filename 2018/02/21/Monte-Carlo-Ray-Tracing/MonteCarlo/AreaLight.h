#ifndef __AREALIGHT__
#define __AREALIGHT__

#include "RGBColor.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Light.h"
#include "Material.h"
#include "GeometricObject.h"

class AreaLight : public Light {
public:

	AreaLight(void);
	AreaLight(const AreaLight &copy);

	virtual
		~AreaLight(void);

	AreaLight&
		operator= (const AreaLight &rhs);

	// 设置物体指针
	void
		set_object_ptr(GeometricObject *_object_ptr);

	// 设置自发光材料指针
	void
		set_material_ptr(const Material *_material_ptr);

	// 设置采样点
	void
		set_sample_point(const Point3D _sample_point);

	// 设置从光线交点到采样点的单位向量
	void
		set_wi(const Vector3D _wi);

	// 设置采样点的法向
	void
		set_light_normal(const Normal _light_normal);

	// cos theta' = -n'j dot wij / d^2
	virtual float
		G(ShadeRec *sr) const;

	// 调用当前物体的pdf方法
	virtual float
		pdf(ShadeRec *sr) const;

	// 计算材质的发射辐射度，如果光线和法线与物体的碰撞面不同则返回黑色
	virtual RGBColor
		L(ShadeRec *sr);

	// 检测阴影光线是否与碰撞点和采样点之间的对象发生碰撞
	virtual bool
		in_shadow(const Ray &ray, const ShadeRec *sr);

	// 克隆为Light指针
	virtual Light*
		clone(void) const;

	// 计算着色点与采样点之间的单位方向，并存储采样点、采样点处的法向
	virtual Vector3D
		get_direction(const ShadeRec *sr);

	void
		print(void) const;

private:

	GeometricObject *object_ptr; // 物体指针
	Material *material_ptr; // 自发光材料指针
	Point3D	sample_point; // 采样点
	Vector3D wi; // 从光线交点到采样点的单位向量
	Normal light_normal; // 采样点的法向
};

// 设置采样点
inline void
	AreaLight::set_sample_point(const Point3D _sample_point) {
		sample_point = _sample_point;
}

// 设置从光线交点到采样点的单位向量
inline void
	AreaLight::set_wi(const Vector3D _wi) {
		wi = _wi;
}

// 设置采样点的法向
inline void
	AreaLight::set_light_normal(const Normal _light_normal) {
		light_normal = _light_normal;
}

#endif