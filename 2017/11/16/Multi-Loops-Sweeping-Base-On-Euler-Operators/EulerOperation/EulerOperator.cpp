#include "header.h"
#include "EulerOperator.h"

CHalfEdge* CEulerOperator::mev(CCoordinate *xyz, CCoordinate *newv, CLoop *loop) {
	CSolid *solid = loop->belongFace->belongSolid;
	CEdge *edge = new CEdge;
	CVertex *v2 = new CVertex;
	CHalfEdge *helfEdge1 = new CHalfEdge;
	CHalfEdge *helfEdge2 = new CHalfEdge;
	CVertex *v1 = solid->FindVertex(xyz);

	if (NULL == v1) {
		cout << "mev: 指定点v不存在" << endl;
		return NULL;
	}

	helfEdge1->v1 = v1;
	v2->xyz->CoordinateCopy(newv);
	helfEdge2->v1 = v2;

	helfEdge1->nextHalfEdge = helfEdge2;
	helfEdge1->brotherHalfEdge = helfEdge2;
	helfEdge2->prevHalfEdge = helfEdge1;
	helfEdge2->brotherHalfEdge = helfEdge1;

	CHalfEdge *windowHalfEdge = loop->firstHalfEdge;
	if (NULL == windowHalfEdge)
	{
		loop->firstHalfEdge = helfEdge1;
		helfEdge1->prevHalfEdge = helfEdge2;
		helfEdge2->nextHalfEdge = helfEdge1;
	}
	else
	{
		while (windowHalfEdge->nextHalfEdge->v1 != v1)
			windowHalfEdge = windowHalfEdge->nextHalfEdge;

		helfEdge2->nextHalfEdge = windowHalfEdge->nextHalfEdge;
		windowHalfEdge->nextHalfEdge->prevHalfEdge = helfEdge2;
		windowHalfEdge->nextHalfEdge = helfEdge1;
		helfEdge1->prevHalfEdge = windowHalfEdge;
	}

	helfEdge1->belongEdge = edge;
	helfEdge2->belongEdge = edge;
	edge->leftHalfEdge = helfEdge1;
	edge->rightHalfEdge = helfEdge2;
	edge->v1 = v1;
	edge->v2 = v2;
	edge->nextEdge = NULL;
	edge->prevEdge = NULL;

	helfEdge1->belongLoop = loop;
	helfEdge2->belongLoop = loop;

	solid->AddEdgeToSolid(edge);
	solid->AddVertexToSolid(v2);

	return helfEdge1;
}

CLoop* CEulerOperator::mef(CCoordinate *v1xyz, CCoordinate *v2xyz, CLoop *loop) {
	CSolid *solid = loop->belongFace->belongSolid;
	CVertex *v1 = solid->FindVertex(v1xyz);
	CVertex *v2 = solid->FindVertex(v2xyz);

	if (NULL == v1 || NULL == v2) {
		cout << "mef: v1或v2不存在" << endl;
		return NULL;
	}

	if (!(loop->IsVertexInLoop(v1) && loop->IsVertexInLoop(v2))) {
		cout << "mef: 指定面没有连接v1和v2的边" << endl;
		return NULL;
	}

	CFace *face = new CFace;
	CLoop *innerLoop = new CLoop;
	CEdge *edge = new CEdge;
	CHalfEdge *halfEdge1 = new CHalfEdge;
	CHalfEdge *halfEdge2 = new CHalfEdge;

	CHalfEdge *tempHalfEdge1 = loop->FindHalfEdge(v1);
	CHalfEdge *tempHalfEdge2 = loop->FindHalfEdge(v2);

	innerLoop->AddHalfEdgeToLoop(halfEdge2);
	CHalfEdge *windowHalfEdge = tempHalfEdge1;
	while (NULL != windowHalfEdge) {
		if (windowHalfEdge == tempHalfEdge2)
			break;
		windowHalfEdge->belongLoop = innerLoop;
		windowHalfEdge = windowHalfEdge->nextHalfEdge;
	}
	halfEdge2->nextHalfEdge = tempHalfEdge1;
	windowHalfEdge = tempHalfEdge1->prevHalfEdge;
	tempHalfEdge1->prevHalfEdge = halfEdge2;
	tempHalfEdge2->prevHalfEdge->nextHalfEdge = halfEdge2;
	halfEdge2->prevHalfEdge = tempHalfEdge2->prevHalfEdge;

	windowHalfEdge->nextHalfEdge = halfEdge1;
	halfEdge1->prevHalfEdge = windowHalfEdge;
	halfEdge1->nextHalfEdge = tempHalfEdge2;
	tempHalfEdge2->prevHalfEdge = halfEdge1;

	halfEdge1->belongLoop = loop;
	loop->firstHalfEdge = halfEdge1;

	halfEdge1->v1 = v1;
	halfEdge2->v1 = v2;

	halfEdge1->brotherHalfEdge = halfEdge2;
	halfEdge2->brotherHalfEdge = halfEdge1;

	halfEdge1->belongEdge = edge;
	halfEdge2->belongEdge = edge;
	edge->leftHalfEdge = halfEdge1;
	edge->rightHalfEdge = halfEdge2;
	edge->v1 = v1;
	edge->v2 = v2;
	edge->nextEdge = NULL;
	edge->prevEdge = NULL;

	solid->AddEdgeToSolid(edge);
	face->AddLoopToFace(innerLoop);
	solid->AddFaceToSolid(face);

	return innerLoop;
}

