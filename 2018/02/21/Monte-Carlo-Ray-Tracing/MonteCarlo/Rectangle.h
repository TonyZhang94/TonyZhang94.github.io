#ifndef __RECTANGLE__
#define __RECTANGLE__

#include "GeometricObject.h"

class Rectangle : public GeometricObject {
public:

	Rectangle(void);
	Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b);
	Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b, const Normal &_normal);
	Rectangle(const Rectangle &copy);

	virtual
		~Rectangle(void);

	Rectangle&
		operator= (const Rectangle &rhs);

	// ���ò�����
	virtual void
		set_sampler(Sampler *_sampler_ptr);

	// ����
	virtual Point3D
		sample(void);

	// �洢����ĵ���������pdfʱ���أ�����һ�γ�������
	virtual float
		pdf(ShadeRec *sr);

	// ���㵥λ������
	virtual Normal
		get_normal(const Point3D &p);

	// �жϹ����Ƿ����Ӱ�����ཻ
	virtual bool
		shadow_hit(const Ray &ray, double &tmin);

	// �жϹ��˺ͳ������Ƿ��ཻ
	virtual bool
		hit(const Ray &ray, double &t, ShadeRec *s) const;

	// ��¡һ���µ�ָ��
	virtual Rectangle*
		clone(void) const;

	void
		print(void) const;
	
public:

	Sampler *sampler_ptr; // ������
	Point3D p0; // ������һ������
	Vector3D a; // ������a
	Vector3D b; // ������b
	double a_len_squared; // ������a��ƽ��
	double b_len_squared; // ������b��ƽ��
	Normal normal; // ��λ������

	float area; // ���
	float inv_area; // ����ĵ���

	static const double kEpsilon; // Epsilon
};

#endif