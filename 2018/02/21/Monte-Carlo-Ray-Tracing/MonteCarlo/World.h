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

	// ��������
	void
		build(unsigned char *image, int window_size);

	// ��Ӽ�������
	void
		add_object(GeometricObject *object_ptr);

	// ��ӹ���
	void
		add_light(Light *light_ptr);

	// �����Ƿ�ͼ���������ײ
	ShadeRec*
		hit_objects(const Ray &ray);

	//void
	//	open_window(int hres, int vres) const;

	// ��ɫ
	void
		display_pixel(int row, int col, RGBColor &pc);

	// ��¡
	World*
		clone(void) const;

	void
		print(void) const;

public:

	ViewPlane *vp; // ��ƽ��
	RGBColor background_color; // ����ɫ
	Tracer *tracer_ptr; // ׷����ָ��
	Camera *camera_ptr; // ���ָ��
	vector<GeometricObject*> objects; // ��������
	vector<Light*> lights; // ����
	Light *ambient_ptr; // ������ָ��
	unsigned char *image; // ��������
	Model *model; // ���볡��������
	char sc; // ����ѡ��
};

#endif