#include "Pinhole.h"

Pinhole::Pinhole(void)		
	: Camera(), d(500), zoom(1.0) {

}

Pinhole::Pinhole(const Pinhole &copy)   		
	: Camera(copy), d(copy.d), zoom(copy.zoom) {

}

Pinhole::~Pinhole(void) {
	Camera::~Camera();
}

Pinhole&
	Pinhole::operator= (const Pinhole &rhs) {
		if (this == &rhs)
			return (*this);

		Camera::operator= (rhs);

		d = rhs.d;
		zoom = rhs.zoom;

		return (*this);
}

// 计算光线方向
Vector3D
	Pinhole::get_direction(const Point2D &p) const {
		Vector3D dir = p.x * u + p.y * v - d * w;
		dir.normalize();

		return dir;
}

// 克隆
Camera*
	Pinhole::clone(void) const {
		return new Pinhole(*this);
}

// 渲染
void
	Pinhole::render_scene(World *wr) {
		RGBColor L;
		ViewPlane *vp = wr->vp;
		Ray ray;
		int depth = 0;
		Point2D pp;
		int n = (int)sqrt((float)vp->num_samples);

		vp->s /= zoom;
		ray.o = eye;

		for (int r = 0;r < vp->vres;r++) {
			// cout << "r = " << r << " begin" << endl;
			for (int c = 0;c < vp->hres;c++) {
				L = black;

				for (int p = 0;p < n;p++) {
					for (int q = 0;q < n;q++) {
						pp.x = vp->s * (c - 0.5 * vp->hres + (q + 0.5) / n);
						pp.y = vp->s * (r - 0.5 * vp->vres + (p + 0.5) / n);
						ray.d = get_direction(pp);
						L += wr->tracer_ptr->trace_ray(ray, depth);
					}
				}

				L /= vp->num_samples;
				L *= exposure_time;

				if (L.r > 1)
					L.r = 1;
				if (L.g > 1)
					L.g = 1;
				if (L.b > 1)
					L.b = 1;

				wr->display_pixel(r, c, L);
			}
		}
}

void
	Pinhole::print(void) const {
		Camera::print();
		cout << "d = " << d << endl;
		cout << "zoom = " << zoom << endl;
}