#include "header.h"

CSolid::CSolid()
{
	static int id = 0;
	idSolid = id++;

	prevSolid = NULL;
	nextSolid = NULL;

	firstFace = NULL;
	firstEdge = NULL;
	firstVertex = NULL;
	
	//numSolid++;
	numFace = 0;
	numLoop = 0;
	numEdge = 0;
	numVertex = 0;
}

CSolid::~CSolid() {
	//numSolid--;
}

bool CSolid::AddFaceToSolid(CFace *newFace) {
	if (NULL == newFace) return false;

	CFace *windowFace = firstFace;
	if (NULL == windowFace) firstFace = newFace;
	else {
		while (NULL != windowFace->nextFace)
			windowFace = windowFace->nextFace;
		windowFace->nextFace = newFace;
		newFace->prevFace = windowFace;
	}
	newFace->belongSolid = this;
	numFace++;
	return true;
}

bool CSolid::AddLoopToSolid(CLoop *newLoop) {
	if (NULL == newLoop) return false;

	CLoop *windowLoop = firstLoop;
	if (NULL == firstLoop) firstLoop = newLoop;
	else {
		while (NULL != windowLoop->nextLoop)
			windowLoop = windowLoop->nextLoop;
		windowLoop->nextLoop = newLoop;
		newLoop->prevLoop = windowLoop;
	}
	//newLoop->belongSolid = this;
	numLoop++;
	return true;
}

bool CSolid::AddEdgeToSolid(CEdge *newEdge) {
	if (NULL == newEdge) return false;

	CEdge *windowEdge = firstEdge;
	if (NULL == windowEdge) firstEdge = newEdge;
	else {
		while (NULL != windowEdge->nextEdge)
			windowEdge = windowEdge->nextEdge;
		windowEdge->nextEdge = newEdge;
		newEdge->prevEdge = windowEdge;
	}
	numEdge++;
	return true;
}

bool CSolid::AddVertexToSolid(CVertex *newVertex)
{
	if (NULL == newVertex) return false;

	CVertex *windowVertex = firstVertex;
	if (NULL == windowVertex) firstVertex = newVertex;
	else {
		while (NULL != windowVertex->nextVertex)
			windowVertex = windowVertex->nextVertex;
		windowVertex->nextVertex = newVertex;
		newVertex->prevVertex = windowVertex;
	}
	numVertex++;
	return true;
}

//CFace* CSolid::GetFace() {
//	return firstFace;
//}

//CEdge* CSolid::GetEdge() {
//	return firstEdge;
//}

//CVertex* CSolid::GetVertex() {
//	return firstVertex;
//}

CVertex* CSolid::FindVertex(CCoordinate *xyz) {
	CVertex *windowVertex = firstVertex;
	while (windowVertex != NULL && !windowVertex->xyz->CoordinateEqual(xyz))
		windowVertex = windowVertex->nextVertex;
	if (NULL == windowVertex) return NULL;
	else return windowVertex;
}

//CFace * CSolid::GetFaceEnd() {
//	CFace *windowFace = firstFace;
//	while (NULL != windowFace->nextFace)
//		windowFace = windowFace->nextFace;
//	return windowFace;
//}

CEdge* CSolid::FindEdge(CVertex *v1,CVertex *v2) {
	CEdge *windowEdge = firstEdge;
	while (NULL != windowEdge) {
		if ((windowEdge->leftHalfEdge->v1 == v1 && windowEdge->rightHalfEdge->v1 == v2) 
			|| (windowEdge->leftHalfEdge->v1 == v2 && windowEdge->rightHalfEdge->v1 == v1))
			return windowEdge;
		windowEdge = windowEdge->nextEdge;
	}
	return NULL;
}