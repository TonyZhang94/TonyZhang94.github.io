#ifndef __ACTIVEEDGETABLE
#define __ACTIVEEDGETABLE

#include "CActiveEdge.h"

class CActiveEdgeTable {
public:
	CActiveEdge *head;
public:
	CActiveEdgeTable();

	// �����µĻ��
	void insertActEdge(CActiveEdge *node);
	// ɾ��ָ�����
	void removeActEdge(CActiveEdge *node);

	void printActiveEdgeTable();
};

#endif