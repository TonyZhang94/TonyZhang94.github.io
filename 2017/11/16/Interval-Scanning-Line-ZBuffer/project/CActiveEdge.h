#ifndef __ACTIVEEDGE
#define __ACTIVEEDGE

class CActiveEdge {
public:
	int actId; // 活化边id
	int polyId; // 属于面片id

	float xl; // 初始为上端的左x坐标，在扫描过程中不断变化
	float dxl; // 两条扫面线之间左x坐标的变化量
	float dyl; // 左边剩扫描线数量

	float xr; // 初始为上端的右x坐标，在扫描过程中不断变化
	float dxr;// 两条扫面线之间右x坐标的变化量
	float dyr; // 右边剩扫描线数量

	float dl; // 左交点处多边形所在平面的深度值
	float dzx; // 扫描线向右一个像素，深度变化量
	float dzy; // 扫描线向下一个像素，深度变化量

	CActiveEdge *nextActEdge; // 链表
public:
	CActiveEdge();
	CActiveEdge(int polyId, float xl, float dxl, float dyl, float xr, float dxr, float dyr, float dl, float dzx, float dzy);

	void printActiveEdge();
};

#endif