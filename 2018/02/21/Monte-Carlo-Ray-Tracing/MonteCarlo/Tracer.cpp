#include "Tracer.h"
#include "World.h"

Tracer::Tracer(void)
	: world_ptr(NULL) {

}

Tracer::Tracer(World *_world_ptr)
	: world_ptr(_world_ptr) {

}

Tracer::Tracer(const Tracer &copy) {
	if (NULL != copy.world_ptr)
		world_ptr = copy.world_ptr->clone();
	else
		world_ptr = NULL;
}

Tracer::~Tracer(void) {
	if (NULL != world_ptr) {
		delete world_ptr;
		world_ptr = NULL;
	}
}

Tracer&
	Tracer::operator= (const Tracer &rhs) {
		if (this == &rhs)
			return (*this);

		if (NULL != rhs.world_ptr)
			world_ptr = rhs.world_ptr->clone();
		else
			world_ptr = NULL;

		return (*this);
}

// 光线追踪计算
RGBColor
	Tracer::trace_ray(const Ray &ray) const {
		return black;
}

// 光线追踪计算
RGBColor
	Tracer::trace_ray(const Ray &ray, int depth) const {
		ShadeRec *sr = world_ptr->hit_objects(ray);
		if (sr->hit_an_object) {
			sr->ray = ray;
			return sr->material_ptr->shade(sr);
		}
		else
			return world_ptr->background_color;
}

void
	Tracer::print(void) const {
		world_ptr->print();
}