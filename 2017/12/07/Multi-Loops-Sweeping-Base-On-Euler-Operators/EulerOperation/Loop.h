#ifndef CLASSLOOP
#define CLASSLOOP

#include "Coordinate.h"
class CSolid;
class CFace;
//class CLoop;
class CEdge;
class CHalfEdge;
class CVertex;

class CLoop {
public:
	int idLoop;

	CLoop *prevLoop;
	CLoop *nextLoop;

	CFace *belongFace;

	CHalfEdge *firstHalfEdge;
public:
	CLoop();
	~CLoop();
	bool AddHalfEdgeToLoop(CHalfEdge *newHalfEdge);
	bool IsVertexInLoop(CVertex *v1);
	CHalfEdge *FindHalfEdge(CVertex *v1);
};

#endif