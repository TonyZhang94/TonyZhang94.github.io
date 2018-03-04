#ifndef __WORLD__
#define __WORLD__

#include "RGBColor.h"

#include "Light.h"
#include "AreaLight.h"
#include "Ambient.h"

#include "Emissive.h"
#include "Matte.h"
#include "Phong.h"
#include "GlossyReflector.h"

#include "GlossySpecular.h"

#include "ViewPlane.h"

#include "Triangle.h"
#include "Sphere.h"
#include "Rectangle.h"

#include "Model.h"

#include "Tracer.h"
#include "AreaLighting.h"
#include "RayCast.h"

#include "Camera.h"
#include "Pinhole.h"

#include<vector>
#include <iostream>
using namespace std;

class World {
public:

	World(void);
	World(Model *_model, char _sc);

	~World(void);

	// 构建场景
	void
		build(unsigned char *image, int window_size);

	// 添加几何物体
	void
		add_object(GeometricObject *object_ptr);

	// 添加光线
	void
		add_light(Light *light_ptr);

	// 光线是否和几何物体碰撞
	ShadeRec*
		hit_objects(const Ray &ray);

	//void
	//	open_window(int hres, int vres) const;

	// 着色
	void
		display_pixel(int row, int col, RGBColor &pc);

	// 克隆
	World*
		clone(void) const;

	void
		print(void) const;

public:

	ViewPlane *vp; // 视平面
	RGBColor background_color; // 背景色
	Tracer *tracer_ptr; // 追踪器指针
	Camera *camera_ptr; // 相机指针
	vector<GeometricObject*> objects; // 几何物体
	vector<Light*> lights; // 光线
	Light *ambient_ptr; // 环境光指针
	unsigned char *image; // 场景画面
	Model *model; // 读入场景的数据
	char sc; // 场景选择
};

#endif