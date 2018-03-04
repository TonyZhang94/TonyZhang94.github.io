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

	// �����ӵ�
	void
		set_eye(const Point3D &_eye);

	// �����ӵ�
	void
		set_eye(float x, float y, float z);

	// ���ù۲��
	void
		set_lookat(const Point3D &_lookat);

	// ���ù۲��
	void
		set_lookat(float x, float y, float z);

	// ����ra
	void
		set_ra(float _ra);

	// ���������������
	void
		compute_uvw(void);

	// ����up����
	void
		set_up_vector(const Vector3D &_up);

	// ����up����
	void
		set_up_vector(float x, float y, float z);

	// �����ع�ʱ��
	void
		set_exposure_time(float _exposure_time);

	// ��¡
	virtual Camera*
		clone(void) const = 0;

	// ��Ⱦ
	virtual void
		render_scene(World *wr) = 0;

	void
		print(void) const;

public:

	Point3D eye; // �ӵ�
	Point3D lookat; // �۲��
	float ra;
	Vector3D u, v, w; // ����������
	Vector3D up; // up����
	float exposure_time; // �ع�ʱ��
};

// �����ӵ�
void inline
	Camera::set_eye(const Point3D &_eye) {
		eye = _eye;
}

// �����ӵ�
void inline
	Camera::set_eye(float x, float y, float z) {
		eye.x = x;
		eye.y = y;
		eye.z = z;
}

// ���ù۲��
void inline
	Camera::set_lookat(const Point3D &_lookat) {
		lookat = _lookat;
}

// ���ù۲��
void inline
	Camera::set_lookat(float x, float y, float z) {
		lookat.x = x;
		lookat.y = y;
		lookat.z = z;
}

// ����ra
void inline
	Camera::set_ra(float _ra) {
		ra = _ra;
}

// ����up����
void inline
	Camera::set_up_vector(const Vector3D &_up) {
		up = _up;
}

// ����up����
void inline
	Camera::set_up_vector(float x, float y, float z) {
		up.x = x;
		up.y = y;
		up.z = z;
}

// �����ع�ʱ��
void inline
	Camera::set_exposure_time(float _exposure_time) {
		exposure_time = _exposure_time;
}

#endif