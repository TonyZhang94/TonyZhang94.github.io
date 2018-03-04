#include "Emissive.h"

Emissive::Emissive(void)
	: Material(), ls(1), ce(1) {

}

Emissive::Emissive(const Emissive &copy)
	: Material(copy), ls(copy.ls), ce(copy.ce) {

}

Emissive::~Emissive(void) {

}

Emissive&
	Emissive::operator= (const Emissive &rhs) {
		if (this == &rhs)
			return (*this);

		Material::operator=(rhs);
		ls = rhs.ls;
		ce = rhs.ce;

		return (*this);
}

// 计算发射辐射度
RGBColor
	Emissive::get_Le(ShadeRec *sr) const {
		if (0.0 < -sr->normal*sr->ray.d)
			return ce*ls;
		else
			return black;
}

// 计算光照
RGBColor
	Emissive::shade(ShadeRec *sr) {
		return black;
}

// 计算区域光照
RGBColor
	Emissive::area_light_shade(ShadeRec *sr) {
		if (0.0 < -sr->normal*sr->ray.d)
			return ce*ls;
		else
			return black;
}

// 克隆为Material
Material*
	Emissive::clone(void) const {
		return new Emissive(*this);
}

void
	Emissive::print(void) const {
		cout << "Emissive" << endl;
		cout << "ls = " << ls << endl;
		cout << "ce: "; ce.print();
		Material::print();
}