#ifndef __PINHOLE__
#define __PINHOLE__

#include "Point2D.h"
#include "World.h"

class Pinhole : public Camera {
public:

	Pinhole();
	Pinhole(const Pinhole &copy);

	virtual
		~Pinhole();

	Pinhole&
		operator= (const Pinhole &rhs);

	// 设置视平面距离
	void
		set_d(float _d);

	// 设置缩放系数
	void
		set_zoom(float _zoom);

	// 计算光线方向
	Vector3D
		get_direction(const Point2D &p) const;

	// 克隆
	virtual Camera*
		clone(void) const;

	// 渲染
	virtual void
		render_scene(World *wr);

	void
		print(void) const;

private:

	float d; // 视平面距离
	float zoom; // 缩放系数
};

// 设置视平面距离
void inline
	Pinhole::set_d(float _d) {
		d = _d;
}

// 设置缩放系数
void inline
	Pinhole::set_zoom(float _zoom) {
		zoom = _zoom;
}

#endif