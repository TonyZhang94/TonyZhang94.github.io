#ifndef __MATTE__
#define __MATTE__

#include "World.h"
#include "Material.h"
#include "Lambertian.h"

class Matte : public Material {
public:

	Matte(void);											
	Matte(const Matte &copy);

	~Matte(void);

	Matte&
		operator= (const Matte &rhs);							

	// 设置材质的环境光反射系数
	void
		set_ka(float _ka);

	// 设置材质的漫反射系数
	void
		set_kd(float _kd);

	// 设置材质的漫反射颜色
	void
		set_cd(float r, float g, float b);

	// 设置材质的漫反射颜色
	void
		set_cd(float c);

	// 设置材质的漫反射颜色
	void
		set_cd(const RGBColor &_cd);

	// 计算光照
	virtual RGBColor
		shade(ShadeRec *sr);

	// 计算区域光照
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// 克隆为Material
	virtual Material*
		clone(void) const;

	void
		print(void) const;
private:

	Lambertian *ambient_brdf; // 环境光
	Lambertian *diffuse_brdf; // 漫射光
};

// 设置材质的环境光反射系数
inline void
	Matte::set_ka(float _ka) {
		ambient_brdf->set_kd(_ka);
}

// 设置材质的漫反射系数
inline void
	Matte::set_kd (float _kd) {
		diffuse_brdf->set_kd(_kd);
}

// 设置材质的漫反射颜色
inline void
	Matte::set_cd(float r, float g, float b) {
		ambient_brdf->set_cd(r, g, b);
		diffuse_brdf->set_cd(r, g, b);
}

// 设置材质的漫反射颜色
inline void
	Matte::set_cd(float c) {
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
}

// 设置材质的漫反射颜色
inline void
	Matte::set_cd(const RGBColor &_cd) {
		ambient_brdf->set_cd(_cd);
		diffuse_brdf->set_cd(_cd);
}

#endif