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

// ���㷢������
RGBColor
	Material::get_Le(ShadeRec *sr) const {
		return black;
}

// �������
RGBColor
	Material::shade(ShadeRec *sr) {
		return black;
}

// �����������
RGBColor
	Material::area_light_shade(ShadeRec *sr) {
		return black;
}

void
	Material::print(void) const {
		cout << "Material" << endl;
}