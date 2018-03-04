#include "GlossyReflector.h"

GlossyReflector::GlossyReflector(void)
	: Phong(), glossy_specular_brdf(new GlossySpecular) {

}

GlossyReflector::GlossyReflector(const GlossyReflector &copy)
	: Phong(copy) {
		if (NULL != copy.glossy_specular_brdf)
			glossy_specular_brdf = copy.glossy_specular_brdf->clone();
		else
			glossy_specular_brdf = NULL;
}

GlossyReflector::~GlossyReflector(void) {
	if (NULL != glossy_specular_brdf) {
		delete glossy_specular_brdf;
		glossy_specular_brdf = NULL;
	}
}

GlossyReflector&
	GlossyReflector::operator= (const GlossyReflector &rhs) {
		if (this == &rhs)
			return (*this);

		Material::operator=(rhs);

		if (NULL != glossy_specular_brdf) {
			delete glossy_specular_brdf;
			glossy_specular_brdf = NULL;
		}

		if (NULL != rhs.glossy_specular_brdf)
			glossy_specular_brdf = rhs.glossy_specular_brdf->clone();
}

// 计算区域光照
RGBColor
	GlossyReflector::area_light_shade(ShadeRec* sr) {
		RGBColor L(Phong::area_light_shade(sr));  
		Vector3D wo(-sr->ray.d);
		Vector3D wi;
		float pdf;
		RGBColor fr(glossy_specular_brdf->sample_f(sr, wo, wi, pdf));
		Ray reflected_ray(sr->hit_point, wi);

		L += fr * sr->w->tracer_ptr->trace_ray(reflected_ray, sr->depth + 1) * (sr->normal * wi) / pdf;

		return L;
		// return black;
}

// 克隆为GlossyReflector
GlossyReflector*
	GlossyReflector::clone(void) const {
		return new GlossyReflector(*this);
}

void
	GlossyReflector::print(void) const {
		Phong::print();
		if (NULL != glossy_specular_brdf) {
			cout << "glossy_specular_brdf:" << endl;
			glossy_specular_brdf->print();
		}
		else
			cout << "glossy_specular_brdf is NULL" << endl;
}