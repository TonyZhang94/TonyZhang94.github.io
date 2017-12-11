#ifndef __ACTIVEEDGE
#define __ACTIVEEDGE

class CActiveEdge {
public:
	int actId; // ���id
	int polyId; // ������Ƭid

	float xl; // ��ʼΪ�϶˵���x���꣬��ɨ������в��ϱ仯
	float dxl; // ����ɨ����֮����x����ı仯��
	float dyl; // ���ʣɨ��������

	float xr; // ��ʼΪ�϶˵���x���꣬��ɨ������в��ϱ仯
	float dxr;// ����ɨ����֮����x����ı仯��
	float dyr; // �ұ�ʣɨ��������

	float dl; // �󽻵㴦���������ƽ������ֵ
	float dzx; // ɨ��������һ�����أ���ȱ仯��
	float dzy; // ɨ��������һ�����أ���ȱ仯��

	CActiveEdge *nextActEdge; // ����
public:
	CActiveEdge();
	CActiveEdge(int polyId, float xl, float dxl, float dyl, float xr, float dxr, float dyr, float dl, float dzx, float dzy);

	void printActiveEdge();
};

#endif