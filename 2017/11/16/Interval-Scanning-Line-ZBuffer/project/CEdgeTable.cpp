#include "CEdgeTable.h"
#include <iostream>
using namespace std;

CEdgeTable::CEdgeTable() {
	head = new CEdge();
	head->nextEdge = NULL;
}

void CEdgeTable::insertEdge(CEdge *node) {
	// ���ڱߵ�˳�������Ҫ���½ڵ�����ڿ�ͷλ��
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
		// dy <= 0���ı��ѱ�ɨ���꣬�������Ĳ����ٱ�ɨ��
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

	cout << endl << "CEdgeTable��ӡ��" << endl;
	while (NULL != window) {
		window->printEdge();
		window = window->nextEdge;
	}
}