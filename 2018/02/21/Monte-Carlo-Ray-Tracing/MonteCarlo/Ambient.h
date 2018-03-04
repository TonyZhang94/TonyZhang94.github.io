#ifndef __AMBIENT__
#define __AMBIENT__

#include "Light.h"

class Ambient : public Light {
public:

	Ambient(void);
	Ambient(const Ambient &copy);

	virtual
		~Ambient(void);

	Ambient&
		operator= (const Ambient &rhs);

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

	// ls * ce
	virtual RGBColor
		L(ShadeRec *sr);

	// ��¡ΪLight
	virtual Light*
		clone(void) const;

	// Ambient��get_direction������ù������͵���ؼ���
	virtual Vector3D
		get_direction(const ShadeRec *sr);
	
	void
		print(void) const;

private:

	float ls; // ��������
	RGBColor ce; // �Է�����ɫֵ
};

// ������������
inline void
	Ambient::set_ls(float _ls) {
		ls = _ls;
}

// �����Է�����ɫֵ
inline void
	Ambient::set_ce(float r, float g, float b) {
		ce.r = r;
		ce.g = g;
		ce.b = b;
}

// �����Է�����ɫֵ
inline void
	Ambient::set_ce(float c) {
		ce.r = c;
		ce.g = c;
		ce.b = c;
}

// �����Է�����ɫֵ
inline void
	Ambient::set_ce(const RGBColor &_ce) {
		ce = _ce;
}

#endif