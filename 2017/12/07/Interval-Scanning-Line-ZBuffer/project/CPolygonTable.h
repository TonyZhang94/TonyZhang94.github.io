#ifndef __CPOLYGONTABLE
#define __CPOLYGONTABLE

#include "CPolygon.h"

class CPolygonTable {
public:
	CPolygon *head;
public:
	CPolygonTable();

	// 插入新的多边形节点
	void insertPoly(CPolygon *node);
	// 删除指定多边形节点
	void removePoly(CPolygon *node);

	void printCPolygonTable();
};

#endif