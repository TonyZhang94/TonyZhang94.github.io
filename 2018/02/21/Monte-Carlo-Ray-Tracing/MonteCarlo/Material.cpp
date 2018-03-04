#include "Material.h"

Material::Material(void) {

}

Material::Material(const Material &copy) {

}

Material::~Material(void) {

}

Material&
	Material::operator= (const Material &rhs) {
		if (this == &rhs)
			return (*this);

		return (*this);
}

// 计算发射辐射度
RGBColor
	Material::get_Le(ShadeRec *sr) const {
		return black;
}

// 计算光照
RGBColor
	Material::shade(ShadeRec *sr) {
		return black;
}

// 计算区域光照
RGBColor
	Material::area_light_shade(ShadeRec *sr) {
		return black;
}

void
	Material::print(void) const {
		cout << "Material" << endl;
}