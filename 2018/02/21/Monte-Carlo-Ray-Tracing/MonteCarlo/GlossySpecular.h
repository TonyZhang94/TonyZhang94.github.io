#ifndef __GLOSSYSPECULAR__
#define __GLOSSYSPECULAR__

#include <algorithm>

#include "Maths.h"
#include "MultiJittered.h"
#include "BRDF.h"

class GlossySpecular : public BRDF {
public:

	GlossySpecular(void);
	GlossySpecular(const GlossySpecular &copy);

	~GlossySpecular(void);

	GlossySpecular&
		operator= (const GlossySpecular &rhs);

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
		set_exp(double _exp);

	// ks * cs * (r dot product wo) ^ exp
	virtual RGBColor
		f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const;

	// wi, ks * cs * (r dot product wo) ^ exp
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const;

	// 黑色
	virtual RGBColor
		rho(const ShadeRec *sr, const Vector3D &wo) const;

	// 克隆GlossySpecular
	virtual GlossySpecular*
		clone(void) const;

	void
		print(void) const;

private:
	Sampler *sampler; // 采样
	RGBColor cr; // 右侧投影向量的颜色
	float ks; // 材质的镜面反射系数
	RGBColor cs; // 材质的镜面反射颜色
	double exp; // Phong指数
};

// 设置样本
inline void
	GlossySpecular::set_sampler(Sampler *_sampler, double _exp) {
		sampler_ptr = _sampler;
		sampler_ptr->map_samples_to_hemisphere(_exp);
}

// 设置样本
inline void
	GlossySpecular::set_samples(int _num_samples, double _exp) {
		sampler_ptr = new MultiJittered(_num_samples);
		sampler_ptr->map_samples_to_hemisphere(_exp);
}

// 设置右侧投影向量的颜色
inline void
	GlossySpecular::set_cr(float r, float g, float b) {
		cr.r = r;
		cr.g = g;
		cr.b = b;
}

// 设置右侧投影向量的颜色
inline void
	GlossySpecular::set_cr(float c) {
		cr.r = c;
		cr.g = c;
		cr.b = c;
}

// 设置右侧投影向量的颜色
inline void
	GlossySpecular::set_cr(const RGBColor &_cr) {
		cr = _cr;
}

// 设置材质的镜面反射系数
inline void
	GlossySpecular::set_ks(float _ks) {
		ks = _ks;
}

// 设置材质的镜面反射颜色
inline void
	GlossySpecular::set_cs(float r, float g, float b) {
		cs.r = r;
		cs.g = g;
		cs.b = b;
}

// 设置材质的镜面反射颜色
inline void
	GlossySpecular::set_cs(float c) {
		cs.r = c;
		cs.g = c;
		cs.b = c;
}

// 设置材质的镜面反射颜色
inline void
	GlossySpecular::set_cs(const RGBColor &_cs) {
		cs = _cs;
}

// 设置Phong指数
inline void
	GlossySpecular::set_exp(double _exp) {
		exp = _exp;
}

#endif