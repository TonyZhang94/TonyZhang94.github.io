#ifndef __CEDGE
#define __CEDGE

#include "CVertex.h"

class CEdge {
public:
	int edgeId; // ��id
	int polyId; // �����ڵ���id
	float x; // ��ʼΪ���϶˵�x���꣬��ɨ������в��ϱ仯
	float dx; // ����ɨ����֮��x����ı仯��
	int dy; // ��ʣ������ɨ����
	float maxy; // y�������ֵ������ɨ������ѡ���ɨ��

	CEdge *nextEdge; // ����ṹ�����ں�vector���ʹ��
public:
	CEdge();
	CEdge(int polyId, float x, float dx, int dy, float maxy);

	// �������㹹��һ����
	CEdge makeEdge(CVertex v1, CVertex v2, int polyId);
	void printEdge();
};

#endif