CSolid* CEulerOperator::mvfs(CCoordinate *xyz) {
	CSolid *solid;
	CLoop *loop;
	CFace *face;
	CVertex *vertex;
	solid = new CSolid;
	loop = new CLoop;
	face = new CFace;
	vertex = new CVertex;

	vertex->xyz->CoordinateCopy(xyz);
	face->AddLoopToFace(loop);
	solid->AddFaceToSolid(face);
	solid->AddVertexToSolid(vertex);

	return solid;
}

CLoop* CEulerOperator::kemr(CCoordinate *v1xyz, CCoordinate *v2xyz, CLoop *loop) {
	CSolid *solid = loop->belongFace->belongSolid;
	CVertex *v1 = solid->FindVertex(v1xyz);
	CVertex *v2 = solid->FindVertex(v2xyz);
	if (NULL == v1 || NULL == v2) {
		cout << "kemr: v1或v2不存在" << endl;
		return NULL;
	}

	if (!(loop->IsVertexInLoop(v1) && loop->IsVertexInLoop(v2))) {
		cout << "kemr: 指定面没有连接v1和v2的边" << endl;
		return NULL;
	}

	CHalfEdge *halfEdge1 = loop->firstHalfEdge;
	while (halfEdge1) {
		if (halfEdge1->v1 == v1 && halfEdge1->nextHalfEdge->v1 == v2)
			break;
		halfEdge1 = halfEdge1->nextHalfEdge;
	}

	CHalfEdge *halfEdge2 = halfEdge1->brotherHalfEdge;
	CLoop *newloop = new CLoop;
	if (halfEdge1->nextHalfEdge != halfEdge2) {
		newloop->AddHalfEdgeToLoop(halfEdge1->nextHalfEdge);
		CHalfEdge *windowHalfEdge = halfEdge1->nextHalfEdge->nextHalfEdge;
		while (windowHalfEdge) {
			if (windowHalfEdge == halfEdge2)
				break;
			windowHalfEdge->belongLoop = newloop;
			windowHalfEdge = windowHalfEdge->nextHalfEdge;
		}
		halfEdge1->nextHalfEdge->prevHalfEdge = halfEdge2->prevHalfEdge;
		halfEdge2->prevHalfEdge->nextHalfEdge = halfEdge1->nextHalfEdge;
	}

	loop->belongFace->AddLoopToFace(newloop);
	loop->firstHalfEdge = halfEdge1->prevHalfEdge;

	halfEdge1->prevHalfEdge->nextHalfEdge = halfEdge2->nextHalfEdge;
	halfEdge2->nextHalfEdge->prevHalfEdge = halfEdge1->prevHalfEdge;
	CEdge *windowEdge = solid->firstEdge;
	while (NULL != windowEdge) {
		if (windowEdge->leftHalfEdge == halfEdge1 || windowEdge->rightHalfEdge == halfEdge1)
			break;
		windowEdge = windowEdge->nextEdge;
	}
	if (NULL != windowEdge->nextEdge && NULL != windowEdge->prevEdge) {
		windowEdge->nextEdge->prevEdge = windowEdge->prevEdge;
		windowEdge->prevEdge->nextEdge = windowEdge->nextEdge;
	}
	else if (NULL == windowEdge->nextEdge && NULL != windowEdge->prevEdge) {
		windowEdge->prevEdge->nextEdge = NULL;
	}
	else if (NULL != windowEdge->nextEdge && NULL == windowEdge->prevEdge)
	{
		windowEdge->nextEdge->prevEdge = NULL;
		solid->firstEdge = windowEdge->nextEdge;
	}
	else {
		solid->firstEdge = NULL;
	}
	delete windowEdge;
	delete halfEdge1;
	delete halfEdge2;

	return newloop;
}

