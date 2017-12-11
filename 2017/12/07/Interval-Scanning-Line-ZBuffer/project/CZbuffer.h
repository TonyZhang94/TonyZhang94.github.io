#ifndef __CZBUFFER
#define __CZBUFFER

#include "CFile.h"
#include "CVertex.h"
#include "CFace.h"
#include "CEdge.h"
#include "CEdgeTable.h"
#include "CActiveEdge.h"
#include "CActiveEdgeTable.h"
#include "CPolygon.h"
#include "CPolygonTable.h"

#include<map>
#include<vector>
#include <iostream>
using namespace std;

// ����ṹ��
struct intersection {
	float x; // ����x����
	int polyId; // �������ڶ����
};

class CZbuffer {
public:
	CFile *objFile; // obj�ļ�����ĵ����Ƭ����

	vector<CPolygon> PolygonList; // PT
	map<int, vector<CEdge> > EdgeList; // ET

	map<int, vector<float> > AET; // AET
	map<int, vector<int> > IPL; // IPL

	// ������ֵ����
	int maxx;
	int minx;
	int maxy;
	int miny;

	// �����������򳤿�
	int sizex;
	int sizey;

	//ActivePolygonList* actPolygonList;
	//ActiveEdgeList* actEdgeList;

public:
	CZbuffer();
	// ����ET��PT
	CZbuffer(CFile *pfile);

	// �����߱�ET
	void makeEdgeList();
	// ��������α�PT
	void makePolygonList();
	
	// ɨ�裬ɨ������ѡ��ĺͶ���εĸ����󽻵㣬����AET��IPL
	void scan();
	//void rotate(int flag); // ��ת����д����CFile��
};

#endif