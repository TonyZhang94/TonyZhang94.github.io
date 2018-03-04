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

	vector<Point3D> vertices; // 顶点
	vector<Normal> normals; // 每个顶点处的法向
	vector<float> u; // 坐标u
	vector<float> v; // 坐标v
	vector<vector<int>> vertex_faces; // 被顶点共享的面
	int num_vertices; // 顶点的数目
	int num_triangles; // 三角形网格数目
};

#endif