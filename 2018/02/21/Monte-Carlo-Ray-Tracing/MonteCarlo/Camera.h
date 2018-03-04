#ifndef __CAMERA__
#define __CAMERA__

#include "Point3D.h"
#include "Vector3D.h"

#include <iostream>
using namespace std;

class World;

class Camera {
public:

	Camera();
	Camera(const Camera &copy);

	virtual
		~Camera();

	Camera&
		operator= (const Camera &rhs);

	// 设置视点
	void
		set_eye(const Point3D &_eye);

	// 设置视点
	void
		set_eye(float x, float y, float z);

	// 设置观察点
	void
		set_lookat(const Point3D &_lookat);

	// 设置观察点
	void
		set_lookat(float x, float y, float z);

	// 设置ra
	void
		set_ra(float _ra);

	// 计算正交向基量积
	void
		compute_uvw(void);

	// 设置up向量
	void
		set_up_vector(const Vector3D &_up);

	// 设置up向量
	void
		set_up_vector(float x, float y, float z);

	// 设置曝光时间
	void
		set_exposure_time(float _exposure_time);

	// 克隆
	virtual Camera*
		clone(void) const = 0;

	// 渲染
	virtual void
		render_scene(World *wr) = 0;

	void
		print(void) const;

public:

	Point3D eye; // 视点
	Point3D lookat; // 观察点
	float ra;
	Vector3D u, v, w; // 正交基向量
	Vector3D up; // up向量
	float exposure_time; // 曝光时间
};

// 设置视点
void inline
	Camera::set_eye(const Point3D &_eye) {
		eye = _eye;
}

// 设置视点
void inline
	Camera::set_eye(float x, float y, float z) {
		eye.x = x;
		eye.y = y;
		eye.z = z;
}

// 设置观察点
void inline
	Camera::set_lookat(const Point3D &_lookat) {
		lookat = _lookat;
}

// 设置观察点
void inline
	Camera::set_lookat(float x, float y, float z) {
		lookat.x = x;
		lookat.y = y;
		lookat.z = z;
}

// 设置ra
void inline
	Camera::set_ra(float _ra) {
		ra = _ra;
}

// 设置up向量
void inline
	Camera::set_up_vector(const Vector3D &_up) {
		up = _up;
}

// 设置up向量
void inline
	Camera::set_up_vector(float x, float y, float z) {
		up.x = x;
		up.y = y;
		up.z = z;
}

// 设置曝光时间
void inline
	Camera::set_exposure_time(float _exposure_time) {
		exposure_time = _exposure_time;
}

#endif