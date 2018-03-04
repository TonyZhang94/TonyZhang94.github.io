#ifndef __RESULT__
#define __RESULT__

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

	// 设置头文件
	void
		set_BMPheader();

	// 设置场景
	void
		set_scene(char _scene);

	// 以运行时间命名
	void
		writeBMP(void);

	// 用户命名
	void
		writeBMP(char *fileName);

	// OpenGL显示
	void
		open_window(int argc, char *argv[]);

public:

	int size; // image边长
	int pSize; // image大小
	char scene; // 场景号
	char name[50]; // 以时间命名
	BITMAPFILEHEADER fileHeader; // BMP文件头
	BITMAPINFOHEADER infoHeader; // 信息概要

	unsigned char *image; // 点阵图
};

// 设置场景
inline void
	Result::set_scene(char _scene) {
		scene = _scene;
}

#endif