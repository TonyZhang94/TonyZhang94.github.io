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
	
	// ���ò��ʵĻ����ⷴ��ϵ��
	void
		set_ka(float _ka);

	// ���ò��ʵ�������ϵ��
	void
		set_kd(float _kd);

	// ���ò��ʵ���������ɫ
	void
		set_cd(float r, float g, float b);

	// ���ò��ʵ���������ɫ
	void
		set_cd(float c);

	// ���ò��ʵ���������ɫ
	void
		set_cd(const RGBColor &_cd);

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

	// �������
	virtual RGBColor
		shade(ShadeRec *sr);

	// ��¡ΪMaterial
	virtual Material*
		clone(void) const;

	void
		print(void) const;

private:

	Lambertian *ambient_brdf; // ������
	Lambertian *diffuse_brdf; // �����
	GlossySpecular *specular_brdf; // �����
};

// ���ò��ʵĻ����ⷴ��ϵ��
inline void
	Phong::set_ka(float _ka) {
		ambient_brdf->set_kd(_ka);
}

// ���ò��ʵ�������ϵ��
inline void
	Phong::set_kd(float _kd) {
		diffuse_brdf->set_kd(_kd);
}

// ���ò��ʵ���������ɫ
inline void
	Phong::set_cd(float r, float g, float b) {
		ambient_brdf->set_cd(r, g, b);
		diffuse_brdf->set_cd(r, g, b);
		specular_brdf->set_cs(r, g, b);
}

// ���ò��ʵ���������ɫ
inline void
	Phong::set_cd(float c) {
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
		//specular_brdf->set_cs(c);
}

// ���ò��ʵ���������ɫ
inline void
	Phong::set_cd(const RGBColor &_cd) {
		ambient_brdf->set_cd(_cd);
		diffuse_brdf->set_cd(_cd);
		specular_brdf->set_cs(_cd);
}

// ��������
inline void
	Phong::set_sampler(Sampler *_sampler, double _exp) {
		specular_brdf->set_sampler(_sampler, _exp);
}

// ��������
inline void
	Phong::set_samples(int _num_samples, double _exp) {
		specular_brdf->set_samples(_num_samples, _exp);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	Phong::set_cr(float r, float g, float b) {
		specular_brdf->set_cr(r, g, b);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	Phong::set_cr(float c) {
		specular_brdf->set_cr(c);
}

// �����Ҳ�ͶӰ��������ɫ
inline void
	Phong::set_cr(const RGBColor &_cr) {
		specular_brdf->set_cr(_cr);
}

// ���ò��ʵľ��淴��ϵ��
inline void
	Phong::set_ks(float _ks) {
		specular_brdf->set_ks(_ks);
}

// ���ò��ʵľ��淴����ɫ
inline void
	Phong::set_cs(float r, float g, float b) {
		specular_brdf->set_cs(r, g, b);
}

// ���ò��ʵľ��淴����ɫ
inline void
	Phong::set_cs(float c) {
		specular_brdf->set_cs(c);
}

// ���ò��ʵľ��淴����ɫ
inline void
	Phong::set_cs(const RGBColor &_cs) {
		specular_brdf->set_cs(_cs);
}

// ����Phongָ��
inline void
	Phong::set_exp(float _exp) {
		specular_brdf->set_exp(_exp);
}

#endif