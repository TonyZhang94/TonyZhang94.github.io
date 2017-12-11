#ifndef EULEROPERATOR
#define EULEROPERATOR

#include "header.h"

class CEulerOperator {
public:
	CHalfEdge* mev(CCoordinate *xyz, CCoordinate *newv, CLoop *loop);
	CLoop* mef(CCoordinate *v1xyz, CCoordinate *v2xyz, CLoop *loop);
	CSolid* mvfs(CCoordinate *xyz);
	CLoop* kemr(CCoordinate *v1xyz, CCoordinate *v2xyz, CLoop *loop);
	void kfmrh(CLoop *outerLoop, CLoop *innerLoop);

	void kev(CCoordinate *xyz1, CCoordinate *xyz2, CSolid *solid);
	void kef(CCoordinate *xyz1, CCoordinate *xyz2, CLoop *loop);
	bool kvfs(CCoordinate *xyz,CSolid *solid);
	CHalfEdge* mekr(CCoordinate *xyz1, CCoordinate *xyz2, CLoop *loop, CLoop *delLoop);
	CFace* mfkrh(CLoop *outerLoop, CLoop *innerLoop);

	//void semv(CCoordinate xyz1, CCoordinate xyz2, CCoordinate xyz3, CSolid *solid);
	//void kekv();

	void Sweep(CFace *face, CCoordinate *direct);
};

#endif