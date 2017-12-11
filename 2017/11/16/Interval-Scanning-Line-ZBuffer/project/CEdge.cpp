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

	//cout << "��Ҫʹ��Ĭ�ϲ�����ʼ��CEdge" << endl;
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

	// ���϶˵�x����
	px = v1.y > v2.y ? v1.x : v2.x;

	// ����ɨ����֮��x����ı仯��
	if (v1.x != v2.x && v1.y != v2.y) {
		pdx = (v2.x - v1.x) / (v1.y - v2.y);
	}
	else {
		pdx = 0;
	}

	// ��ʣ������ɨ����
	pdy = abs((int)(v1.y - v2.y));
	// y�������ֵ������ɨ������ѡ���ɨ��
	pmaxy = v1.y > v2.y ? v1.y : v2.y;

	return CEdge(ppolyId, px, pdx, pdy, pmaxy);
}

void CEdge::printEdge() {
	cout << endl << "edgeId = " << edgeId << endl;
	cout << "polyId=" << polyId << "; x=" << x << "; dx=" << dx << "; dy=" << dy << "; ymax=" << maxy << endl;
}