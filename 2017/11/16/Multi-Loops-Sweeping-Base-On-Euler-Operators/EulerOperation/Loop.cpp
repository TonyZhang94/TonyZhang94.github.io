#include "header.h"

CLoop::CLoop() {
	static int id = 0;
	idLoop = id++;

	nextLoop = NULL;
	prevLoop = NULL;

	belongFace = NULL;

	firstHalfEdge = NULL;
}

CLoop::~CLoop() {

}

bool CLoop::AddHalfEdgeToLoop(CHalfEdge *newHalfEdge) {
	if (NULL == newHalfEdge) return false;
	CHalfEdge *windowHalfEdge = firstHalfEdge;
	if (NULL == windowHalfEdge) firstHalfEdge = newHalfEdge;
	else {
		while (NULL != windowHalfEdge->nextHalfEdge)
			windowHalfEdge = windowHalfEdge->nextHalfEdge;
		windowHalfEdge->nextHalfEdge = newHalfEdge;
		newHalfEdge->prevHalfEdge = windowHalfEdge;
	}
	newHalfEdge->belongLoop = this;
	return true;
}

bool CLoop::IsVertexInLoop(CVertex *v1) {
	if (NULL == v1) return false;

	CHalfEdge *windowHalfEdge = firstHalfEdge;
	while (NULL != windowHalfEdge) {
		if (windowHalfEdge->v1 == v1) return true;
		windowHalfEdge = windowHalfEdge->nextHalfEdge;
		if (windowHalfEdge == firstHalfEdge)
			return false;
	}
	return false;
}

CHalfEdge *CLoop::FindHalfEdge(CVertex *v1) {
	if (NULL == v1) return NULL;
	CHalfEdge *windowHalfEdge = firstHalfEdge;
	while (NULL != windowHalfEdge) {
		if (windowHalfEdge->v1 == v1)
			return windowHalfEdge;
		windowHalfEdge = windowHalfEdge->nextHalfEdge;
		if (windowHalfEdge == firstHalfEdge)
			return NULL;
	}
	return NULL;
}