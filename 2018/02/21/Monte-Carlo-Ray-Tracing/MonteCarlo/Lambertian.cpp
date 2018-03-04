#include "Lambertian.h"

Lambertian::Lambertian(void)
	: BRDF(), kd(0.0), cd(0.0) {

}

Lambertian::Lambertian(float _kd, const RGBColor &_cd)
	: BRDF(), kd(_kd), cd(_cd) {

}

Lambertian::Lambertian(float _kd, float r, float g, float b)
	: BRDF(), kd(_kd), cd(RGBColor(r, g, b)) {

}

Lambertian::Lambertian(const Lambertian &copy)
	: BRDF(copy), kd(copy.kd), cd(copy.cd) {

}

Lambertian::~Lambertian() {

}

Lambertian&
	Lambertian::operator= (const Lambertian &rhs) {
		if (this == &rhs)
			return (*this);

		BRDF::operator= (rhs);
		kd = rhs.kd;
		cd = rhs.cd;

		return (*this);
}

// kd * cd / pi
RGBColor
	Lambertian::f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const {
		return cd * kd * invPI;
}

// wi, kd * cd / (n dot product wi)
RGBColor
	Lambertian::sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const {
		Vector3D w = sr->normal;
		Vector3D v = Vector3D(0.0034, 1, 0.0071) ^ w;
		v.normalize();
		Vector3D u = v ^ w;

		Point3D sp = sampler_ptr->sample_hemisphere();
		wi = sp.x * u + sp.y * v + sp.z * w;
		wi.normalize();

		pdf = sr->normal * wi * invPI;

		return cd * kd * invPI;
}

// kd * cd
RGBColor
	Lambertian::rho(const ShadeRec *sr, const Vector3D &wo) const {
		return cd * kd;
}

Lambertian*
	Lambertian::clone(void) const {
		return new Lambertian(*this);
}

void
	Lambertian::print(void) const {
		cout << "Lambertian" << endl;

		cout << "kd = " << kd << endl;
		cout << "cd: "; cd.print();

		BRDF::print();
}