#include "CFile.h"
#include "CZbuffer.h"
#include "CResult.h"
#include <string>
#include<iostream>
#include <algorithm>
#include <time.h>
using namespace std;

void Instruction(char *path, int *size) {
	cout << "请输入需要导入的obj文件名（e.g.teapot）：" << endl;
	scanf("%s", path);
	getchar();

	cout << "请输入结果显示窗口的大小（推荐400-1000）：" << endl;
	scanf("%d", size);

	cout << endl;
	cout << "输入的obj文件为：" << path << ".obj" << endl;
	cout << "输出的bmp文件为：" << path << ".bmp" << endl;
	cout << "结果输出的窗口大小为：" << *size << endl;

	cout << endl;
}

int main(int argc, char *argv[]) {
	CFile obj = CFile();
	char path[50];
	char pathcopy[50];
	char pathcopy1[50];
	int size;

	// 获取文件名和结果窗口大小，文件名多备份几份
	Instruction(path, &size);
	strcpy(pathcopy, path);
	strcpy(pathcopy1, path);

	clock_t start, end;
	start = clock();
	obj.ReadObj(strcat(path, ".obj"), size); // 读取obj文件，构造点的数据结构和面片与点的关系，并将点成比例的放大缩小至用户指定的大小

	CZbuffer zbuffer = CZbuffer(&obj); // 初始化zbuffer的一些变量
	zbuffer.makeEdgeList(); // 建立边表ET
	zbuffer.makePolygonList(); // 建立多边形表PT

	zbuffer.scan(); // 扫描，扫描线有选择的和多边形的各边求交点，建立AET和IPL
	CResult result = CResult(zbuffer, size); // 按照用户指定大小利用AET和IPL构造结果矩阵
	
	/**
		func：将显示结果写入bmp文件
		由于写入文件需要耗时，影响鼠标拖拽旋转物体的观察效果的连续性
		所以我这里注释了，如果需要保存物体当前状态的二维图片可以放开
	*/
	// result.WriteFile(strcat(pathcopy, ".bmp"));

	end = clock();
	cout << "zBuffer数据结构生成用时：" << (double)(end-start)/CLOCKS_PER_SEC << endl;

	// OpenGL渲染
	result.Rendering(argc, argv, obj, pathcopy1);

	return 0;
}