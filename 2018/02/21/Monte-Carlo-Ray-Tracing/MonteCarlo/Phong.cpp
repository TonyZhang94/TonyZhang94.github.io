#include "Phong.h"
#include "World.h"

Phong::Phong(void)
	: Material(), ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian), specular_brdf(new GlossySpecular) {

}

Phong::Phong(const Phong &copy)
	: Material(copy) {
		if(NULL != copy.ambient_brdf)
			ambient_brdf = copy.ambient_brdf->clone();
		else
			ambient_brdf = NULL;

		if(NULL != copy.diffuse_brdf)
			diffuse_brdf = copy.diffuse_brdf->clone();
		else
			diffuse_brdf = NULL;

		if(NULL != copy.specular_brdf)
			specular_brdf = copy.specular_brdf->clone();
		else
			specular_brdf = NULL;
}

Phong::~Phong(void) {
	if (NULL != ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if (NULL != diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}

	if (NULL != specular_brdf) {
		delete specular_brdf;
		specular_brdf = NULL;
	}
}

Phong&
	Phong::operator= (const Phong &rhs) {
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

		if (NULL != specular_brdf) {
			delete specular_brdf;
			specular_brdf = NULL;
		}

		if (NULL != rhs.specular_brdf)
			specular_brdf = rhs.specular_brdf->clone();

		return (*this);
}

// 计算光照
RGBColor
	Phong::shade(ShadeRec *sr) {
		Vector3D wo = -sr->ray.d;
		RGBColor L = ambient_brdf->rho(sr, wo) * sr->w->ambient_ptr->L(sr);
		int num_lights = sr->w->lights.size();

		for (int j = 0;j < num_lights;j++) {
			Vector3D wi = sr->w->lights[j]->get_direction(sr);
			float ndotwi = sr->normal * wi;

			if (0.0 < ndotwi) {
				bool in_shadow = false;

				Ray shadowRay(sr->hit_point,wi);
				in_shadow = sr->w->lights[j]->in_shadow(shadowRay,sr);

				if (!in_shadow)
					L += (diffuse_brdf->f(sr, wo, wi) + specular_brdf->f(sr, wo, wi)) * sr->w->lights[j]->L(sr) * ndotwi;
			}
		}

		return L;
		// return black;
}

// 克隆为Material
Material*
	Phong::clone(void) const {
		return new Phong(*this);
}

void
	Phong::print(void) const {
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

		if (NULL != specular_brdf) {
			cout << "specular_brdf:" << endl;
			specular_brdf->print();
		}
		else
			cout << "specular_brdf is NULL" << endl;
};