#include "Rectangle.h"

Rectangle::Rectangle(void)
	: GeometricObject(), sampler_ptr(NULL), p0(-1, 0, -1), a(0, 0, 2),
	b(2, 0, 0), a_len_squared(4.0), b_len_squared(4.0), normal(0, 1, 0),
	area(4.0), inv_area(0.25) {

}

Rectangle::Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b)
	: GeometricObject(), sampler_ptr(NULL), p0(_p0), a(_a), b(_b),
	a_len_squared(a.modeLengthSquart()), b_len_squared(b.modeLengthSquart()),
	area(a.modeLength() * b.modeLength()), inv_area(1.0 / area) {
		normal = a ^ b;
		normal.normalize();
}

Rectangle::Rectangle(const Point3D &_p0, const Vector3D &_a, const Vector3D &_b, const Normal &_normal)
	: GeometricObject(), sampler_ptr(NULL), p0(_p0), a(_a), b(_b),
	a_len_squared(a.modeLengthSquart()), b_len_squared(b.modeLengthSquart()),
	normal(_normal), area(a.modeLength() * b.modeLength()), inv_area(1.0 / area) {
		normal.normalize();
}

Rectangle::Rectangle (const Rectangle &copy)
	: GeometricObject(copy), p0(copy.p0), a(copy.a), b(copy.b),
	a_len_squared(copy.a_len_squared), b_len_squared(copy.b_len_squared),	
	normal(copy.normal), area(copy.area), inv_area(copy.inv_area) {
		if(NULL != copy.sampler_ptr)
			sampler_ptr	= copy.sampler_ptr->clone();
		else
			sampler_ptr = NULL;
}

const double Rectangle::kEpsilon = 0.001;

Rectangle::~Rectangle (void) {
	GeometricObject::~GeometricObject();

	if (NULL != sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
}

Rectangle&
	Rectangle::operator= (const Rectangle &rhs) {
		if (this == &rhs)
			return (*this);

		GeometricObject::operator=(rhs);

		p0 = rhs.p0;
		a = rhs.a;
		b = rhs.b;
		a_len_squared = rhs.a_len_squared;
		b_len_squared = rhs.b_len_squared;
		area = rhs.area;
		inv_area = rhs.inv_area;
		normal = rhs.normal;

		if (NULL != sampler_ptr) {
			delete sampler_ptr;
			sampler_ptr = NULL;
		}

		if (NULL != rhs.sampler_ptr)
			sampler_ptr= rhs.sampler_ptr->clone();

		return (*this);
}

// 设置采样器
void
	Rectangle::set_sampler(Sampler *_sampler_ptr) {
		sampler_ptr = _sampler_ptr;
}

// 采样
Point3D
	Rectangle::sample(void) {
		Point2D sample_point = sampler_ptr->sample_unit_square();
		return (p0 + sample_point.x * a + sample_point.y * b);
}

// 存储面积的倒数，调用pdf时返回，减少一次除法操作
float
	Rectangle::pdf(ShadeRec *sr) {	
		return inv_area;
}

// 计算单位法向量
Normal
	Rectangle::get_normal(const Point3D &p) {
		return normal;
}

// 判断光线是否和阴影部分相交
bool
	Rectangle::shadow_hit(const Ray &ray, double &tmin) {
		double t = (p0 - ray.o) * normal / (ray.d * normal);

		if (t <= kEpsilon)
			return false;

		Point3D p = ray.o + t * ray.d;
		Vector3D d = p - p0;

		double ddota = d * a;

		if (ddota < 0.0 || ddota > a_len_squared)
			return false;

		double ddotb = d * b;

		if (ddotb < 0.0 || ddotb > b_len_squared)
			return false;

		tmin = t;

		return true;
}

// 判断光纤和长方形是否相交
bool
	Rectangle::hit(const Ray &ray, double &tmin, ShadeRec *sr) const {
		double t = (p0 - ray.o) * normal / (ray.d * normal);

		if (t <= kEpsilon)
			return false;

		Point3D p = ray.o + t * ray.d;
		Vector3D d = p - p0;

		double ddota = d * a;

		if (ddota < 0.0 || ddota > a_len_squared)
			return false;

		double ddotb = d * b;

		if (ddotb < 0.0 || ddotb > b_len_squared)
			return false;

		tmin = t;
		sr->normal = normal;
		sr->local_hit_point = p;

		return true;
}

// 克隆一个新的指针
Rectangle*
	Rectangle::clone(void) const {
		return new Rectangle(*this);
}

void
	Rectangle::print(void) const {
		GeometricObject::print();

		cout << "Rectangle:" << endl;
		if (NULL != sampler_ptr) {
			cout << "sampler_ptr:" << endl;
			sampler_ptr->print();
		}
		else
			cout << "sampler_ptr is NULL" << endl;

		cout << "p0: "; p0.print();
		cout << "a: "; a.print(); cout << "a_len_squared = " << a_len_squared << endl;
		cout << "b: "; b.print(); cout << "b_len_squared = " << b_len_squared << endl;
		cout << "normal: "; normal.print();
		cout << "area = " << area << endl;
		cout << "inv_area = " << inv_area << endl;
}