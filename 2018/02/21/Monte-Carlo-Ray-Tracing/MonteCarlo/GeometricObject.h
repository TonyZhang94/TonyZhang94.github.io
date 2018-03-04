#ifndef __GEOMETRICOBJECT__
#define __GEOMETRICOBJECT__

#include <math.h>

#include "Constants.h"
#include "RGBColor.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "BBox.h"
#include "Sampler.h"

class Material;

class GeometricObject {
public:

	GeometricObject(void);
	GeometricObject(const GeometricObject &copy);

	virtual
		~GeometricObject(void);

	GeometricObject&
		operator= (const GeometricObject &rhs);

	// ���ò���
	virtual void
		set_material(Material *_material_ptr);

	// ��ȡ����
	Material*
		get_material(void) const;

	// ���ò�����
	virtual void
		set_sampler(Sampler *_sampler_ptr);

	//Sampler*
	//	get_sampler(void) const;

	// �����µ�����
	virtual void
		add_object(GeometricObject *object_ptr);

	// ����
	virtual Point3D
		sample(void);

	virtual float
		pdf(ShadeRec *sr);

	// ���㷨��
	virtual Normal
		get_normal(void) const;

	// ���㷨��
	virtual Normal
		get_normal(const Point3D &p);

	// �����Ƿ�����Ӱ�ཻ
	virtual bool
		shadow_hit(const Ray &ray, double &tmin);

	// �����Ƿ��������ཻ
	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec *sr) const = 0;

	// ��¡
	virtual GeometricObject*
		clone(void) const = 0;

	void
		print(void) const;

protected:

	Material *material_ptr; // ����ָ��
	Sampler *sampler_ptr; // ������ָ��
	RGBColor color; // ������ɫ
};

#endif