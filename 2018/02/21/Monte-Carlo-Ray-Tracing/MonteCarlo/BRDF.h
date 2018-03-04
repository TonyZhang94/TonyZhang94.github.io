#ifndef __BRDF__
#define __BRDF__

#include "RGBColor.h"
#include "Vector3D.h"
#include "Constants.h"
#include "ShadeRec.h"
#include "Sampler.h"

// SurfaceColor = Emissive + Ambient + Diffuse + Specular 
// 最终表面　　 = 放射光  +  环境光  + 漫反射  + 镜面反射

class BRDF {
public:

	BRDF(void);
	BRDF(const Sampler *_sampler_ptr);
	BRDF(const BRDF &copy);

	virtual ~BRDF(void);

	BRDF&
		operator= (const BRDF &rhs);

	// 设置采用器
	void
		set_sampler(Sampler *sPtr);

	// 通过sr的法向量和wi得到反射方向，进而与入射方向计算颜色
	virtual RGBColor
		f(const ShadeRec *sr, const Vector3D &wo, const Vector3D &wi) const;

	// 计算反射光线方向，保存在wi中
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi) const;

	// 计算反射光线方向，保存在wi中
	virtual RGBColor
		sample_f(const ShadeRec *sr, const Vector3D &wo, Vector3D &wi, float &pdf) const;

	// 双半球反射系数
	virtual RGBColor
		rho(const ShadeRec *sr, const Vector3D &wo) const;

	// 克隆BRDF
	virtual BRDF*
		clone(void)const = 0;

	void
		print(void) const;

protected:

	Sampler *sampler_ptr;
};

#endif