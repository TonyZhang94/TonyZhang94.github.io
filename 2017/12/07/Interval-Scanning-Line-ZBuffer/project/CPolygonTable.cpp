#include "CPolygonTable.h"
#include <iostream>
using namespace std;

CPolygonTable::CPolygonTable() {
	head = new CPolygon();
	head->nextPoly = NULL;
}

void CPolygonTable::insertPoly(CPolygon *node) {
	// 多边形顺序不影响结果，新节点插入在最前面
	if (NULL == head->nextPoly) {
		head->nextPoly = node;
	}
	else {
		node->nextPoly = head->nextPoly;
		head->nextPoly = node;
	}
}

void CPolygonTable::removePoly(CPolygon *node) {
	CPolygon *p = head;
	CPolygon *q = head->nextPoly;

	while (NULL != q) {
		if (q == node) {
			p->nextPoly = q->nextPoly;
			//free(q);
			return;
		}

		p = q;
		q = q->nextPoly;
	}
}

void CPolygonTable::printCPolygonTable() {
	CPolygon *window = head->nextPoly;

	cout << endl << "CEdgeTable打印：" << endl;
	while (NULL != window) {
		window->printPolygon();
		window = window->nextPoly;
	}
}