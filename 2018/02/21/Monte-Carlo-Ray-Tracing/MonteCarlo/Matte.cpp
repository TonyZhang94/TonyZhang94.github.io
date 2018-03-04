#include "Matte.h"

Matte::Matte (void)
	: Material(), ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian) {

}

Matte::Matte(const Matte &copy)
	: Material(copy) {
		if(NULL != copy.ambient_brdf)
			ambient_brdf = copy.ambient_brdf->clone();
		else
			ambient_brdf = NULL;

		if(NULL != copy.diffuse_brdf)
			diffuse_brdf = copy.diffuse_brdf->clone();
		else
			diffuse_brdf = NULL;
}

Matte::~Matte(void) {
	if (NULL != ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if (NULL != diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}
}

Matte&
	Matte::operator= (const Matte &rhs) {
		if (this == &rhs)
			return (*this);

		Material::operator=(rhs);

		if (NULL != ambient_brdf) {
			delete ambient_brdf;
			ambient_brdf = NULL;
		}

		if (NULL != rhs.ambient_brdf)
			ambient_brdf = rhs.ambient_brdf->clone();

		if (NULL != diffuse_brdf) {
			delete diffuse_brdf;
			diffuse_brdf = NULL;
		}

		if (NULL != rhs.diffuse_brdf)
			diffuse_brdf = rhs.diffuse_brdf->clone();

		return (*this);
}

// 计算光照
RGBColor
	Matte::shade(ShadeRec *sr) {
		Vector3D wo = -sr->ray.d;
		RGBColor L = ambient_brdf->rho(sr, wo) * sr->w->ambient_ptr->L(sr);
		int num_lights = sr->w->lights.size();

		for (int j = 0;j < num_lights;j++) {
			Vector3D wi = sr->w->lights[j]->get_direction(sr);
			float ndotwi = sr->normal * wi;

			if (0.0 < ndotwi) {
				bool in_shadow = false;

				Ray shadowRay(sr->hit_point, wi);
				in_shadow = sr->w->lights[j]->in_shadow(shadowRay, sr);

				if (!in_shadow)
					L += diffuse_brdf->f(sr, wo, wi) * sr->w->lights[j]->L(sr) * ndotwi;
			}
		}

		return L;
		// return black;
}

// 计算区域光照
RGBColor
	Matte::area_light_shade(ShadeRec *sr) {
		Vector3D wo = -sr->ray.d;
		RGBColor L = ambient_brdf->rho(sr, wo) * sr->w->ambient_ptr->L(sr);
		int num_lights = sr->w->lights.size();

		for (int j = 0;j < num_lights;j++) {
			Vector3D wi = sr->w->lights[j]->get_direction(sr);
			float ndotwi = sr->normal * wi;

			if (0.0 < ndotwi) {
				bool in_shadow = false;

				Ray shadow_ray(sr->hit_point, wi);
				in_shadow = sr->w->lights[j]->in_shadow(shadow_ray, sr);


				if (!in_shadow) {
					L += diffuse_brdf->f(sr, wo, wi) * sr->w->lights[j]->L(sr) * sr->w->lights[j]->G(sr) * ndotwi / sr->w->lights[j]->pdf(sr);
				}
			}
		}

		if (L.r > 1) L.r = 1;
		if (L.g > 1) L.g = 1;
		if (L.b > 1) L.b = 1;

		return L;
		// return black;
}

// 克隆为Material
Material*
	Matte::clone(void) const {
		return new Matte(*this);
}

void
	Matte::print(void) const {
		if (NULL != ambient_brdf) {
			cout << "ambient_brdf:" << endl;
			ambient_brdf->print();
		}
		else
			cout << "ambient_brdf is NULL" << endl;

		if (NULL != diffuse_brdf) {
			cout << "diffuse_brdf:" << endl;
			diffuse_brdf->print();
		}
		else
			cout << "diffuse_brdf is NULL" << endl;
}