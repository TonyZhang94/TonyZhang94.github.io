#include "Triangle.h"

Triangle::Triangle(void)
	: GeometricObject(), sampler_ptr(NULL), v0(0, 0, 0), v1(0,0,1), v2(1,0,0), normal(0, 1, 0) {

}

Triangle::Triangle(const Point3D &_v0, const Point3D &_v1, const Point3D &v2)
	: GeometricObject(), sampler_ptr(NULL), v0(_v0), v1(_v1), v2(v2), normal(0, 1, 0) {
		compute_normal();
}

Triangle::Triangle(const Triangle &copy)
	: GeometricObject(copy), sampler_ptr(copy.sampler_ptr), v0(copy.v0), v1(copy.v1), v2(copy.v2), normal(copy.normal) {

}

Triangle::~Triangle(void) {
	GeometricObject::~GeometricObject();

	if (NULL != sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
}

Triangle&
	Triangle::operator= (const Triangle &rhs) {
		if (this == &rhs)
			return (*this);

		GeometricObject::operator=(rhs);

		v0 = rhs.v0;
		v1 = rhs.v1;
		v2 = rhs.v2;
		normal = rhs.normal;

		return (*this);
}

// 设置采样器
void
	Triangle::set_sampler(Sampler *sampler) {
		sampler_ptr = sampler;
}

// 采样
Point3D
	Triangle::sample(void) {
		Point2D sample_point = sampler_ptr->sample_unit_square();
		return v0 + sample_point.x * (v2-v0) + sample_point.y * (v1-v0);
}

// 计算单位法向量
void
	Triangle::compute_normal(void) {
		normal = (v1 - v0) ^ (v2 - v0);
		normal.normalize();
}

// 判断光线是否和阴影部分相交
bool
	Triangle::shadow_hit(const Ray &ray, double &tmin) {
		double a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
		double e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
		double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.z - ray.o.z;

		double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
		double q = g * i - e * k, s = e * j - f * i;

		double inv_denom  = 1.0 / (a * m + b * q + c * s);

		double e1 = d * m - b * n - c * p;
		double beta = e1 * inv_denom;

		if (beta < 0.0)
			return false;

		double r = e * l - h * i;
		double e2 = a * n + d * q + c * r;
		double gamma = e2 * inv_denom;

		if (gamma < 0.0)
			return false;

		if (beta + gamma > 1.0)
			return false;

		double e3 = a * p - b * r + d * s;
		double t = e3 * inv_denom;

		if (t < kEpsilon)
			return false;

		tmin = t;

		return true;
}

// 判断光纤和三角形是否相交
bool
	Triangle::hit(const Ray &ray, double &tmin, ShadeRec *sr) const {
		double a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
		double e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
		double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.z - ray.o.z;

		double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
		double q = g * i - e * k, s = e * j - f * i;

		double inv_denom  = 1.0 / (a * m + b * q + c * s);

		double e1 = d * m - b * n - c * p;
		double beta = e1 * inv_denom;

		if (beta < 0.0)
			return false;

		double r = r = e * l - h * i;
		double e2 = a * n + d * q + c * r;
		double gamma = e2 * inv_denom;

		if (gamma < 0.0)
			return false;

		if (beta + gamma > 1.0)
			return false;

		double e3 = a * p - b * r + d * s;
		double t = e3 * inv_denom;

		if (t < kEpsilon)
			return false;

		tmin = t;
		sr->normal = normal;
		sr->local_hit_point = ray.o + t * ray.d;

		return true;
}

// 克隆一个新的指针
Triangle*
	Triangle::clone(void) const {
		return new Triangle(*this);
}

void
	Triangle::print(void) const {
		GeometricObject::print();

		cout << "Triangle:" << endl;
		if (NULL != sampler_ptr) {
			cout << "sampler_ptr" << endl;
			sampler_ptr->print();
		}
		else
			cout << "sampler_ptr is NULL" << endl;

		cout << "v0:"; v0.print();
		cout << "v1:"; v1.print();
		cout << "v2:"; v2.print();

		cout << "normal:"; normal.print();
}