#ifndef CLASSSOLID
#define CLASSSOLID

#include "Coordinate.h"
//class CSolid;
class CFace;
class CLoop;
class CEdge;
class CHalfEdge;
class CVertex;

class CSolid {
public:
	int idSolid;
	
	CSolid *prevSolid;
	CSolid *nextSolid;

	CFace *firstFace;
	CLoop *firstLoop;
	CEdge *firstEdge;
	CVertex *firstVertex;

	//static int numSolid;
	int numFace;
	int numLoop;
	int numEdge;
	int numVertex;
public:
	CSolid();
	virtual ~CSolid();

	bool AddFaceToSolid(CFace *newFace);
	bool AddLoopToSolid(CLoop *newLoop);
	bool AddEdgeToSolid(CEdge *newEdge);
	bool AddVertexToSolid(CVertex *newVertex);

	//CFace* GetFace();
	//CEdge* GetEdge();
	//CVertex* GetVertex();

	CVertex* FindVertex(CCoordinate *xyz);
	//CFace* GetFaceEnd();
	CEdge* FindEdge(CVertex *v1, CVertex *v2);
};

#endif