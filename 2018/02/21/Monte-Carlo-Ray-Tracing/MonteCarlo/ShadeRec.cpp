#include <iostream>
using namespace std;

#include "ShadeRec.h"

ShadeRec::ShadeRec(World *wr)
	: hit_an_object(false),
	  material_ptr(NULL),
	  hit_point(),
	  local_hit_point(),
	  normal(),
	  ray(),
	  depth(0),
	  color(black),
	  t(0.0),
	  u(0.0),
	  v(0.0),
	  w(wr) {

}

ShadeRec::ShadeRec(ShadeRec &copy)
	: hit_an_object(copy.hit_an_object),
	  material_ptr(copy.material_ptr),
	  hit_point(copy.hit_point),
	  local_hit_point(copy.local_hit_point),
	  normal(copy.normal),
	  ray(copy.ray),
	  depth(copy.depth),
	  color(copy.color),
	  t(copy.t),
	  u(copy.u),
	  v(copy.v),
	  w(copy.w) {

}

ShadeRec::~ShadeRec(void) {
	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}
}

ShadeRec&
	ShadeRec::operator= (const ShadeRec &rhs) {
		if (this == &rhs)
			return (*this);

		hit_an_object = rhs.hit_an_object;
		material_ptr = rhs.material_ptr;
		hit_point = rhs.hit_point;
		local_hit_point = rhs.local_hit_point;
		normal = rhs.normal;
		ray = rhs.ray;
		depth = rhs.depth;
		color = rhs.color;
		t = rhs.t;
		u = rhs.u;
		v = rhs.v;
		w = rhs.w;

		return (*this);
}

void
	ShadeRec::print(void) const {
		cout << "hit_an_object = " << hit_an_object << endl;
		// cout << "material_ptr: "; material_ptr->print();
		cout << "hit_point: "; hit_point.print();
		cout << "local_hit_point: "; local_hit_point.print();

		cout << "normal: "; normal.print();
		cout << "ray: "; ray.print();
		cout << "depth = " << depth << endl;
		cout << "color: "; color.print();

		cout << "t = " << t << endl;
		cout << "u = " << u << endl;
		cout << "v = " << v << endl;
		// cout << "w: "; w->print();
}