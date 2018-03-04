#ifndef __AREALIGHT__
#define __AREALIGHT__

#include "RGBColor.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "Light.h"
#include "Material.h"
#include "GeometricObject.h"

class AreaLight : public Light {
public:

	AreaLight(void);
	AreaLight(const AreaLight &copy);

	virtual
		~AreaLight(void);

	AreaLight&
		operator= (const AreaLight &rhs);

	// ��������ָ��
	void
		set_object_ptr(GeometricObject *_object_ptr);

	// �����Է������ָ��
	void
		set_material_ptr(const Material *_material_ptr);

	// ���ò�����
	void
		set_sample_point(const Point3D _sample_point);

	// ���ôӹ��߽��㵽������ĵ�λ����
	void
		set_wi(const Vector3D _wi);

	// ���ò�����ķ���
	void
		set_light_normal(const Normal _light_normal);

	// cos theta' = -n'j dot wij / d^2
	virtual float
		G(ShadeRec *sr) const;

	// ���õ�ǰ�����pdf����
	virtual float
		pdf(ShadeRec *sr) const;

	// ������ʵķ������ȣ�������ߺͷ������������ײ�治ͬ�򷵻غ�ɫ
	virtual RGBColor
		L(ShadeRec *sr);

	// �����Ӱ�����Ƿ�����ײ��Ͳ�����֮��Ķ�������ײ
	virtual bool
		in_shadow(const Ray &ray, const ShadeRec *sr);

	// ��¡ΪLightָ��
	virtual Light*
		clone(void) const;

	// ������ɫ���������֮��ĵ�λ���򣬲��洢�����㡢�����㴦�ķ���
	virtual Vector3D
		get_direction(const ShadeRec *sr);

	void
		print(void) const;

private:

	GeometricObject *object_ptr; // ����ָ��
	Material *material_ptr; // �Է������ָ��
	Point3D	sample_point; // ������
	Vector3D wi; // �ӹ��߽��㵽������ĵ�λ����
	Normal light_normal; // ������ķ���
};

// ���ò�����
inline void
	AreaLight::set_sample_point(const Point3D _sample_point) {
		sample_point = _sample_point;
}

// ���ôӹ��߽��㵽������ĵ�λ����
inline void
	AreaLight::set_wi(const Vector3D _wi) {
		wi = _wi;
}

// ���ò�����ķ���
inline void
	AreaLight::set_light_normal(const Normal _light_normal) {
		light_normal = _light_normal;
}

#endif