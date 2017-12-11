#include "header.h"

CEdge::CEdge() {
	static int id = 0;
	idEdge = id++;

	nextEdge = NULL;
	prevEdge = NULL;

	v1 = NULL;
	v2 = NULL;

	leftHalfEdge = NULL;
	rightHalfEdge = NULL;
}

CEdge::~CEdge() {

}