void CEulerOperator::kfmrh(CLoop *outerLoop, CLoop *innerLoop) {
	if (NULL == outerLoop || NULL == innerLoop) {
		cout << "kfmrh: 外环或内环不存在" << endl;
		return;
	}

	CFace *windowFace = innerLoop->belongFace;

	outerLoop->belongFace->AddLoopToFace(innerLoop);
	if (NULL == windowFace->nextFace && NULL == windowFace->prevFace) {
		windowFace->nextFace->prevFace = windowFace->prevFace;
		windowFace->prevFace->nextFace = windowFace->nextFace;
	}
	else if (NULL == windowFace->nextFace && NULL != windowFace->prevFace) {
		windowFace->prevFace->nextFace = NULL;
	}
	else if (NULL != windowFace->nextFace && NULL == windowFace->prevFace) {
		windowFace->nextFace->prevFace = NULL;
		outerLoop->belongFace->belongSolid->firstFace = windowFace->nextFace;
	}
	else {
		outerLoop->belongFace->belongSolid->firstFace = NULL;
	}
	delete windowFace;

	return;
}

void CEulerOperator::kev(CCoordinate *xyz1, CCoordinate *xyz2, CSolid *solid) {
	CVertex *v1 = solid->FindVertex(xyz1);
	CVertex *v2 = solid->FindVertex(xyz2);
	if (NULL == v1 || NULL == v2) {
		cout << "kev: v1或v2不存在" << endl;
		return;
	}

	CEdge *delEdge = solid->FindEdge(v1, v2);
	if (NULL == delEdge) {
		cout << "kev: 不存在连接v1或v2的边" << endl;
		return;
	}

	CHalfEdge *delHalfEdge1 = delEdge->leftHalfEdge, *delHalfEdge2 = delEdge->rightHalfEdge;
	CVertex *delv2 = v2;
	CFace *pface = solid->firstFace;
	while (pface) {
		CLoop *ploop = pface->firstLoop;
		while (ploop) {
			if(ploop->FindHalfEdge(delv2))
				ploop->FindHalfEdge(delv2)->v1 = v1;
			ploop = ploop->nextLoop;
		}
		pface = pface->nextFace;
	}
	delHalfEdge1->belongLoop->firstHalfEdge = delHalfEdge1->nextHalfEdge;
	delHalfEdge2->belongLoop->firstHalfEdge = delHalfEdge2->nextHalfEdge;
	delHalfEdge1->nextHalfEdge->prevHalfEdge = delHalfEdge1->prevHalfEdge;
	delHalfEdge1->prevHalfEdge->nextHalfEdge = delHalfEdge1->nextHalfEdge;
	delHalfEdge2->nextHalfEdge->prevHalfEdge = delHalfEdge2->prevHalfEdge;
	delHalfEdge2->prevHalfEdge->nextHalfEdge = delHalfEdge2->nextHalfEdge;
	delete delHalfEdge1;
	delete delHalfEdge2;

	if (NULL != delEdge->nextEdge && NULL != delEdge->prevEdge) {
		delEdge->nextEdge->prevEdge = delEdge->prevEdge;
		delEdge->prevEdge->nextEdge = delEdge->nextEdge;
	}
	else if (NULL == delEdge->nextEdge && NULL != delEdge->prevEdge) {
		delEdge->prevEdge->nextEdge = NULL;
	}
	else if (NULL != delEdge->nextEdge && NULL == delEdge->prevEdge) {
		delEdge->nextEdge->prevEdge = NULL;
		solid->firstEdge = delEdge->nextEdge;
	}
	else {
		solid->firstEdge = NULL;
	}
	delete delEdge;

	if (NULL != delv2->nextVertex && NULL != delv2->prevVertex) {
		delv2->nextVertex->prevVertex = delv2->prevVertex;
		delv2->prevVertex->nextVertex = delv2->nextVertex;
	}
	else if (NULL == delv2->nextVertex && NULL != delv2->prevVertex) {
		delv2->prevVertex->nextVertex = NULL;
	}
	else if (NULL != delv2->nextVertex && NULL == delv2->prevVertex) {
		delv2->nextVertex->prevVertex = NULL;
		solid->firstVertex = delv2->nextVertex;
	}
	else {
		solid->firstVertex = NULL;
	}
	delete delv2;

	return;
}

