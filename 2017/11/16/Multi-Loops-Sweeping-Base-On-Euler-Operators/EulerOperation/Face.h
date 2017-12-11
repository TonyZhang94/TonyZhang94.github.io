#ifndef CLASSFACE
#define CLASSFACE

#include "Coordinate.h"
class CSolid;
//class CFace;
class CLoop;
class CEdge;
class CHalfEdge;
class CVertex;

class CFace {
public:
	int idFace;

	CFace *prevFace;
	CFace *nextFace;

	CSolid *belongSolid;

	//CLoop *outerLoop;
	//CLoop *firstInnerLoop;
	CLoop *firstLoop;

	int numInnerLoop;
	int numEdge;
	int numVertex;
public:
	CFace();
	~CFace();
	bool AddLoopToFace(CLoop *newLoop);
};

#endif