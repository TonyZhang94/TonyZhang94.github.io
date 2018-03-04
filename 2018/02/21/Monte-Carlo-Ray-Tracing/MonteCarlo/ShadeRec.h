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

	bool hit_an_object; // �����Ƿ�����������
	Material *material_ptr; // ���ϵ�ָ��
	Point3D hit_point; // ������������ײ��
	Point3D local_hit_point; // �������������
	Normal normal; // ���㴦�ķ�����
	Ray ray; // ����
	int depth; // ���
	RGBColor color; // ������ɫ��Ϣ������
	double t;
	float u;
	float v;
	World *w; // shade����
};

#endif