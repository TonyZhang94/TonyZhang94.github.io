#include "CFace.h"
#include <iostream>
using namespace std;

CFace::CFace() {
	fId = -1;

	v1Id = -1;
	v2Id = -1;
	v3Id = -1;

	r = 0;
	g = 0;
	b = 0;

	cout << "不要使用默认参数初始化CFace" << endl;
}

CFace::CFace(int id1, int id2, int id3) {
	static int rank = 1;
	fId = rank;
	rank++;

	v1Id = id1;
	v2Id = id2;
	v3Id = id3;

	// 给面片设定颜色
	r = (fId * 50) % 255;
	g = (fId * 50) % 255;
	b = (fId * 50) % 255;
}

void CFace::printFace() {
	cout << endl << "fId = " << fId << endl;
	cout << "v1Id=" << v1Id << "; v2Id=" << v2Id << "; v3Id=" << v3Id << endl;
	cout << "r=" << r << "; g=" << g << "; b=" << b << endl;
}