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

	// 计算发射辐射度
	virtual RGBColor
		get_Le(ShadeRec *sr) const;

	// 计算光照
	virtual RGBColor
		shade(ShadeRec *sr);

	// 计算区域光照
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// 克隆Material
	virtual Material*
		clone(void) const = 0;

	void
		print(void) const;
};

#endif