void CEulerOperator::kef(CCoordinate *xyz1, CCoordinate *xyz2, CLoop *loop) {
	CSolid *solid = loop->belongFace->belongSolid;
	CVertex *v1 = solid->FindVertex(xyz1);
	CVertex *v2 = solid->FindVertex(xyz2);
	if (NULL == v1 || NULL == v2) {
		cout << "kef: v1或v2不存在" << endl;
		return;
	}

	if (!(loop->IsVertexInLoop(v1) && loop->IsVertexInLoop(v2))) {
		cout << "kef: v1或v2不在指定环内" << endl;
		return;
	}

	CHalfEdge *delHalfEdge1 = loop->FindHalfEdge(v1);
	CHalfEdge *delHalfEdge2 = delHalfEdge1->brotherHalfEdge;
	CEdge *delEdge = delHalfEdge1->belongEdge;
	CLoop *delLoop = delHalfEdge2->belongLoop;
	CFace *delFace = delLoop->belongFace;
	CHalfEdge *windowHalfEdge = delHalfEdge2->nextHalfEdge;

	while (NULL != windowHalfEdge) {
		if (windowHalfEdge == delHalfEdge2)
			break;
		windowHalfEdge->belongLoop = loop;
		windowHalfEdge = windowHalfEdge->nextHalfEdge;
	}

	delHalfEdge1->nextHalfEdge->prevHalfEdge = delHalfEdge2->prevHalfEdge;
	delHalfEdge2->prevHalfEdge->nextHalfEdge = delHalfEdge1->nextHalfEdge;
	delHalfEdge1->prevHalfEdge->nextHalfEdge = delHalfEdge2->nextHalfEdge;
	delHalfEdge2->nextHalfEdge->prevHalfEdge = delHalfEdge1->prevHalfEdge;
	loop->firstHalfEdge = delHalfEdge1->nextHalfEdge;
	delete delHalfEdge1;
	delete delHalfEdge2;

	if (NULL != delEdge->nextEdge && NULL != delEdge->prevEdge) {
		delEdge->nextEdge->prevEdge = delEdge->prevEdge;
		delEdge->prevEdge->nextEdge = delEdge->nextEdge;
	}
	else if (NULL == delEdge->nextEdge && NULL != delEdge->prevEdge) {
		delEdge->prevEdge->nextEdge = NULL;
	}
	else if (NULL != delEdge->nextEdge && NULL == delEdge->prevEdge) {
		delEdge->nextEdge->prevEdge = NULL;
		solid->firstEdge = delEdge->nextEdge;
	}
	else {
		solid->firstEdge = NULL;
	}
	delete delEdge;

	if (NULL != delLoop->nextLoop && NULL != delLoop->prevLoop) {
		delLoop->nextLoop->prevLoop = delLoop->prevLoop;
		delLoop->prevLoop->nextLoop = delLoop->nextLoop;
	}
	else if (NULL == delLoop->nextLoop && NULL != delLoop->prevLoop) {
		delLoop->prevLoop->nextLoop = NULL;
	}
	else if (NULL != delLoop->nextLoop && NULL == delLoop->prevLoop) {
		delLoop->nextLoop->prevLoop = NULL;
		delLoop->belongFace->firstLoop = delLoop->nextLoop;
	}
	else {
		delLoop->belongFace->firstLoop = NULL;
	}
	delete delLoop;

	if (NULL != delFace->nextFace && NULL != delFace->prevFace) {
		delFace->nextFace->prevFace = delFace->prevFace;
		delFace->prevFace->nextFace = delFace->nextFace;
	}
	else if (NULL == delFace->nextFace && NULL != delFace->prevFace) {
		delFace->prevFace->nextFace = NULL;
	}
	else if (NULL != delFace->nextFace && NULL == delFace->prevFace) {
		delFace->nextFace->prevFace = NULL;
		solid->firstFace = delFace->nextFace;
	}
	else {
		solid->firstFace = NULL;
	}
	delete delFace;

	return;
}

