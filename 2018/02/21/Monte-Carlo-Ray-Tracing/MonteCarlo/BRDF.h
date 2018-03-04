#ifndef __BRDF__
#define __BRDF__

#include "RGBColor.h"
#include "Vector3D.h"
#include "Constants.h"
#include "ShadeRec.h"
#include "Sampler.h"

// SurfaceColor = Emissive + Ambient + Diffuse + Specular 
// ���ձ��桡�� = �����  +  ������  + ������  + ���淴��

class BRDF {
public:

	BRDF(void);
	BRDF(const Sampler *_sampler_ptr);
	BRDF(const BRDF &copy);

	virtual ~BRDF(void);

	BRDF&
		operator= (const BRDF &rhs);

	// ���ò�����
	void
		set_sampler(Sampler *sPtr);

	// ͨ��sr�ķ�������wi�õ����䷽�򣬽��������䷽�������ɫ
	virtual RGBColor
		f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const;

	// ���㷴����߷��򣬱�����wi��
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi) const;

	// ���㷴����߷��򣬱�����wi��
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const;

	// ˫������ϵ��
	virtual RGBColor
		rho(const ShadeRec *sr, const Vector3D &wo) const;

	// ��¡BRDF
	virtual BRDF*
		clone(void)const = 0;

	void
		print(void) const;

protected:

	Sampler *sampler_ptr;
};

#endif