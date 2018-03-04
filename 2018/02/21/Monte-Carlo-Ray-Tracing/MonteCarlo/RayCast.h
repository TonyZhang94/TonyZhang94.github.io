#ifndef __RAYCAST__
#define __RAYCAST__

#include "Tracer.h"

class RayCast : public Tracer {
public:

	RayCast(void);
	RayCast(World *_world_ptr);
	RayCast(const RayCast &copy);

	virtual
		~RayCast(void);

	RayCast&
		operator= (const RayCast &rhs);

	virtual RGBColor
		trace_ray(const Ray &ray, int depth) const;

	void
		print(void) const;
};

#endif