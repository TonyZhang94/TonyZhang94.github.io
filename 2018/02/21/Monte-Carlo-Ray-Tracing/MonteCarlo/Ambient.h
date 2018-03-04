#ifndef __AMBIENT__
#define __AMBIENT__

#include "Light.h"

class Ambient : public Light {
public:

	Ambient(void);
	Ambient(const Ambient &copy);

	virtual
		~Ambient(void);

	Ambient&
		operator= (const Ambient &rhs);

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

	// ls * ce
	virtual RGBColor
		L(ShadeRec *sr);

	// 克隆为Light
	virtual Light*
		clone(void) const;

	// Ambient的get_direction不参与该光照类型的相关计算
	virtual Vector3D
		get_direction(const ShadeRec *sr);
	
	void
		print(void) const;

private:

	float ls; // 缩放因子
	RGBColor ce; // 自发光颜色值
};

// 设置缩放因子
inline void
	Ambient::set_ls(float _ls) {
		ls = _ls;
}

// 设置自发光颜色值
inline void
	Ambient::set_ce(float r, float g, float b) {
		ce.r = r;
		ce.g = g;
		ce.b = b;
}

// 设置自发光颜色值
inline void
	Ambient::set_ce(float c) {
		ce.r = c;
		ce.g = c;
		ce.b = c;
}

// 设置自发光颜色值
inline void
	Ambient::set_ce(const RGBColor &_ce) {
		ce = _ce;
}

#endif