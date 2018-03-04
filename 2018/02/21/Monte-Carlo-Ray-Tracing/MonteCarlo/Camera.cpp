#include "Camera.h"

Camera::Camera(void)
	: eye(0, 0, 500), lookat(0), ra(0), up(0, 1, 0),
	u(1, 0, 0), v(0, 1, 0), w(0, 0, 1), exposure_time(1.0) {

}

Camera::Camera(const Camera &copy)
	: eye(copy.eye), lookat(copy.lookat), ra(copy.ra),
	up(copy.up), u(copy.u), v(copy.v), w(copy.w),
	exposure_time(copy.exposure_time) {

}

Camera::~Camera(void) {

}

Camera&
	Camera::operator= (const Camera &rhs) {
		if (this == &rhs)
			return (*this);

		eye = rhs.eye;
		lookat = rhs.lookat;
		ra = rhs.ra;
		up = rhs.up;
		u = rhs.u;
		v = rhs.v;
		w = rhs.w;
		exposure_time = rhs.exposure_time;

		return (*this);
}


// 计算正交基向量
void
	Camera::compute_uvw(void) {
		w = eye - lookat;
		w.normalize();
		u = up ^ w;
		u.normalize();
		v = w ^ u;

		if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y) {
			u = Vector3D(0, 0, 1);
			v = Vector3D(1, 0, 0);
			w = Vector3D(0, 1, 0);
		}

		if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) {
			u = Vector3D(1, 0, 0);
			v = Vector3D(0, 0, 1);
			w = Vector3D(0, -1, 0);
		}
}

void
	Camera::print(void) const {
		cout << "eye: "; eye.print();
		cout << "lookat: "; lookat.print();
		cout << "ra = " << ra << endl;
		cout << "u: "; u.print();
		cout << "v: "; v.print();
		cout << "w: "; w.print();
		cout << "up: "; up.print();
		cout << "exposure_time = " << exposure_time << endl;
}