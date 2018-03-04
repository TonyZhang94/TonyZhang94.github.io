#ifndef __SHADEREC__
#define __SHADEREC__

#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBColor.h"
#include "Constants.h"
// #include "Material.h"
// #include "World.h"

class Material;
class World;

class ShadeRec {
public:

	ShadeRec(World *wr);
	ShadeRec(ShadeRec &copy);

	~ShadeRec(void);

	ShadeRec&
		operator= (const ShadeRec &rhs);

	void
		print(void) const;

public:

	bool hit_an_object; // 光线是否与物体相遇
	Material *material_ptr; // 材料的指针
	Point3D hit_point; // 光线与物体碰撞点
	Point3D local_hit_point; // 交点的世界坐标
	Normal normal; // 交点处的法向量
	Ray ray; // 光线
	int depth; // 深度
	RGBColor color; // 交点着色信息，弃用
	double t;
	float u;
	float v;
	World *w; // shade世界
};

#endif