#ifndef __GLOSSYREFLECTOR__
#define __GLOSSYREFLECTOR__

#include "World.h"
#include "Phong.h"
#include "GlossySpecular.h"

class GlossyReflector : public Phong {
public:

	GlossyReflector(void);
	GlossyReflector(const GlossyReflector &copy);

	~GlossyReflector(void);

	GlossyReflector&
		operator= (const GlossyReflector &rhs);
	
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

	// 计算区域光照
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// 克隆为GlossyReflector
	GlossyReflector*
		GlossyReflector::clone(void) const;

	void
		print(void) const;

private:

	GlossySpecular *glossy_specular_brdf;  // 镜面光
};

// 设置样本
inline void
	GlossyReflector::set_sampler(Sampler *_sampler, double _exp) {
		glossy_specular_brdf->set_sampler(_sampler, _exp);
}

// 设置样本
inline void
	GlossyReflector::set_samples(int _num_samples, double _exp) {
		glossy_specular_brdf->set_samples(_num_samples, _exp);
}

// 设置右侧投影向量的颜色
inline void
	GlossyReflector::set_cr(float r, float g, float b) {
		glossy_specular_brdf->set_cr(r, g, b);
}

// 设置右侧投影向量的颜色
inline void
	GlossyReflector::set_cr(float c) {
		glossy_specular_brdf->set_cr(c);
}

// 设置右侧投影向量的颜色
inline void
	GlossyReflector::set_cr(const RGBColor &_cr) {
		glossy_specular_brdf->set_cr(_cr);
}

// 设置材质的镜面反射系数
inline void
	GlossyReflector::set_ks(float _ks) {
		glossy_specular_brdf->set_ks(_ks);
}

// 设置材质的镜面反射颜色
inline void
	GlossyReflector::set_cs(float r, float g, float b) {
		glossy_specular_brdf->set_cs(r, g, b);
}

// 设置材质的镜面反射颜色
inline void
	GlossyReflector::set_cs(float c) {
		glossy_specular_brdf->set_cs(c);
}

// 设置材质的镜面反射颜色
inline void
	GlossyReflector::set_cs(const RGBColor &_cs) {
		glossy_specular_brdf->set_cs(_cs);
}

// 设置Phong指数
inline void
	GlossyReflector::set_exp(float _exp) {
		glossy_specular_brdf->set_exp(_exp);
}

#endif