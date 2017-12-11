#ifndef __CEDGETABLE
#define __CEDGETABLE

#include "CEdge.h"

// ET
class CEdgeTable {
public:
	CEdge *head;
public:
	CEdgeTable();

	// �����µı�
	void insertEdge(CEdge *node);
	// ɾ��ָ����
	void removeEdge(CEdge *node);
	// ɾ����ɨ����ı�(dy <= 0)
	void removeCompletedEdge();

	void printCEdgeTable();
};

#endif