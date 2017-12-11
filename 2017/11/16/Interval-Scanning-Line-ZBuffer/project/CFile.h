#ifndef __CFILE
#define __CFILE

#include "CVertex.h"
#include "CFace.h"
#include <vector>
#include <string>
using namespace std;

class CFile {
public:
	vector<CFace> FaceList; // 三角形面片表
	vector<CVertex> VertexList; // 点表
	
	// 最大最小坐标
	float maxx;
	float maxy;
	float maxz;
	float minx;
	float miny;
	float minz;

	// 用户指定结果窗口大小
	int size;

public:
	// 读取obj文件构造FaceList和VertexList
	void ReadObj(string path, int size);
	// 按用户指定结果窗口大小缩放和平移物体各点
	void Move();
	// 旋转物体
	void rotate(float thetax, float thetay);
};

#endif