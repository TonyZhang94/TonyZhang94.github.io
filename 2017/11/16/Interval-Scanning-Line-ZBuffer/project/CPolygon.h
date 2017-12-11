#ifndef __CPOLYGON
#define __CPOLYGON

class CPolygon {
public:
	int polyId; // 多边形id，与三角形面片id对应

	// 多边形系数
	float a;
	float b;
	float c;
	float d;

	// 多边形颜色信息
	int R;
	int G;
	int B;

	float dzx; // 向右的深度变化量
	float dzy; // 向下的深度变化量

	bool inFlag; // 是否包含当前扫描区域

	CPolygon *nextPoly; // 链表结构，后期和vector配合使用
public:
	CPolygon();
	CPolygon(float a, float b, float c, float d, int R, int G, int B);

	void printPolygon();
};

#endif