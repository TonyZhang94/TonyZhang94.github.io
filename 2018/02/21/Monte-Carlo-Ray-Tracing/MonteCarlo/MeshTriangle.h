#ifndef __MESHTRIANGLE__
#define __MESHTRIANGLE__

#include "GeometricObject.h"
#include "Mesh.h"

class MeshTriangle: public GeometricObject {
public:

	MeshTriangle(void);
	MeshTriangle(Mesh *_mesh_ptr, int i1, int i2, int i3);
	MeshTriangle(const MeshTriangle &mt);

	virtual
		~MeshTriangle(void);

	MeshTriangle&
		operator= (const MeshTriangle &rhs);

	void
		compute_normal(bool reverse_normal);

	virtual Normal
		get_normal(void) const;

	virtual BBox
		get_bounding_box(void);

	float
		interpolate_u(float beta, float gamma) const;

	float  
		interpolate_v(float beta, float gamma) const;

	virtual	bool
		shadow_hit(const Ray &ray, double &tmin) const;

	virtual bool
		hit(const Ray &ray, double &tmin, ShadeRec &sr) const = 0;

	virtual MeshTriangle*
		clone(void) const = 0;

	void
		print(void) const;

public:

	Mesh *mesh_ptr; // �洢��������
	int index0; // �����ж������������
	int index1;
	int index2;
	Normal normal; // ����
	float area;	// �����͸����
};

#endif