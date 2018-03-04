#ifndef __EMISSIVE__
#define __EMISSIVE__

#include "World.h"
#include "Material.h"
#include "Lambertian.h"

class Emissive : public Material {
public:

	Emissive(void);
	Emissive(const Emissive &copy);

	~Emissive(void);

	Emissive&
		operator= (const Emissive &rhs);

	// 设置缩放因子
	void
		set_ls(float _ls);

	// 设置自发光颜色值
	void
		set_ce(float r, float g, float b);

	// 设置自发光颜色值
	void
		set_ce(float c);

	// 设置自发光颜色值
	void
		set_ce(const RGBColor &_ce);

	// 计算发射辐射度
	virtual
		RGBColor get_Le(ShadeRec *sr) const;

	// 计算光照
	virtual RGBColor
		shade(ShadeRec *sr);

	// 计算区域光照
	virtual RGBColor
		area_light_shade(ShadeRec *sr);

	// 克隆为Material
	virtual Material*
		clone(void) const;

	void
		print(void) const;

private:

	float ls; // 缩放因子
	RGBColor ce; // 自发光颜色值
};

// 设置缩放因子
inline void
	Emissive::set_ls(float _ls) {
		ls = _ls;
}

// 设置自发光颜色值
inline void
	Emissive::set_ce(float r, float g, float b) {
		ce.r = r;
		ce.g = g;
		ce.b = b;
}

// 设置自发光颜色值
inline void
	Emissive::set_ce(float c) {
		ce.r = c;
		ce.g = c;
		ce.b = c;
}

// 设置自发光颜色值
inline void
	Emissive::set_ce(const RGBColor &_ce) {
		ce = _ce;
}

#endif