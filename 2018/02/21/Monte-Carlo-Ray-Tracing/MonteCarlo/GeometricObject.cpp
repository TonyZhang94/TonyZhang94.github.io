#include "Material.h"
#include "GeometricObject.h"


GeometricObject::GeometricObject(void)
	: material_ptr(NULL), sampler_ptr(NULL), color(black) {

}

GeometricObject::GeometricObject(const GeometricObject &copy)
	: color(copy.color) {
		if(NULL != copy.material_ptr)
			material_ptr = copy.material_ptr->clone();
		else
			material_ptr = NULL;

		if(NULL != copy.sampler_ptr)
			sampler_ptr = copy.sampler_ptr->clone();
		else
			sampler_ptr = NULL;
}

GeometricObject::~GeometricObject(void) {
	if (NULL != material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}

	if (NULL != sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
}

GeometricObject&
	GeometricObject::operator= (const GeometricObject &rhs) {
		if (this == &rhs)
			return (*this);

		if (NULL != material_ptr) {
			delete material_ptr;
			material_ptr = NULL;
		}

		if (NULL != rhs.material_ptr)
			material_ptr = rhs.material_ptr->clone();

		if (NULL != sampler_ptr) {
			delete sampler_ptr;
			sampler_ptr = NULL;
		}

		if (NULL != rhs.sampler_ptr)
			sampler_ptr = rhs.sampler_ptr->clone();

		color = rhs.color;

		return (*this);
}

// ���ò���
void
	GeometricObject::set_material(Material* _material_ptr) {
		material_ptr = _material_ptr;
}

// ��ò���
Material*
	GeometricObject::get_material(void) const {
		return material_ptr;
}

// ���ò�����
void
	GeometricObject::set_sampler(Sampler *_sampler_ptr) {
	sampler_ptr = _sampler_ptr;
}

// ���Ӽ������壨��World��ʵ�� add-object ���û���ã�
void
	GeometricObject::add_object(GeometricObject *object_ptr) {
		
}

Point3D
	GeometricObject::sample(void) {
		return Point3D(0.0);
}

float
	GeometricObject::pdf(ShadeRec *sr) {
		return 0.0;
}

// ���㷨��
Normal
	GeometricObject::get_normal(void) const {
		return Normal();
}

// ���㷨��
Normal
	GeometricObject::get_normal(const Point3D &p) {
		return Normal();
}

// �����Ƿ�����Ӱ�ཻ
bool
	GeometricObject::shadow_hit(const Ray &ray, double &tmin) {
		return false;
}

void
	GeometricObject::print(void) const {
		cout << "GeometricObject" << endl;
		if (NULL != material_ptr) {
			cout << "material_ptr:" << endl;
			material_ptr->print();
		}
		else
			cout << "material_ptr is NULL" << endl;

		if (NULL != sampler_ptr) {
			cout << "sampler_ptr:" << endl;
			sampler_ptr->print();
		}
		else
			cout << "sampler_ptr is NULL" << endl;

		color.print();
}