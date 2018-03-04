#ifndef __AREALIGHTING__
#define __AREALIGHTING__

#include "Tracer.h"

class AreaLighting : public Tracer {
public:

	AreaLighting(void);
	AreaLighting(World *_world_ptr);
	AreaLighting(const AreaLighting &copy);

	virtual
		~AreaLighting(void);

	AreaLighting&
		operator= (const AreaLighting &rhs);

	// ¹âÏß×·×Ù¼ÆËã
	virtual RGBColor
		trace_ray(const Ray &ray, int depth) const;

	void
		print(void) const;
};

#endif