#ifndef __CEDGE
#define __CEDGE

#include "CVertex.h"

class CEdge {
public:
	int edgeId; // 边id
	int polyId; // 边属于的面id
	float x; // 初始为边上端的x坐标，在扫描过程中不断变化
	float dx; // 两条扫面线之间x坐标的变化量
	int dy; // 还剩多少条扫描线
	float maxy; // y坐标最大值，方便扫面线有选择的扫描

	CEdge *nextEdge; // 链表结构，后期和vector配合使用
public:
	CEdge();
	CEdge(int polyId, float x, float dx, int dy, float maxy);

	// 用两个点构造一条边
	CEdge makeEdge(CVertex v1, CVertex v2, int polyId);
	void printEdge();
};

#endif