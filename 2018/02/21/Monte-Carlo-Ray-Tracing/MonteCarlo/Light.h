#ifndef __LIGHT__
#define __LIGHT__

#include <iostream>
using namespace std;

#include "Constants.h"
#include "RGBColor.h"
#include "Vector3D.h"
#include "Ray.h"

class ShadeRec;

class Light {
public:

	Light(void);
	Light(const Light &copy);

	virtual
		~Light(void);

	Light&
		operator= (const Light &rhs);

	virtual float
		G(ShadeRec *sr) const;

	// ���������pdf����
	virtual float
		pdf(ShadeRec *sr) const;

	// ������������
	virtual RGBColor
		L(ShadeRec *sr);

	// �����Ӱ�����Ƿ�����ײ��Ͳ�����֮��Ķ�������ײ
	virtual bool
		in_shadow(const Ray &ray, const ShadeRec *sr);

	// ��¡ΪLight
	virtual Light*
		clone(void) const = 0;

	// ������ײ�㴦�Ĺ��߷���
	virtual Vector3D
		get_direction(const ShadeRec *sr) = 0;

	void
		print(void) const;
};

#endif