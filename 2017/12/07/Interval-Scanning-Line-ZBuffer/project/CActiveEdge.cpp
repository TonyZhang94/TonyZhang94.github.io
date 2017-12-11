#include "CActiveEdge.h"
#include <iostream>
using namespace std;

CActiveEdge::CActiveEdge() {
	actId = -1;
	polyId = -1;

	xl = 0.0;
	dxl = 0.0;
	dyl = 0.0;

	xr = 0.0;
	dxr = 0.0;
	dyr = 0.0;

	dl = 0.0;
	dzx = 0.0;
	dzy = 0.0;

	nextActEdge = NULL;

	cout << "不要使用默认参数初始化CActiveEdge" << endl;
}

CActiveEdge::CActiveEdge(int ppolyId, float pxl, float pdxl, float pdyl, float pxr, float pdxr, float pdyr, float pdl, float pdzx, float pdzy) {
	static int rank = 1;
	actId = rank;
	rank++;

	polyId = ppolyId;
	
	xl = pxl;
	dxl = pdxl;
	dyl = pdyl;

	xr = pxr;
	dxr = pdxr;
	dyr = pdyr;

	dl = pdl;
	dzx = pdzx;
	dzy = pdzy;

	nextActEdge = NULL;
}

void CActiveEdge::printActiveEdge() {
	cout << endl << "actId = " << actId << "; polyId = " << polyId << endl;
	cout << "xl=" << xl << "; dxl=" << dxl << "; dyl=" << dyl << endl;
	cout << "xr=" << xr << "; dxr=" << dxr << "; dyr=" << dyr << endl;
	cout << "dl=" << dl << "; dzx=" << dzx << "; dzy=" << dzy << endl;
}