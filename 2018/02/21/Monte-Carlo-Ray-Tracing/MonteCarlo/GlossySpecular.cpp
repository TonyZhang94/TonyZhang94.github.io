#include "GlossySpecular.h"

GlossySpecular::GlossySpecular(void) 
	: sampler(NULL), cr(white), ks(0.0), cs(1.0), exp(0.0) {

}

GlossySpecular::GlossySpecular(const GlossySpecular &copy) 
	: sampler(copy.sampler), cr(copy.cr), ks(copy.ks), cs(copy.cs), exp(copy.exp) {

}

GlossySpecular::~GlossySpecular(void) {

}

GlossySpecular&
	GlossySpecular::operator= (const GlossySpecular &rhs) {
		if (this == &rhs)
			return (*this);

		BRDF::operator= (rhs);
		sampler = rhs.sampler;
		cr = rhs.cr;
		ks = rhs.ks;
		cs = rhs.cs;
		exp = rhs.exp;

		return (*this);
}

// ks * cs * (r dot product wo) ^ exp
RGBColor
	GlossySpecular::f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const {
		RGBColor L;
		float ndotwi = sr->normal * wi;
		Vector3D r(-wi+2.0*sr->normal*ndotwi);
		float rdotwo = r * wo;

		if (rdotwo > 0.0)
			L = cs * ks * pow(rdotwo, float(exp));
		return L;
}

// wi, ks * cs * (r dot product wo) ^ exp
RGBColor
	GlossySpecular::sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const {
		float ndotwo = sr->normal * wo;

		Vector3D r = -wo + 2.0 * sr->normal * ndotwo;     
		Vector3D w = r;								
		Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w; 
		u.normalize();
		Vector3D v = u ^ w;

		Point3D sp = sampler_ptr->sample_hemisphere();
		wi = sp.x * u + sp.y * v + sp.z * w;			

		if (sr->normal * wi < 0.0) 						
			wi = -sp.x * u - sp.y * v + sp.z * w;

		float phong_lobe = pow(r*wi, exp);
		pdf = phong_lobe * (sr->normal * wi);

		return cs * ks * phong_lobe;
}

// ºÚÉ«
RGBColor
	GlossySpecular::rho(const ShadeRec *sr, const Vector3D &wo) const {
		return black;
}

// ¿ËÂ¡GlossySpecular
GlossySpecular*
	GlossySpecular::clone (void) const {
		return new GlossySpecular(*this);
}

void
	GlossySpecular::print(void) const {
		cout << "GlossySpecular" << endl;

		if (NULL != sampler) {
			cout << "sampler: "; sampler->print();
		}
		else
			cout << "sampler is NULL" << endl;
		cout << "cr: "; cr.print();
		cout << "ks = " << ks << endl;
		cout << "cs: "; cs.print();
		cout << "exp = " << exp << endl;

		BRDF::print();
}