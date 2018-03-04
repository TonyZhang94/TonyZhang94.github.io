#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "Constants.h"
#include "GeometricObject.h"

class Triangle : public GeometricObject {
public:

	Triangle(void);
	Triangle(const Point3D &_v0, const Point3D &_v1, const Point3D &_v2);
	Triangle(const Triangle &copy);

	~Triangle(void);

	Triangle&
		operator= (const Triangle &rhs);

	// ���ò�����
	virtual void
		set_sampler(Sampler *sampler);

	// ����
	virtual Point3D
		sample(void);

	// ���㵥λ������
	void
		compute_normal(void);

	// �жϹ����Ƿ����Ӱ�����ཻ
	virtual bool
		shadow_hit(const Ray &ray, double &tmin);

	// �жϹ��˺��������Ƿ��ཻ
	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec *sr) const;

	// ��¡һ���µ�ָ��
	virtual Triangle*
		clone(void) const;

	void
		print(void) const;

public:

	Sampler *sampler_ptr;
	Point3D	v0, v1, v2; // ��������������
	Normal normal; // �����η���
};

#endif