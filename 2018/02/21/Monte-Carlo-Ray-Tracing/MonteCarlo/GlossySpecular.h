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

	// ��������
	void
		set_sampler(Sampler *_sampler, double _exp);

	// ��������
	void
		set_samples(int _num_samples, double _exp);

	// �����Ҳ�ͶӰ��������ɫ
	void
		set_cr(float r, float g, float b);

	// �����Ҳ�ͶӰ��������ɫ
	void
		set_cr(float c);

	// �����Ҳ�ͶӰ��������ɫ
	void
		set_cr(const RGBColor &_cr);

	// ���ò��ʵľ��淴��ϵ��
	void
		set_ks(float _ks);

	// ���ò��ʵľ��淴����ɫ
	void
		set_cs(float r, float g, float b);

	// ���ò��ʵľ��淴����ɫ
	void
		set_cs(float c);

	// ���ò��ʵľ��淴����ɫ
	void
		set_cs(const RGBColor &_cs);

	// ����Phongָ��
	void
		set_exp(double _exp);

	// ks * cs * (r dot product wo) ^ exp
	virtual RGBColor
		f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const;

	// wi, ks * cs * (r dot product wo) ^ exp
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const;

	// ��ɫ
	virtual RGBColor
		rho(const ShadeRec *sr, const Vector3D &wo) const;

	// ��¡GlossySpecular
	virtual GlossySpecular*
		clone(void) const;

	void
		print(void) const;

private:
	Sampler *sampler; // ����
	RGBColor cr; // �Ҳ�ͶӰ��������ɫ
	float ks; // ���ʵľ��淴��ϵ��
	RGBColor cs; // ���ʵľ��淴����ɫ
	double exp; // Phongָ��
};

// ��������
inline void
	GlossySpecular::set_sampler(Sampler *_sampler, double _exp) {
		sampler_ptr = _sampler;
		sampler_ptr->map_samples_to_hemisphere(_exp);
}

// ��������
inline void
	GlossySpecular::set_samples(int _num_samples, double _exp) {
		sampler_ptr = new MultiJittered(_num_samples);
		sampler_ptr->map_samples_to_hemisphere(_exp);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	GlossySpecular::set_cr(float r, float g, float b) {
		cr.r = r;
		cr.g = g;
		cr.b = b;
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	GlossySpecular::set_cr(float c) {
		cr.r = c;
		cr.g = c;
		cr.b = c;
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	GlossySpecular::set_cr(const RGBColor &_cr) {
		cr = _cr;
}

// ���ò��ʵľ��淴��ϵ��
inline void
	GlossySpecular::set_ks(float _ks) {
		ks = _ks;
}

// ���ò��ʵľ��淴����ɫ
inline void
	GlossySpecular::set_cs(float r, float g, float b) {
		cs.r = r;
		cs.g = g;
		cs.b = b;
}

// ���ò��ʵľ��淴����ɫ
inline void
	GlossySpecular::set_cs(float c) {
		cs.r = c;
		cs.g = c;
		cs.b = c;
}

// ���ò��ʵľ��淴����ɫ
inline void
	GlossySpecular::set_cs(const RGBColor &_cs) {
		cs = _cs;
}

// ����Phongָ��
inline void
	GlossySpecular::set_exp(double _exp) {
		exp = _exp;
}

#endif