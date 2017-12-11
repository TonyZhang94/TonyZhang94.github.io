#include "CZbuffer.h"
#include <algorithm>

CZbuffer::CZbuffer() {
	objFile = NULL;
	
	maxx = 0;
	minx = 0;
	maxy = 0;
	miny = 0;

	sizex = 0;
	sizey = 0;

	cout << "不要使用默认参数初始化CZbuffer" << endl;
}

CZbuffer::CZbuffer(CFile *pfile) {
	objFile = pfile;

	maxx = pfile->maxx;
	minx = pfile->minx;
	maxy = pfile->maxy;
	miny = pfile->miny;

	sizex = pfile->maxx + 10;
	sizey = pfile->maxy + 10;
}

// 建立ET
void CZbuffer::makeEdgeList() {
	int cur;
	CEdge obj = CEdge();
	for (vector<CFace>::iterator it = objFile->FaceList.begin();it != objFile->FaceList.end();it++) {
		CVertex vertex1 = objFile->VertexList[it->v1Id-1];
		CVertex vertex2 = objFile->VertexList[it->v2Id-1];
		CVertex vertex3 = objFile->VertexList[it->v3Id-1];
		
		// 两两之间构造边
		//if (vertex1.y != vertex2.y) {
			CEdge edge1 = obj.makeEdge(vertex1, vertex2, it->fId);
			cur = edge1.maxy;
			EdgeList[cur].push_back(edge1);
			//edge1.printEdge();
		//}

		//if (vertex2.y != vertex3.y) {
			CEdge edge2 = obj.makeEdge(vertex2, vertex3, it->fId);
			cur = edge2.maxy;
			EdgeList[cur].push_back(edge2);
			//edge2.printEdge();
		//}

		//if (vertex3.y != vertex1.y) {
			CEdge edge3 = obj.makeEdge(vertex3, vertex1, it->fId);
			cur = edge3.maxy;
			EdgeList[cur].push_back(edge3);
			//edge3.printEdge();
		//}
	}
}

// 建立PT
void CZbuffer::makePolygonList() {
	for (vector<CFace>::iterator it = objFile->FaceList.begin();it != objFile->FaceList.end();it++) {
		CVertex vertex1 = objFile->VertexList[it->v1Id-1];
		CVertex vertex2 = objFile->VertexList[it->v2Id-1];
		CVertex vertex3 = objFile->VertexList[it->v3Id-1];

		//int cur = vertex1.y;

		//if (cur < vertex2.y) cur = vertex2.y;
		//if (cur < vertex3.y) cur = vertex3.y;

		// 计算a, b, c, d
		float a, b, c, d;
		a = (vertex2.y - vertex1.y) * (vertex3.z - vertex1.z) - (vertex3.y - vertex1.y) * (vertex2.z - vertex1.z);
		b = (vertex2.z - vertex1.z) * (vertex3.x - vertex1.x) - (vertex3.z - vertex1.z) * (vertex2.x - vertex1.x);
		c = (vertex2.x - vertex1.x) * (vertex3.y - vertex1.y) - (vertex3.x - vertex1.x) * (vertex2.y - vertex1.y);
		d = - a * vertex1.x - b * vertex1.y - c * vertex1.z;

		CPolygon poly = CPolygon(a, b, c, d, it->r, it->g, it->b);
		PolygonList.push_back(poly);
		//poly.printPolygon();
	}
}

// 交点x坐标比较函数
bool cmp(intersection a, intersection b) {
	return a.x < b.x;
}

// 扫描线与边求交点
vector<intersection> FindIntersection(CEdgeTable activeEdgeTable) {
	vector<intersection> points;
	//activeEdgeTable.printCEdgeTable();

	CEdge *window = activeEdgeTable.head->nextEdge;
	intersection tmp;
	// 遍历活化边表
	while (NULL != window) {
		tmp.x = window->x;
		tmp.polyId = window->polyId;
		// 加入交点
		points.push_back(tmp);
		// dx修正下一个交点的x坐标
		window->x += window->dx;
		window = window->nextEdge;
	}

	// 将所有交点按照x坐标由小到大排序
	sort(points.begin(), points.end(), cmp);

	//cout << endl << "after sort" << endl;
	//for (int i = 0;i < points.size();i++) {
	//	cout << points[i].x << " " << points[i].polyId << "===";
	//}

	return points;
}

// 根据一条扫描线的交点生成AET中的一行数据
vector<float> makeAET(vector<intersection> points) {
	vector<float> aet;

	for (int i = 0;i < points.size();i++) {
		aet.push_back(points[i].x);
	}

	return aet;
}

// 根据扫描线位置y和x坐标，计算z值
float calZ(CPolygon poly, float x, int y) {
	if (0 != poly.c) {
		return - (poly.a * x + poly.b * y + poly.d) / poly.c;
	}
	else {
		return 0.0;//c为0时z如何计算？
	}
}

// 根据一条扫描线的交点生成IPL中的一行数据
vector<int> makeIPL(vector<intersection> points, vector<CPolygon> PolygonList, float y) {
	vector<int> ipl;
	vector<int> polys;

	// 找到所有活化多边形
	for (int i = 0;i < points.size();i++) {
		polys.push_back(points[i].polyId);
	}
	// 活化多边形排序后去重，减少计算量
	sort(polys.begin(), polys.end());
	polys.erase(unique(polys.begin(), polys.end()), polys.end());

	int maxId;
	float maxZ, tmpZ;
	ipl.push_back(0); // 最前面的设置为背景
	for (int i = 0;i < points.size();i++) {
		// 该交点所属多边形包含区域状态取反(奇数交点进去，偶数交点离开原则)
		PolygonList[points[i].polyId-1].inFlag = !PolygonList[points[i].polyId-1].inFlag;
		maxId = 0; //背景
		maxZ = -999;
		// 遍历活化多边形找到z值最大的作为该区域的显示面片
		for (int j = 0;j < polys.size();j++) {
			// 判断该活化多边形是否覆盖该区域
			if (true == PolygonList[polys[j]-1].inFlag) {
				// 计算z值
				tmpZ = calZ(PolygonList[polys[j]-1], points[i].x , y);
			}
			else {
				continue;
			}

			// 比较z值
			if (maxZ < tmpZ) {
				maxZ = tmpZ;
				maxId = polys[j];
			}
		}

		ipl.push_back(maxId);
		//cout << "maxId=" << maxId << "; maxZ=" << maxZ << endl;
	}

	return ipl;
}

void CZbuffer::scan() {
	// 活化边表
	CEdgeTable activeEdgeTable = CEdgeTable();
	for (int y = sizey; y >= 0;y--) { // 在多边形区域内扫面，减少计算量
		// 将该扫描线y值为起点的边加入到活化边表里
		for (int i = 0;i < EdgeList[y].size();i++) {
			if (EdgeList[y][i].dy > 0) {
				activeEdgeTable.insertEdge(&EdgeList[y][i]);
			}
		}

		//activeEdgeTable.printCEdgeTable();

		// 求交点
		vector<intersection> points = FindIntersection(activeEdgeTable);
		//求交AET
		AET[y] = makeAET(points);
		//求IPL
		IPL[y] = makeIPL(points, PolygonList, y);

		if (AET[y].size() - IPL[y].size() == 0) {
			cout << "y=" << y << endl;
		}

		// 将扫描完的边从活化边表中删除（dy <= 0）
		activeEdgeTable.removeCompletedEdge();
		//cout << "==========================" << endl;
		//activeEdgeTable.printCEdgeTable();
	}
}