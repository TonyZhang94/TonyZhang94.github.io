#ifndef CLASSEDGE
#define CLASSEDGE

#include "Coordinate.h"
class CSolid;
class CFace;
class CLoop;
//class CEdge;
class CHalfEdge;
class CVertex;

class CEdge {
public:
	int idEdge;

	CEdge *prevEdge;
	CEdge *nextEdge;

	CVertex *v1;
	CVertex *v2;

	CHalfEdge *leftHalfEdge;
	CHalfEdge *rightHalfEdge;
public:
	CEdge();
	~CEdge();
};

#endif