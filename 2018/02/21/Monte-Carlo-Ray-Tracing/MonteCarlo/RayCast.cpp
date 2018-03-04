#include "RayCast.h"
#include "ShadeRec.h"
#include "World.h"

RayCast::RayCast(void)
	: Tracer() {

}

RayCast::RayCast(World *_world_ptr)
	: Tracer(_world_ptr) {

}

RayCast::RayCast(const RayCast &copy)
	: Tracer(copy) {

}

RayCast::~RayCast(void) {
	Tracer::~Tracer();
}

RayCast&
	RayCast::operator= (const RayCast &rhs) {
		Tracer::operator=(rhs);

		return (*this);
}

RGBColor
	RayCast::trace_ray(const Ray &ray, int depth) const {
		ShadeRec *sr = world_ptr->hit_objects(ray);

		if (sr->hit_an_object) {
			sr->ray = ray;
			return sr->material_ptr->shade(sr);
		}   
		else {
			return world_ptr->background_color;
		}
}

void
	RayCast::print(void) const {
		world_ptr->print();
}