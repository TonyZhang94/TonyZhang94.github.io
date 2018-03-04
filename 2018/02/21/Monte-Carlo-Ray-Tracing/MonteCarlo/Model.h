#ifndef _MODEL
#define _MODEL

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<map>
using namespace std;

struct objMaterial {
	float kd[3];
	float ka[3];
	float tf[3];
	float ni;
	float ks[3];
};

struct Vertex {
	float x, y, z;
};

struct Norm {
	float x, y, z;
};

struct Texture {
	float x, y;
};

struct Face {
	string material;
	int v1, v2, v3, v4;
	int n1, n2, n3, n4;
	int t1, t2, t3, t4;
};

class Model {
public:

	Model(char sc);

	void
		print(void) const;

public:

	// 存储obj和mtl文件数据
	map<string, objMaterial> mtlMap; // 材料
	vector<Vertex> vertexList; // 顶点
	vector<Norm> normList; // 规范
	vector<Texture> texList; // 纹理
	vector<Face> faceList; // 面
};

#endif