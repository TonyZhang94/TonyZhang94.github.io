#ifndef __CPOLYGONTABLE
#define __CPOLYGONTABLE

#include "CPolygon.h"

class CPolygonTable {
public:
	CPolygon *head;
public:
	CPolygonTable();

	// �����µĶ���νڵ�
	void insertPoly(CPolygon *node);
	// ɾ��ָ������νڵ�
	void removePoly(CPolygon *node);

	void printCPolygonTable();
};

#endif