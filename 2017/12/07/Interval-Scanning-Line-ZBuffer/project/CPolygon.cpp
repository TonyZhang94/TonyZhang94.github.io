#include "CPolygon.h"
#include <iostream>
using namespace std;

CPolygon::CPolygon() {
	polyId = -1;

	a = 0.0;
	b = 0.0;
	c = 0.0;
	d = 0.0;

	R = 0;
	G = 0;
	B = 0;

	////dzx = 0.0;
	////dzy = 0.0;

	inFlag = false;

	nextPoly = NULL;

	cout << "不要使用默认参数初始化CPolygon" << endl;
}

CPolygon::CPolygon(float ma, float mb, float mc, float md, int mR, int mG, int mB) {
	static int rank = 1;
	polyId = rank;
	rank++;

	a = ma;
	b = mb;
	c = mc;
	d = md;

	R = mR;
	G = mG;
	B = mB;

	//if (0 != c) {
	//	dzx = - a / c;
	//	dzy = b / c;
	//}
	//else {
	//	dzx = 0;
	//	dzy = 0;
	//}

	inFlag = false;

	nextPoly = NULL;
}

void CPolygon::printPolygon() {
	cout << endl << "polyId = " << polyId << endl;
	cout << "a=" << a << "; b=" << b << "; c=" << c << "; d=" << d << endl;
	cout << "R=" << R << "; G=" << G << "; B=" << B << endl;
	//cout << "dzx=" << dzx << "; dzy=" << dzy << endl;
}