bool CEulerOperator::kvfs(CCoordinate *xyz,CSolid *solid) {
	CVertex *vertex = solid->FindVertex(xyz);
	if (NULL == vertex) {
		cout << "kvfs: 点xyz不存在" << endl;
		return false;
	}
	CFace *face = solid->firstFace;
	CLoop *loop = face->firstLoop;
	delete vertex;
	delete loop;
	delete face;
	delete solid;
	return true;
}

CHalfEdge* CEulerOperator::mekr(CCoordinate *xyz1, CCoordinate *xyz2, CLoop *loop, CLoop *delLoop) {
	CSolid *solid = loop->belongFace->belongSolid;
	CVertex *v1 = solid->FindVertex(xyz1);
	CVertex *v2 = solid->FindVertex(xyz2);
	if (NULL == v1 || NULL == v2) {
		cout << "mekr: v1或v2不存在" << endl;
		return NULL;
	}

	if (!(loop->IsVertexInLoop(v1) && loop->IsVertexInLoop(v2))) {
		cout << "mekr: v1或v2不在指定环内" << endl;
		return NULL;
	}

	CHalfEdge *halfEdge1 = new CHalfEdge, *halfEdge2 = new CHalfEdge;
	CEdge *newEdge = new CEdge;
	halfEdge1->v1 = v1;
	halfEdge2->v1 = v2;
	halfEdge1->brotherHalfEdge = halfEdge2;
	halfEdge2->brotherHalfEdge = halfEdge1;
	halfEdge1->belongEdge = newEdge;
	halfEdge2->belongEdge = newEdge;
	newEdge->leftHalfEdge = halfEdge1;
	newEdge->rightHalfEdge = halfEdge2;
	halfEdge1->belongLoop = loop;
	halfEdge2->belongLoop = loop;

	CHalfEdge *v2HalfEdge = delLoop->FindHalfEdge(v2);
	CHalfEdge *windowHalfEdge = v2HalfEdge;
	while (NULL != windowHalfEdge) {
		windowHalfEdge->belongLoop = loop;
		windowHalfEdge = windowHalfEdge->nextHalfEdge;
		if (windowHalfEdge == v2HalfEdge)
			break;
	}

	CHalfEdge* v1HalfEdge = loop->FindHalfEdge(v1);
	v1HalfEdge->prevHalfEdge->nextHalfEdge = halfEdge1;
	halfEdge1->prevHalfEdge = v1HalfEdge->prevHalfEdge;
	halfEdge1->nextHalfEdge = v2HalfEdge;
	windowHalfEdge = v2HalfEdge->prevHalfEdge;
	v2HalfEdge->prevHalfEdge = halfEdge1;
	windowHalfEdge->nextHalfEdge = halfEdge2;
	halfEdge2->prevHalfEdge = windowHalfEdge;
	halfEdge2->nextHalfEdge = v1HalfEdge;
	v1HalfEdge->prevHalfEdge = halfEdge2;

	solid->AddEdgeToSolid(newEdge);

	if (NULL != delLoop->nextLoop && NULL != delLoop->prevLoop) {
		delLoop->nextLoop->prevLoop = delLoop->prevLoop;
		delLoop->prevLoop->nextLoop = delLoop->nextLoop;
	}
	else if (NULL == delLoop->nextLoop && NULL != delLoop->prevLoop) {
		delLoop->prevLoop->nextLoop = NULL;
	}
	else if (NULL != delLoop->nextLoop && NULL == delLoop->prevLoop) {
		delLoop->nextLoop->prevLoop = NULL;
		delLoop->belongFace->firstLoop = delLoop->nextLoop;
	}
	else {
		delLoop->belongFace->firstLoop = NULL;
	}
	delete delLoop;

	return halfEdge1;
}

