#include "header.h"

CHalfEdge::CHalfEdge() {
	static int id = 0;
	idHalfEdge = id++;

	nextHalfEdge = NULL;
	prevHalfEdge = NULL;
	brotherHalfEdge = NULL;

	belongLoop = NULL;
	belongEdge = NULL;

	v1 = NULL;
}

CHalfEdge::~CHalfEdge() {

}