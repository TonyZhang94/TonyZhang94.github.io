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
		set_exp(float _exp);

	// �����������
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// ��¡ΪGlossyReflector
	GlossyReflector*
		GlossyReflector::clone(void) const;

	void
		print(void) const;

private:

	GlossySpecular *glossy_specular_brdf;  // �����
};

// ��������
inline void
	GlossyReflector::set_sampler(Sampler *_sampler, double _exp) {
		glossy_specular_brdf->set_sampler(_sampler, _exp);
}

// ��������
inline void
	GlossyReflector::set_samples(int _num_samples, double _exp) {
		glossy_specular_brdf->set_samples(_num_samples, _exp);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	GlossyReflector::set_cr(float r, float g, float b) {
		glossy_specular_brdf->set_cr(r, g, b);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	GlossyReflector::set_cr(float c) {
		glossy_specular_brdf->set_cr(c);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	GlossyReflector::set_cr(const RGBColor &_cr) {
		glossy_specular_brdf->set_cr(_cr);
}

// ���ò��ʵľ��淴��ϵ��
inline void
	GlossyReflector::set_ks(float _ks) {
		glossy_specular_brdf->set_ks(_ks);
}

// ���ò��ʵľ��淴����ɫ
inline void
	GlossyReflector::set_cs(float r, float g, float b) {
		glossy_specular_brdf->set_cs(r, g, b);
}

// ���ò��ʵľ��淴����ɫ
inline void
	GlossyReflector::set_cs(float c) {
		glossy_specular_brdf->set_cs(c);
}

// ���ò��ʵľ��淴����ɫ
inline void
	GlossyReflector::set_cs(const RGBColor &_cs) {
		glossy_specular_brdf->set_cs(_cs);
}

// ����Phongָ��
inline void
	GlossyReflector::set_exp(float _exp) {
		glossy_specular_brdf->set_exp(_exp);
}

#endif