#ifndef __CFILE
#define __CFILE

#include "CVertex.h"
#include "CFace.h"
#include <vector>
#include <string>
using namespace std;

class CFile {
public:
	vector<CFace> FaceList; // ��������Ƭ��
	vector<CVertex> VertexList; // ���
	
	// �����С����
	float maxx;
	float maxy;
	float maxz;
	float minx;
	float miny;
	float minz;

	// �û�ָ��������ڴ�С
	int size;

public:
	// ��ȡobj�ļ�����FaceList��VertexList
	void ReadObj(string path, int size);
	// ���û�ָ��������ڴ�С���ź�ƽ���������
	void Move();
	// ��ת����
	void rotate(float thetax, float thetay);
};

#endif