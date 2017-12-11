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

// дbmp�ļ���Ҫ����Ϣ���ݽṹ
typedef struct tagBITMAPFILEHEADER
{
	WORD  bfType;  
	DWORD bfSize; 
	WORD  bfReserved1; 
	WORD  bfReserved2; 
	DWORD bfOffBits;
} BITMAPFILEHEADER;

// дbmp�ļ���Ҫ����Ϣ���ݽṹ
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
	int size; // �û�ָ���Ľ�����ڴ�С
	DWORD picSize; // ��������С(size*size*3)
	unsigned char *pData; // �������
public:
	CResult();
	// ����������
	CResult(CZbuffer zbuffer, int size);

	// ����ǰ��ʾд���ļ����棬Ϊ����ת���������������������ĵط���ע���ˣ����������work�ģ���Ҫ�Ļ�ע��ȡ���Ϳ�����
	void WriteFile(char *path);
	// ����bmp�ļ�ͷ
	void setHeaderInfo (BITMAPFILEHEADER &fileHeader, BITMAPINFOHEADER &infoHeader, int size);

	// OpenGL��Ⱦ
	void Rendering(int argc, char *argv[], CFile obj, char *path);
};

#endif