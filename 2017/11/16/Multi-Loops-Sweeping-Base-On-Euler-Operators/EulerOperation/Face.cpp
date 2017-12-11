#include "header.h"

CFace::CFace() {
	static int id = 0;
	idFace = id++;

	nextFace = NULL;
	prevFace = NULL;

	belongSolid = NULL;

	//outerLoop = NULL;
	//firstInnerLoop = NULL;
	firstLoop = NULL;

	numInnerLoop = 0;
	numEdge = 0;
	numVertex = 0;
}

CFace::~CFace() {

}

bool CFace::AddLoopToFace(CLoop *newLoop) {
	if (NULL == newLoop) return false;

	CLoop *windowLoop = firstLoop;
	if (NULL == windowLoop) firstLoop = newLoop;
	else {
		while (NULL != windowLoop->nextLoop)
			windowLoop = windowLoop->nextLoop;
		windowLoop->nextLoop = newLoop;
		newLoop->prevLoop = windowLoop;
	}
	newLoop->belongFace = this;
	numInnerLoop++;
	//this->belongSolid->numLoop++;
	return true;
}