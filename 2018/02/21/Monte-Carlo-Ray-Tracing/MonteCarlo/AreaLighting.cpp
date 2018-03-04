#include "AreaLighting.h"
#include "ShadeRec.h"
#include "World.h"

AreaLighting::AreaLighting(void)
	: Tracer() {

}

AreaLighting::AreaLighting(World *_world_ptr)
	: Tracer(_world_ptr) {

}

AreaLighting::AreaLighting(const AreaLighting &copy)
	: Tracer(copy) {

}

AreaLighting::~AreaLighting(void) {
	Tracer::~Tracer();
}

AreaLighting&
	AreaLighting::operator= (const AreaLighting &rhs) {
		Tracer::operator=(rhs);

		return (*this);
}

RGBColor
	AreaLighting::trace_ray(const Ray &ray, int depth) const {
		ShadeRec *sr = world_ptr->hit_objects(ray);

		if (sr->hit_an_object) {
			sr->depth = depth;
			sr->ray = ray;
			return sr->material_ptr->area_light_shade(sr);
		}
		else {
			return world_ptr->background_color;
		}
}

void
	AreaLighting::print(void) const {
		world_ptr->print();
}