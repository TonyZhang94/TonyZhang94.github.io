#ifndef __MATERIAL__
#define __MATERIAL__

#include <iostream>
using namespace std;

#include "Constants.h"
#include "RGBColor.h"
#include "ShadeRec.h"

class Material {
public:

	Material(void);
	Material(const Material &copy);

	virtual
		~Material(void);

	Material&
		operator= (const Material &rhs);

	// ���㷢������
	virtual RGBColor
		get_Le(ShadeRec *sr) const;

	// �������
	virtual RGBColor
		shade(ShadeRec *sr);

	// �����������
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// ��¡Material
	virtual Material*
		clone(void) const = 0;

	void
		print(void) const;
};

#endif