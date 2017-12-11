#ifndef __CZBUFFER
#define __CZBUFFER

#include "CFile.h"
#include "CVertex.h"
#include "CFace.h"
#include "CEdge.h"
#include "CEdgeTable.h"
#include "CActiveEdge.h"
#include "CActiveEdgeTable.h"
#include "CPolygon.h"
#include "CPolygonTable.h"

#include<map>
#include<vector>
#include <iostream>
using namespace std;

// 交点结构体
struct intersection {
	float x; // 交点x坐标
	int polyId; // 交点属于多边形
};

class CZbuffer {
public:
	CFile *objFile; // obj文件读入的点和面片数据

	vector<CPolygon> PolygonList; // PT
	map<int, vector<CEdge> > EdgeList; // ET

	map<int, vector<float> > AET; // AET
	map<int, vector<int> > IPL; // IPL

	// 保存最值坐标
	int maxx;
	int minx;
	int maxy;
	int miny;

	// 物体所在区域长宽
	int sizex;
	int sizey;

	//ActivePolygonList* actPolygonList;
	//ActiveEdgeList* actEdgeList;

public:
	CZbuffer();
	// 建立ET和PT
	CZbuffer(CFile *pfile);

	// 建立边表ET
	void makeEdgeList();
	// 建立多边形表PT
	void makePolygonList();
	
	// 扫描，扫描线有选择的和多边形的各边求交点，建立AET和IPL
	void scan();
	//void rotate(int flag); // 旋转函数写到了CFile下
};

#endif