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

	// �洢obj��mtl�ļ�����
	map<string, objMaterial> mtlMap; // ����
	vector<Vertex> vertexList; // ����
	vector<Norm> normList; // �淶
	vector<Texture> texList; // ����
	vector<Face> faceList; // ��
};

#endif