#ifndef CLASSHALFEDGE
#define CLASSHALFEDGE

#include "Coordinate.h"
class CSolid;
class CFace;
class CLoop;
class CEdge;
//class CHalfEdge;
class CVertex;

class CHalfEdge {
public:
	int idHalfEdge;

	CHalfEdge *prevHalfEdge;
	CHalfEdge *nextHalfEdge;
	CHalfEdge *brotherHalfEdge;

	CLoop *belongLoop;
	CEdge *belongEdge;

	CVertex *v1;
public:
	CHalfEdge();
	~CHalfEdge();
};

#endif