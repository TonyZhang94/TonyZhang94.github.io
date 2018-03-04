#ifndef __PHONG__
#define __PHONG__

#include "Lambertian.h"
#include "GlossySpecular.h"
#include "Material.h"

class Phong : public Material {
public:

	Phong(void);
	Phong(const Phong &copy);

	~Phong(void);

	Phong&
		operator= (const Phong &rhs);
	
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

	// 设置样本
	void
		set_sampler(Sampler *_sampler, double _exp);

	// 设置样本
	void
		set_samples(int _num_samples, double _exp);

	// 设置右侧投影向量的颜色
	void
		set_cr(float r, float g, float b);

	// 设置右侧投影向量的颜色
	void
		set_cr(float c);

	// 设置右侧投影向量的颜色
	void
		set_cr(const RGBColor &_cr);

	// 设置材质的镜面反射系数
	void
		set_ks(float _ks);

	// 设置材质的镜面反射颜色
	void
		set_cs(float r, float g, float b);

	// 设置材质的镜面反射颜色
	void
		set_cs(float c);

	// 设置材质的镜面反射颜色
	void
		set_cs(const RGBColor &_cs);

	// 设置Phong指数
	void
		set_exp(float _exp);

	// 计算光照
	virtual RGBColor
		shade(ShadeRec *sr);

	// 克隆为Material
	virtual Material*
		clone(void) const;

	void
		print(void) const;

private:

	Lambertian *ambient_brdf; // 环境光
	Lambertian *diffuse_brdf; // 漫射光
	GlossySpecular *specular_brdf; // 镜面光
};

// 设置材质的环境光反射系数
inline void
	Phong::set_ka(float _ka) {
		ambient_brdf->set_kd(_ka);
}

// 设置材质的漫反射系数
inline void
	Phong::set_kd(float _kd) {
		diffuse_brdf->set_kd(_kd);
}

// 设置材质的漫反射颜色
inline void
	Phong::set_cd(float r, float g, float b) {
		ambient_brdf->set_cd(r, g, b);
		diffuse_brdf->set_cd(r, g, b);
		specular_brdf->set_cs(r, g, b);
}

// 设置材质的漫反射颜色
inline void
	Phong::set_cd(float c) {
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
		//specular_brdf->set_cs(c);
}

// 设置材质的漫反射颜色
inline void
	Phong::set_cd(const RGBColor &_cd) {
		ambient_brdf->set_cd(_cd);
		diffuse_brdf->set_cd(_cd);
		specular_brdf->set_cs(_cd);
}

// 设置样本
inline void
	Phong::set_sampler(Sampler *_sampler, double _exp) {
		specular_brdf->set_sampler(_sampler, _exp);
}

// 设置样本
inline void
	Phong::set_samples(int _num_samples, double _exp) {
		specular_brdf->set_samples(_num_samples, _exp);
}

// 设置右侧投影向量的颜色
inline void
	Phong::set_cr(float r, float g, float b) {
		specular_brdf->set_cr(r, g, b);
}

// 设置右侧投影向量的颜色
inline void
	Phong::set_cr(float c) {
		specular_brdf->set_cr(c);
}

// 设置右侧投影向量的颜色
inline void
	Phong::set_cr(const RGBColor &_cr) {
		specular_brdf->set_cr(_cr);
}

// 设置材质的镜面反射系数
inline void
	Phong::set_ks(float _ks) {
		specular_brdf->set_ks(_ks);
}

// 设置材质的镜面反射颜色
inline void
	Phong::set_cs(float r, float g, float b) {
		specular_brdf->set_cs(r, g, b);
}

// 设置材质的镜面反射颜色
inline void
	Phong::set_cs(float c) {
		specular_brdf->set_cs(c);
}

// 设置材质的镜面反射颜色
inline void
	Phong::set_cs(const RGBColor &_cs) {
		specular_brdf->set_cs(_cs);
}

// 设置Phong指数
inline void
	Phong::set_exp(float _exp) {
		specular_brdf->set_exp(_exp);
}

#endif