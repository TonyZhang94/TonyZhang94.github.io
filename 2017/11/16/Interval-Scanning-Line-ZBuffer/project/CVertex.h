#ifndef __CVERTEX
#define __CVERTEX

class CVertex {
public:
	int vId; // ��id
	// ������
	float x;
	float y;
	float z;

public:
	CVertex();
	CVertex(float X, float Y, float Z);
	void printVertex();
};

#endif