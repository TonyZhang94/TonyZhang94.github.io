#include "CVertex.h"
#include <iostream>
using namespace std;

CVertex::CVertex() {
	vId = -1;

	x = 0.0;
	y = 0.0;
	z = 0.0;

	cout << "��Ҫʹ��Ĭ�ϲ�����ʼ��CVertex" << endl;
}

CVertex::CVertex(float X, float Y, float Z) {
	static int rank = 1;
	vId = rank;
	rank++;

	x = X;
	y = Y;
	z = Z;
}

void CVertex::printVertex() {
	cout << endl << "vId = " << vId << endl;
	cout << "x=" << x << "; y=" << y << "; z=" << z << endl;
}