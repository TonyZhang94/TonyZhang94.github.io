#include "Result.h"

#include <GL/glut.h>

Result::Result(void)
	: size(0), pSize(0), image(NULL) {
		set_BMPheader();
}

Result::Result(int _sence, int _size)
	: scene(_sence), size(_size) {
		pSize = size * size * 3;
		set_BMPheader();

		image = (unsigned char *)malloc(sizeof(unsigned char)*pSize);
		for (int i = 0;i < size;i++) {
			for (int j = 0;j < size;j++) {
				*(image + (i * 3 * size + j * 3)) = 254;
				*(image + (i * 3 * size + j * 3 + 1)) = 254;
				*(image + (i * 3 * size + j * 3 + 2)) = 254;
			}
		}

		time_t tt = time(NULL);
		tm* t= localtime(&tt);

		sprintf(name, "scene0%d %d-%d-%d %d-%d-%d.bmp", scene, t->tm_year+1900,  t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec); 
}

Result::~Result(void) {
	if (NULL != image) {
		delete image;
		image = NULL;
	}
}

// 设置头文件
void
	Result::set_BMPheader() {
		fileHeader.bfType = 19778;
		fileHeader.bfSize = size*size;
		fileHeader.bfReserved1 = 0;
		fileHeader.bfReserved2 = 0;
		fileHeader.bfOffBits = 54;

		infoHeader.biSize = 40;
		infoHeader.biWidth = size;
		infoHeader.biHeight = size;
		infoHeader.biPlanes = 1;
		infoHeader.biBitCount = 24;
		infoHeader.biCompression = 0;
		infoHeader.biSizeImage = size*size;
		infoHeader.biXPelsPerMeter = 3779;
		infoHeader.biYPelsPerMeter = 3779;
		infoHeader.biClrUsed = 0;
		infoHeader.biClrImportant = 0;
}

// 以运行时间命名
void
	Result::writeBMP(void) {
		cout << "结果文件为：" << name << endl;

		FILE *fw;
		fw = fopen(name, "wb");

		fwrite(&fileHeader.bfType, sizeof(WORD), 1, fw);
		fwrite(&fileHeader.bfSize, sizeof(DWORD), 1, fw);
		fwrite(&fileHeader.bfReserved1, sizeof(WORD), 1, fw);
		fwrite(&fileHeader.bfReserved2, sizeof(WORD), 1, fw);
		fwrite(&fileHeader.bfOffBits, sizeof(DWORD), 1, fw);
		fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fw);

		fwrite(image, pSize, 1, fw);
		fclose(fw);
}

// 用户命名
void
	Result::writeBMP(char *fileName) {
		cout << "结果文件为：" << fileName << endl;

		FILE *fw;
		fw = fopen(fileName, "wb");

		fwrite(&fileHeader.bfType, sizeof(WORD), 1, fw);
		fwrite(&fileHeader.bfSize, sizeof(DWORD), 1, fw);
		fwrite(&fileHeader.bfReserved1, sizeof(WORD), 1, fw);
		fwrite(&fileHeader.bfReserved2, sizeof(WORD), 1, fw);
		fwrite(&fileHeader.bfOffBits, sizeof(DWORD), 1, fw);
		fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fw);

		fwrite(image, pSize, 1, fw);
		fclose(fw);
}

unsigned char *GLData;
int GLSize;

void myDisplay(void) {
	glDrawPixels(GLSize, GLSize, GL_BGR_EXT, GL_UNSIGNED_BYTE, GLData);
	glutSwapBuffers();
}

// OpenGL显示
void
	Result::open_window(int argc, char *argv[]) {
		GLData = image;
		GLSize = size;

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(GLSize, GLSize);
		glutCreateWindow("MonteCarlo Call偶围城 XXXXXXXX");
		glutDisplayFunc(&myDisplay);
		glutMainLoop();
}