#include "header.h"

CVertex::CVertex() {
	static int id = 0;
	idVertex = id++;

	nextVertex = NULL;
	prevVertex = NULL;

	xyz = new CCoordinate();
}

CVertex::~CVertex() {

}