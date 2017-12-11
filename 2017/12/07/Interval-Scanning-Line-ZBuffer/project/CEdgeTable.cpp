#include "CEdgeTable.h"
#include <iostream>
using namespace std;

CEdgeTable::CEdgeTable() {
	head = new CEdge();
	head->nextEdge = NULL;
}

void CEdgeTable::insertEdge(CEdge *node) {
	// 由于边的顺序无需紧要，新节点插入在开头位置
	if (NULL == head->nextEdge) {
		head->nextEdge = node;
	}
	else {
		node->nextEdge = head->nextEdge;
		head->nextEdge = node;
	}
}

void CEdgeTable::removeEdge(CEdge *node) {
	CEdge *p = head;
	CEdge *q = head->nextEdge;

	while (NULL != q) {
		if (q == node) {
			p->nextEdge = q->nextEdge;
			delete q;
			return;
		}

		p = q;
		q = q->nextEdge;
	}
}

void CEdgeTable::removeCompletedEdge() {
	CEdge *p = head;
	CEdge *q = head->nextEdge;

	while (NULL != q) {
		q->dy -= 1;
		// dy <= 0，改变已被扫描完，接下来的不会再被扫描
		if (q->dy <= 0) {
			p->nextEdge = q->nextEdge;
			//free(q);
			q = p->nextEdge;
		}
		else {
			p = q;
			q = q->nextEdge;
		}
	}
}

void CEdgeTable::printCEdgeTable() {
	CEdge *window = head->nextEdge;

	cout << endl << "CEdgeTable打印：" << endl;
	while (NULL != window) {
		window->printEdge();
		window = window->nextEdge;
	}
}