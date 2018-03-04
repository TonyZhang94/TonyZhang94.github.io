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

	// ���ò��ʵĻ����ⷴ��ϵ��
	void
		set_ka(float _ka);

	// ���ò��ʵ�������ϵ��
	void
		set_kd(float _kd);

	// ���ò��ʵ���������ɫ
	void
		set_cd(const RGBColor &_cd);

	// ���ò��ʵ���������ɫ
	void
		set_cd(float r, float g, float b);

	// ���ò��ʵ���������ɫ
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

	// ��¡Lambertian
	virtual Lambertian*
		clone(void) const;

	void
		print(void) const;

private:

	float kd; // ���ʵ�������ϵ��
	RGBColor cd; // ���ʵ���������ɫ
};

// ���ò��ʵĻ����ⷴ��ϵ��
inline void
	Lambertian::set_ka(float _ka) {
		kd = _ka;
}

// ���ò��ʵ�������ϵ��
inline void
	Lambertian::set_kd(float _kd) {
		kd = _kd;
}

// ���ò��ʵ���������ɫ
inline void
	Lambertian::set_cd(const RGBColor &_cd) {
		cd = _cd;
}

// ���ò��ʵ���������ɫ
inline void
	Lambertian::set_cd(float r, float g, float b) {
		cd.r = r;
		cd.g = g;
		cd.b = b;
}

// ���ò��ʵ���������ɫ
inline void
	Lambertian::set_cd(float c) {
		cd.r = c;
		cd.g = c;
		cd.b = c;
}

#endif