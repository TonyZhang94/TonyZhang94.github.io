#ifndef __ACTIVEEDGETABLE
#define __ACTIVEEDGETABLE

#include "CActiveEdge.h"

class CActiveEdgeTable {
public:
	CActiveEdge *head;
public:
	CActiveEdgeTable();

	// 插入新的活化边
	void insertActEdge(CActiveEdge *node);
	// 删除指定活化边
	void removeActEdge(CActiveEdge *node);

	void printActiveEdgeTable();
};

#endif