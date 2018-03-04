#include "Ambient.h"

Ambient::Ambient(void)
	: Light(), ls(1.0), ce(1.0) {

}

Ambient::Ambient(const Ambient &copy)
	: Light(copy), ls(copy.ls), ce(copy.ce) {

}

Ambient::~Ambient(void) {

}

Ambient&
	Ambient::operator= (const Ambient &rhs) {
		if (this == &rhs)
			return (*this);

		Light::operator= (rhs);
		ls = rhs.ls;
		ce = rhs.ce;

		return (*this);
}

// ls * ce
RGBColor
	Ambient::L(ShadeRec *sr) {
		return ce  *ls;
}

Light*
	Ambient::clone(void) const {
		return new Ambient(*this);
}

// Ambient的get_direction不参与该光照类型的相关计算
Vector3D
	Ambient::get_direction(const ShadeRec *sr) {
		return Vector3D(0.0);
}

void
	Ambient::print(void) const {
		cout << "Ambient" << endl;
		Light::print();
		cout << "ls = " << ls << endl;
		cout << "ce: "; ce.print();
}