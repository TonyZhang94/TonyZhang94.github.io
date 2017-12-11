#ifndef __CPOLYGON
#define __CPOLYGON

class CPolygon {
public:
	int polyId; // �����id������������Ƭid��Ӧ

	// �����ϵ��
	float a;
	float b;
	float c;
	float d;

	// �������ɫ��Ϣ
	int R;
	int G;
	int B;

	float dzx; // ���ҵ���ȱ仯��
	float dzy; // ���µ���ȱ仯��

	bool inFlag; // �Ƿ������ǰɨ������

	CPolygon *nextPoly; // ����ṹ�����ں�vector���ʹ��
public:
	CPolygon();
	CPolygon(float a, float b, float c, float d, int R, int G, int B);

	void printPolygon();
};

#endif