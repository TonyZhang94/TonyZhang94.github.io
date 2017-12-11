#include "CActiveEdgeTable.h"
#include <iostream>
using namespace std;

CActiveEdgeTable::CActiveEdgeTable() {
	head = new CActiveEdge();
	head->nextActEdge = NULL;
}

void CActiveEdgeTable::insertActEdge(CActiveEdge *node) {
	// 由于边的顺序无需紧要，新节点插入在开头位置
	if (NULL == head->nextActEdge) {
		head->nextActEdge = node;
	}
	else {
		node->nextActEdge = head->nextActEdge;
		head->nextActEdge = node;
	}
}

void CActiveEdgeTable::removeActEdge(CActiveEdge *node) {
	CActiveEdge *p = head;
	CActiveEdge *q = head->nextActEdge;

	while (NULL != q) {
		if (q == node) {
			p->nextActEdge = q->nextActEdge;
			//free(q);
			return;
		}

		p = q;
		q = q->nextActEdge;
	}
}

void CActiveEdgeTable::printActiveEdgeTable() {
	CActiveEdge *window = head->nextActEdge;

	cout << endl << "CActiveEdgeTable打印：" << endl;
	while (NULL != window) {
		window->printActiveEdge();
		window = window->nextActEdge;
	}
}