#ifndef __CEDGETABLE
#define __CEDGETABLE

#include "CEdge.h"

// ET
class CEdgeTable {
public:
	CEdge *head;
public:
	CEdgeTable();

	// 插入新的边
	void insertEdge(CEdge *node);
	// 删除指定边
	void removeEdge(CEdge *node);
	// 删除被扫面完的边(dy <= 0)
	void removeCompletedEdge();

	void printCEdgeTable();
};

#endif