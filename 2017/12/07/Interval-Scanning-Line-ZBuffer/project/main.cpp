#include "CFile.h"
#include "CZbuffer.h"
#include "CResult.h"
#include <string>
#include<iostream>
#include <algorithm>
#include <time.h>
using namespace std;

void Instruction(char *path, int *size) {
	cout << "��������Ҫ�����obj�ļ�����e.g.teapot����" << endl;
	scanf("%s", path);
	getchar();

	cout << "����������ʾ���ڵĴ�С���Ƽ�400-1000����" << endl;
	scanf("%d", size);

	cout << endl;
	cout << "�����obj�ļ�Ϊ��" << path << ".obj" << endl;
	cout << "�����bmp�ļ�Ϊ��" << path << ".bmp" << endl;
	cout << "�������Ĵ��ڴ�СΪ��" << *size << endl;

	cout << endl;
}

int main(int argc, char *argv[]) {
	CFile obj = CFile();
	char path[50];
	char pathcopy[50];
	char pathcopy1[50];
	int size;

	// ��ȡ�ļ����ͽ�����ڴ�С���ļ����౸�ݼ���
	Instruction(path, &size);
	strcpy(pathcopy, path);
	strcpy(pathcopy1, path);

	clock_t start, end;
	start = clock();
	obj.ReadObj(strcat(path, ".obj"), size); // ��ȡobj�ļ������������ݽṹ����Ƭ���Ĺ�ϵ��������ɱ����ķŴ���С���û�ָ���Ĵ�С

	CZbuffer zbuffer = CZbuffer(&obj); // ��ʼ��zbuffer��һЩ����
	zbuffer.makeEdgeList(); // �����߱�ET
	zbuffer.makePolygonList(); // ��������α�PT

	zbuffer.scan(); // ɨ�裬ɨ������ѡ��ĺͶ���εĸ����󽻵㣬����AET��IPL
	CResult result = CResult(zbuffer, size); // �����û�ָ����С����AET��IPL����������
	
	/**
		func������ʾ���д��bmp�ļ�
		����д���ļ���Ҫ��ʱ��Ӱ�������ק��ת����Ĺ۲�Ч����������
		����������ע���ˣ������Ҫ�������嵱ǰ״̬�Ķ�άͼƬ���Էſ�
	*/
	// result.WriteFile(strcat(pathcopy, ".bmp"));

	end = clock();
	cout << "zBuffer���ݽṹ������ʱ��" << (double)(end-start)/CLOCKS_PER_SEC << endl;

	// OpenGL��Ⱦ
	result.Rendering(argc, argv, obj, pathcopy1);

	return 0;
}