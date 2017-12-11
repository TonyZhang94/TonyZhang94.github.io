#ifndef __CFACE
#define __CFACE

class CFace {
public:
	int fId; // 面片id

	// 包含的点id
	int v1Id;
	int v2Id;
	int v3Id;

	// 面片颜色
	int r;
	int g;
	int b;
public:
	CFace();
	CFace(int id1, int id2, int id3);
	void printFace();
};

#endif