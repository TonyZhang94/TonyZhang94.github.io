#ifndef __RESULT__
#define __RESULT__

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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Result {
public:

	Result(void);
	Result(int _scene, int _size);

	~Result();

	// ����ͷ�ļ�
	void
		set_BMPheader();

	// ���ó���
	void
		set_scene(char _scene);

	// ������ʱ������
	void
		writeBMP(void);

	// �û�����
	void
		writeBMP(char *fileName);

	// OpenGL��ʾ
	void
		open_window(int argc, char *argv[]);

public:

	int size; // image�߳�
	int pSize; // image��С
	char scene; // ������
	char name[50]; // ��ʱ������
	BITMAPFILEHEADER fileHeader; // BMP�ļ�ͷ
	BITMAPINFOHEADER infoHeader; // ��Ϣ��Ҫ

	unsigned char *image; // ����ͼ
};

// ���ó���
inline void
	Result::set_scene(char _scene) {
		scene = _scene;
}

#endif