#ifndef __MESH__
#define __MESH__

#include <vector>
#include "Point3D.h"
#include "Normal.h"

#include <iostream>
using namespace std;

class Mesh {
public:

	Mesh(void);
	Mesh(const Mesh &copy);

	~Mesh(void);

	Mesh&
		operator= (const Mesh &rhs);

	void
		print(void) const;

public:

	vector<Point3D> vertices; // ����
	vector<Normal> normals; // ÿ�����㴦�ķ���
	vector<float> u; // ����u
	vector<float> v; // ����v
	vector<vector<int>> vertex_faces; // �����㹲�����
	int num_vertices; // �������Ŀ
	int num_triangles; // ������������Ŀ
};

#endif