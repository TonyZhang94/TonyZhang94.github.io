#ifndef __CRESULT
#define __CRESULT

#include "CZbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
//#include <GLFW/glfw3.h>

typedef unsigned int Int;
typedef unsigned short WORD;
typedef unsigned long DWORD;

// 写bmp文件需要的信息数据结构
typedef struct tagBITMAPFILEHEADER
{
	WORD  bfType;  
	DWORD bfSize; 
	WORD  bfReserved1; 
	WORD  bfReserved2; 
	DWORD bfOffBits;
} BITMAPFILEHEADER;

// 写bmp文件需要的信息数据结构
typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize; 
	Int  biWidth; 
	Int  biHeight; 
	WORD  biPlanes; 
	WORD  biBitCount; 
	DWORD biCompression; 
	DWORD biSizeImage; 
	Int  biXPelsPerMeter; 
	Int  biYPelsPerMeter; 
	DWORD biClrUsed; 
	DWORD biClrImportant;
} BITMAPINFOHEADER;

class CResult {
public:
	int size; // 用户指定的结果窗口大小
	DWORD picSize; // 结果矩阵大小(size*size*3)
	unsigned char *pData; // 结果矩阵
public:
	CResult();
	// 构造结果矩阵
	CResult(CZbuffer zbuffer, int size);

	// 将当前显示写入文件保存，为了旋转流畅，代码调用这个方法的地方我注释了，这个方法是work的，需要的话注释取消就可以了
	void WriteFile(char *path);
	// 设置bmp文件头
	void setHeaderInfo (BITMAPFILEHEADER &fileHeader, BITMAPINFOHEADER &infoHeader, int size);

	// OpenGL渲染
	void Rendering(int argc, char *argv[], CFile obj, char *path);
};

#endif