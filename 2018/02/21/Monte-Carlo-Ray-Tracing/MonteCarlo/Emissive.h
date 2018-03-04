#ifndef __EMISSIVE__
#define __EMISSIVE__

#include "World.h"
#include "Material.h"
#include "Lambertian.h"

class Emissive : public Material {
public:

	Emissive(void);
	Emissive(const Emissive &copy);

	~Emissive(void);

	Emissive&
		operator= (const Emissive &rhs);

	// ������������
	void
		set_ls(float _ls);

	// �����Է�����ɫֵ
	void
		set_ce(float r, float g, float b);

	// �����Է�����ɫֵ
	void
		set_ce(float c);

	// �����Է�����ɫֵ
	void
		set_ce(const RGBColor &_ce);

	// ���㷢������
	virtual
		RGBColor get_Le(ShadeRec *sr) const;

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

	float ls; // ��������
	RGBColor ce; // �Է�����ɫֵ
};

// ������������
inline void
	Emissive::set_ls(float _ls) {
		ls = _ls;
}

// �����Է�����ɫֵ
inline void
	Emissive::set_ce(float r, float g, float b) {
		ce.r = r;
		ce.g = g;
		ce.b = b;
}

// �����Է�����ɫֵ
inline void
	Emissive::set_ce(float c) {
		ce.r = c;
		ce.g = c;
		ce.b = c;
}

// �����Է�����ɫֵ
inline void
	Emissive::set_ce(const RGBColor &_ce) {
		ce = _ce;
}

#endif