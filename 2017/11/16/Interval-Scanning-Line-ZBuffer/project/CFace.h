#ifndef __CFACE
#define __CFACE

class CFace {
public:
	int fId; // ��Ƭid

	// �����ĵ�id
	int v1Id;
	int v2Id;
	int v3Id;

	// ��Ƭ��ɫ
	int r;
	int g;
	int b;
public:
	CFace();
	CFace(int id1, int id2, int id3);
	void printFace();
};

#endif