#ifndef __TRACER__
#define __TRACER__

#include"Constants.h"
#include "ShadeRec.h"

class World;

class Tracer {
public:

	Tracer(void);
	Tracer(World *_world_ptr);
	Tracer(const Tracer &copy);

	virtual
		~Tracer(void);

	Tracer&
		operator= (const Tracer & rhs);

	// 光线追踪计算
	virtual RGBColor
		trace_ray(const Ray &ray) const;

	// depth用于模拟反射和透明度
	virtual RGBColor
		trace_ray(const Ray &ray, int depth) const;

	void
		print(void) const;

public:

	World *world_ptr;
};

#endif