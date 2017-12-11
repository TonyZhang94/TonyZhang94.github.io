#ifndef CLASSVERTEX
#define CLASSVERTEX

#include "Coordinate.h"
class CSolid;
class CFace;
class CLoop;
class CEdge;
class CHalfEdge;
//class CVertex;

class CVertex {
public:
	int idVertex;

	CVertex *prevVertex;
	CVertex *nextVertex;

	CCoordinate *xyz;
public:
	CVertex();
	~CVertex();
};

#endif