CFace* CEulerOperator::mfkrh(CLoop *outerLoop, CLoop *innerLoop) {
	if (!outerLoop || !innerLoop) {
		cout << "mfkrh: 指定外环或者内环不存在" << endl;
		return NULL;
	}
	if (outerLoop->belongFace != innerLoop->belongFace) {
		cout << "mfkrh: 指定外环或者内环不在同一面上" << endl;
		return NULL;
	}

	if (NULL != innerLoop->nextLoop && NULL != innerLoop->prevLoop) {
		innerLoop->nextLoop->prevLoop = innerLoop->prevLoop;
		innerLoop->prevLoop->nextLoop = innerLoop->nextLoop;
	}
	else if (NULL == innerLoop->nextLoop && NULL != innerLoop->prevLoop)
	{
		innerLoop->prevLoop->nextLoop = NULL;
	}
	else if (NULL != innerLoop->nextLoop && NULL == innerLoop->prevLoop)
	{
		innerLoop->nextLoop->prevLoop = NULL;
		innerLoop->belongFace->belongSolid->firstFace->firstLoop = innerLoop->nextLoop;
	}
	else
	{
		innerLoop->belongFace->belongSolid->firstFace->firstLoop = NULL;
	}
	CFace *face = new CFace;
	outerLoop->belongFace->belongSolid->AddFaceToSolid(face);
	face->AddLoopToFace(innerLoop);

	return face;
}

void CEulerOperator::Sweep(CFace *face, CCoordinate *direct) {
	//cout << face->idFace << endl;
	CLoop *topFirstLoop = face->firstLoop;
	CLoop *bottomFirstLoop = NULL;
	CLoop *bottomLoop = NULL;
	CCoordinate *p1 = &CCoordinate(), *p2 = &CCoordinate(), *firstv, *lastv;
	for (CLoop *windowLoop = face->firstLoop;NULL != windowLoop;windowLoop = windowLoop->nextLoop) {
		CHalfEdge *windowEdge = windowLoop->firstHalfEdge;
		CHalfEdge *nextHalfEdge = windowEdge->nextHalfEdge;
		CHalfEdge *prevHalfEdge = windowEdge->prevHalfEdge;

		CCoordinate *xyz = windowEdge->v1->xyz;
		p1->CoordinateCopy(xyz);
		p2 = xyz->CCoordinateAdd(direct);
		firstv = xyz->CCoordinateAdd(direct);
		lastv = xyz->CCoordinateAdd(direct);
		
		this->mev(p1, p2, windowLoop);
		if (windowEdge == prevHalfEdge) {
			windowEdge = NULL;
		}
		else {
			windowEdge = nextHalfEdge;
			nextHalfEdge = windowEdge->nextHalfEdge;
		}

		while (windowEdge) {
			xyz = windowEdge->v1->xyz;
			p1->CoordinateCopy(xyz);
			p2 = xyz->CCoordinateAdd(direct);
			this->mev(p1, p2, windowLoop);
			bottomLoop = this->mef(lastv, p2, windowLoop);
			lastv = p2;
			if (windowEdge == prevHalfEdge) {
				this->mef(lastv, firstv, windowLoop);
				windowEdge = NULL;
			}
			else {
				windowEdge = nextHalfEdge;
				nextHalfEdge = windowEdge->nextHalfEdge;
			}
		}

		//if (windowLoop == topFirstLoop) {
		//	bottomFirstLoop = bottomLoop;
		//	cout << bottomFirstLoop->idLoop << endl;
		//}
		//if (windowLoop != topFirstLoop) {
		//	this->kfmrh(bottomFirstLoop, bottomLoop);
		//}
	}
}