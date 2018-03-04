#ifndef __LAMBERTIAN__
#define __LAMBERTIAN__

#include "BRDF.h"

class Lambertian : public BRDF {
public:

	Lambertian(void);
	Lambertian(float _kd, const RGBColor &_cd);
	Lambertian(float _kd, float r, float g, float b);
	Lambertian(const Lambertian &copy);

	virtual ~Lambertian(void);

	Lambertian&
		operator= (const Lambertian &rhs);

	// 设置材质的环境光反射系数
	void
		set_ka(float _ka);

	// 设置材质的漫反射系数
	void
		set_kd(float _kd);

	// 设置材质的漫反射颜色
	void
		set_cd(const RGBColor &_cd);

	// 设置材质的漫反射颜色
	void
		set_cd(float r, float g, float b);

	// 设置材质的漫反射颜色
	void
		set_cd(float c);

	// kd * cd / pi
	virtual RGBColor
		f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const;

	// wi, kd * cd / (n dot product wi)
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const;

	// kd * cd
	virtual RGBColor
		rho(const ShadeRec *sr, const Vector3D &wo) const;

	// 克隆Lambertian
	virtual Lambertian*
		clone(void) const;

	void
		print(void) const;

private:

	float kd; // 材质的漫反射系数
	RGBColor cd; // 材质的漫反射颜色
};

// 设置材质的环境光反射系数
inline void
	Lambertian::set_ka(float _ka) {
		kd = _ka;
}

// 设置材质的漫反射系数
inline void
	Lambertian::set_kd(float _kd) {
		kd = _kd;
}

// 设置材质的漫反射颜色
inline void
	Lambertian::set_cd(const RGBColor &_cd) {
		cd = _cd;
}

// 设置材质的漫反射颜色
inline void
	Lambertian::set_cd(float r, float g, float b) {
		cd.r = r;
		cd.g = g;
		cd.b = b;
}

// 设置材质的漫反射颜色
inline void
	Lambertian::set_cd(float c) {
		cd.r = c;
		cd.g = c;
		cd.b = c;
}

#endif