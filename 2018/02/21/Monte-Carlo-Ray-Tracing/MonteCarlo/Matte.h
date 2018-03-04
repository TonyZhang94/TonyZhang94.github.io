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

	// �������
	virtual RGBColor
		shade(ShadeRec *sr);

	// �����������
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// ��¡ΪMaterial
	virtual Material*
		clone(void) const;

	void
		print(void) const;
private:

	Lambertian *ambient_brdf; // ������
	Lambertian *diffuse_brdf; // �����
};

// ���ò��ʵĻ����ⷴ��ϵ��
inline void
	Matte::set_ka(float _ka) {
		ambient_brdf->set_kd(_ka);
}

// ���ò��ʵ�������ϵ��
inline void
	Matte::set_kd (float _kd) {
		diffuse_brdf->set_kd(_kd);
}

// ���ò��ʵ���������ɫ
inline void
	Matte::set_cd(float r, float g, float b) {
		ambient_brdf->set_cd(r, g, b);
		diffuse_brdf->set_cd(r, g, b);
}

// ���ò��ʵ���������ɫ
inline void
	Matte::set_cd(float c) {
		ambient_brdf->set_cd(c);
		diffuse_brdf->set_cd(c);
}

// ���ò��ʵ���������ɫ
inline void
	Matte::set_cd(const RGBColor &_cd) {
		ambient_brdf->set_cd(_cd);
		diffuse_brdf->set_cd(_cd);
}

#endif