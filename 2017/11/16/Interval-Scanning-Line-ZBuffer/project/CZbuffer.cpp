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

	cout << "��Ҫʹ��Ĭ�ϲ�����ʼ��CZbuffer" << endl;
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

// ����ET
void CZbuffer::makeEdgeList() {
	int cur;
	CEdge obj = CEdge();
	for (vector<CFace>::iterator it = objFile->FaceList.begin();it != objFile->FaceList.end();it++) {
		CVertex vertex1 = objFile->VertexList[it->v1Id-1];
		CVertex vertex2 = objFile->VertexList[it->v2Id-1];
		CVertex vertex3 = objFile->VertexList[it->v3Id-1];
		
		// ����֮�乹���
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

// ����PT
void CZbuffer::makePolygonList() {
	for (vector<CFace>::iterator it = objFile->FaceList.begin();it != objFile->FaceList.end();it++) {
		CVertex vertex1 = objFile->VertexList[it->v1Id-1];
		CVertex vertex2 = objFile->VertexList[it->v2Id-1];
		CVertex vertex3 = objFile->VertexList[it->v3Id-1];

		//int cur = vertex1.y;

		//if (cur < vertex2.y) cur = vertex2.y;
		//if (cur < vertex3.y) cur = vertex3.y;

		// ����a, b, c, d
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

// ����x����ȽϺ���
bool cmp(intersection a, intersection b) {
	return a.x < b.x;
}

// ɨ��������󽻵�
vector<intersection> FindIntersection(CEdgeTable activeEdgeTable) {
	vector<intersection> points;
	//activeEdgeTable.printCEdgeTable();

	CEdge *window = activeEdgeTable.head->nextEdge;
	intersection tmp;
	// ������߱�
	while (NULL != window) {
		tmp.x = window->x;
		tmp.polyId = window->polyId;
		// ���뽻��
		points.push_back(tmp);
		// dx������һ�������x����
		window->x += window->dx;
		window = window->nextEdge;
	}

	// �����н��㰴��x������С��������
	sort(points.begin(), points.end(), cmp);

	//cout << endl << "after sort" << endl;
	//for (int i = 0;i < points.size();i++) {
	//	cout << points[i].x << " " << points[i].polyId << "===";
	//}

	return points;
}

// ����һ��ɨ���ߵĽ�������AET�е�һ������
vector<float> makeAET(vector<intersection> points) {
	vector<float> aet;

	for (int i = 0;i < points.size();i++) {
		aet.push_back(points[i].x);
	}

	return aet;
}

// ����ɨ����λ��y��x���꣬����zֵ
float calZ(CPolygon poly, float x, int y) {
	if (0 != poly.c) {
		return - (poly.a * x + poly.b * y + poly.d) / poly.c;
	}
	else {
		return 0.0;//cΪ0ʱz��μ��㣿
	}
}

// ����һ��ɨ���ߵĽ�������IPL�е�һ������
vector<int> makeIPL(vector<intersection> points, vector<CPolygon> PolygonList, float y) {
	vector<int> ipl;
	vector<int> polys;

	// �ҵ����л�����
	for (int i = 0;i < points.size();i++) {
		polys.push_back(points[i].polyId);
	}
	// �����������ȥ�أ����ټ�����
	sort(polys.begin(), polys.end());
	polys.erase(unique(polys.begin(), polys.end()), polys.end());

	int maxId;
	float maxZ, tmpZ;
	ipl.push_back(0); // ��ǰ�������Ϊ����
	for (int i = 0;i < points.size();i++) {
		// �ý�����������ΰ�������״̬ȡ��(���������ȥ��ż�������뿪ԭ��)
		PolygonList[points[i].polyId-1].inFlag = !PolygonList[points[i].polyId-1].inFlag;
		maxId = 0; //����
		maxZ = -999;
		// �����������ҵ�zֵ������Ϊ���������ʾ��Ƭ
		for (int j = 0;j < polys.size();j++) {
			// �жϸû������Ƿ񸲸Ǹ�����
			if (true == PolygonList[polys[j]-1].inFlag) {
				// ����zֵ
				tmpZ = calZ(PolygonList[polys[j]-1], points[i].x , y);
			}
			else {
				continue;
			}

			// �Ƚ�zֵ
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
	// ��߱�
	CEdgeTable activeEdgeTable = CEdgeTable();
	for (int y = sizey; y >= 0;y--) { // �ڶ����������ɨ�棬���ټ�����
		// ����ɨ����yֵΪ���ı߼��뵽��߱���
		for (int i = 0;i < EdgeList[y].size();i++) {
			if (EdgeList[y][i].dy > 0) {
				activeEdgeTable.insertEdge(&EdgeList[y][i]);
			}
		}

		//activeEdgeTable.printCEdgeTable();

		// �󽻵�
		vector<intersection> points = FindIntersection(activeEdgeTable);
		//��AET
		AET[y] = makeAET(points);
		//��IPL
		IPL[y] = makeIPL(points, PolygonList, y);

		if (AET[y].size() - IPL[y].size() == 0) {
			cout << "y=" << y << endl;
		}

		// ��ɨ����ıߴӻ�߱���ɾ����dy <= 0��
		activeEdgeTable.removeCompletedEdge();
		//cout << "==========================" << endl;
		//activeEdgeTable.printCEdgeTable();
	}
}