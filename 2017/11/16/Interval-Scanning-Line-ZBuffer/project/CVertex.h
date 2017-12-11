#ifndef __CVERTEX
#define __CVERTEX

class CVertex {
public:
	int vId; // µãid
	// µã×ø±ê
	float x;
	float y;
	float z;

public:
	CVertex();
	CVertex(float X, float Y, float Z);
	void printVertex();
};

#endif