#include "CEdge.h"
#include <iostream>
using namespace std;

CEdge::CEdge() {
	edgeId = -1;
	polyId = -1;
	x  = 0.0;
	dx = 0.0;
	dy = 0.0;
	maxy = 0.0;

	nextEdge = NULL;

	//cout << "不要使用默认参数初始化CEdge" << endl;
}

CEdge::CEdge(int ppolyId, float px, float pdx, int pdy, float pmaxy) {
	static int rank = 1;
	edgeId = rank;
	rank++;

	polyId = ppolyId;
	x = px;
	dx = pdx;
	dy = pdy;
	maxy = pmaxy;

	nextEdge = NULL;
}

CEdge CEdge::makeEdge(CVertex v1, CVertex v2, int ppolyId) {
	float px;
	float pdx;
	int pdy;
	float pmaxy;

	// 边上端的x坐标
	px = v1.y > v2.y ? v1.x : v2.x;

	// 两条扫面线之间x坐标的变化量
	if (v1.x != v2.x && v1.y != v2.y) {
		pdx = (v2.x - v1.x) / (v1.y - v2.y);
	}
	else {
		pdx = 0;
	}

	// 还剩多少条扫描线
	pdy = abs((int)(v1.y - v2.y));
	// y坐标最大值，方便扫面线有选择的扫描
	pmaxy = v1.y > v2.y ? v1.y : v2.y;

	return CEdge(ppolyId, px, pdx, pdy, pmaxy);
}

void CEdge::printEdge() {
	cout << endl << "edgeId = " << edgeId << endl;
	cout << "polyId=" << polyId << "; x=" << x << "; dx=" << dx << "; dy=" << dy << "; ymax=" << maxy << endl;
}