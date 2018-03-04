#include "AreaLight.h"
#include "World.h"

AreaLight::AreaLight(void)
	: Light(), object_ptr(NULL), material_ptr(NULL) {

}

AreaLight::AreaLight(const AreaLight &copy)
	: Light(copy) {
		if(NULL != copy.object_ptr)
			object_ptr = copy.object_ptr->clone();
		else
			object_ptr = NULL;

		if(NULL != copy.material_ptr)
			material_ptr = copy.material_ptr->clone();
		else
			material_ptr = NULL;
}

AreaLight::~AreaLight(void) {
	if (NULL != object_ptr) {
		delete object_ptr;
		object_ptr = NULL;
	}

	if (NULL != material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}
}

AreaLight&
	AreaLight::operator= (const AreaLight &rhs) {
		if (this == &rhs)
			return (*this);

		Light::operator=(rhs);

		if (NULL != object_ptr) {
			delete object_ptr;
			object_ptr = NULL;
		}

		if (NULL != rhs.object_ptr)
			object_ptr = rhs.object_ptr->clone();

		if (NULL != material_ptr) {
			delete material_ptr;
			material_ptr = NULL;
		}

		if (NULL != rhs.material_ptr)
			material_ptr = rhs.material_ptr->clone();

		return (*this);
}

// ��������ָ��
void
	AreaLight::set_object_ptr(GeometricObject *_object_ptr) {
		if (NULL != object_ptr) {
			delete object_ptr;
			object_ptr = NULL;
		}

		object_ptr = _object_ptr;
		material_ptr = object_ptr->get_material();
}

// �����Է������ָ��
void
	AreaLight::set_material_ptr(const Material *_material_ptr) {
		if (NULL != material_ptr) {
			delete material_ptr;
			material_ptr = NULL;
		}

		if (NULL != _material_ptr)
			material_ptr = _material_ptr->clone();
		else
			material_ptr = NULL;
}

// cos theta' = -n'j dot wij / d^2
float
	AreaLight::G(ShadeRec* sr) const {
		float ndotd = -light_normal * wi;
		float d2 = sample_point.distance2(sr->hit_point);

		return ndotd / d2;
}

// ���õ�ǰ�����pdf����
float
	AreaLight::pdf(ShadeRec *sr) const {
		return object_ptr->pdf(sr);
}

// ������ʵķ������ȣ�������ߺͷ������������ײ�治ͬ�򷵻غ�ɫ
RGBColor
	AreaLight::L(ShadeRec *sr) {
		float ndotd = -light_normal * wi;

		if (0.0 < ndotd)
			return material_ptr->get_Le(sr);
		else
			return black;
}

// �����Ӱ�����Ƿ�����ײ��Ͳ�����֮��Ķ�������ײ
bool
	AreaLight::in_shadow(const Ray &ray, const ShadeRec *sr) {
		double t;
		int num_objects = sr->w->objects.size();
		float ts = (sample_point - ray.o) * ray.d;

		for (int j = 0; j < num_objects; j++)
			if (sr->w->objects[j]->shadow_hit(ray, t) && t < ts)
				return true;

		return false;
		// return true;
}

// ��¡ΪLightָ��
Light*
	AreaLight::clone(void) const {
		return new AreaLight(*this);
}

// ������ɫ���������֮��ĵ�λ���򣬲��洢�����㡢�����㴦�ķ���
Vector3D
	AreaLight::get_direction(const ShadeRec *sr) {
		sample_point = object_ptr->sample();
		light_normal = object_ptr->get_normal(sample_point);
		wi = sample_point - sr->hit_point;
		wi.normalize();

		return wi;
}

void
	AreaLight::print(void) const {
		cout << "AreaLight:" << endl;
		if (NULL != object_ptr) {
			cout << "GeometricObject:" << endl;
			object_ptr->print();
		}
		else
			cout << "object_ptr is NULL" << endl;
		if (NULL != material_ptr) {
			cout << "Material:" << endl;
			material_ptr->print();
		}
		else
			cout << "material_ptr is NULL" << endl;
		cout << "sample_point: "; sample_point.print();
		cout << "wi: "; wi.print();
		cout << "light_normal: "; light_normal.print();
}