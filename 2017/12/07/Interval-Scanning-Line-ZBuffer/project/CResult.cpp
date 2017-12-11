#include "CResult.h"
#include <time.h>

#define Pi 3.1415926

unsigned char *GLData;
int GLSize;
char *pathHead;
clock_t start;
clock_t endT;

CResult::CResult() {
	cout << "�벻Ҫʹ��Ĭ�ϲ�����ʼ��CResult!" << endl;
}

CResult::CResult(CZbuffer zbuffer, int psize) {
	size = psize;
	int width = size * 3;
	int height = size;

	picSize = width * height;
	pData = new unsigned char[picSize];

	// ���ñ���ɫΪ��ɫ
	int reverseHeight;
	for (int row = 0;row < height;row++) {
		for (int column = 0;column < width;column+=3) {
			reverseHeight = height - row - 1;
			*(pData+row*width+column+0) = 255;
			*(pData+row*width+column+1) = 255;
			*(pData+row*width+column+2) = 255;
		}
	}
	//memset(pData, 255, sizeof(pData));

	// ��IPL������Ϊ�����ѭ��
	for (int y = 0;y < zbuffer.IPL.size();y++) {
		// ����ֻ�б���
		if (1 == zbuffer.IPL[y].size()) {
			continue;
		}

		// ɨ���ߴ������������
		if (0 != zbuffer.IPL[y][zbuffer.IPL[y].size()-1]) {
			//cout << "y=" << y << endl;
			//cout << "IPL size = " << zbuffer.IPL[y].size() << "; AET size = " << zbuffer.AET[y].size() << "; i=" << i << endl;
			for (int k = 0;k < width;k++) {
				*(pData+y*width+k) = *(pData+(y-1)*width+k);
			}
			continue;
		}

		// ����IPL����һ��
		for (int i = 0;i < zbuffer.IPL[y].size()-1;i++) {
			int cur = zbuffer.IPL[y][i+1] - 1;
			// ������û����Ƭ���ǣ����ֱ���ɫ
			if (cur < 0) {
				continue;
			}

			// ��ѯAET��Ϣ������ɫ��Ϣд��������
			for (int x = zbuffer.AET[y][i];x < zbuffer.AET[y][i+1];x++) {
				*(pData+y*width+x*3+0) = zbuffer.PolygonList[cur].R;
				*(pData+y*width+x*3+1) = zbuffer.PolygonList[cur].G;
				*(pData+y*width+x*3+2) = zbuffer.PolygonList[cur].B;
			}
		}
	}

	// ������������Ϊ����������������ת��Ϊ�������������������
	for (int row = 1;row < zbuffer.maxy-1;row++) {
		for (int column = zbuffer.minx;column < zbuffer.maxx*3;column++) {
			if (255 == *(pData+row*width+column)) {
				if (255 != *(pData+(row-1)*width+column)
				 && 255 != *(pData+(row+1)*width+column)) {
					*(pData+row*width+column) = *(pData+(row-1)*width+column);
				}
			}
		}
	}
}

// bmp�ļ���Ϣ
void CResult::setHeaderInfo (BITMAPFILEHEADER &fileHeader, BITMAPINFOHEADER &infoHeader, int size) {
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

// ����ǰ��ʾд���ļ����棬Ϊ����ת���������������������ĵط���ע���ˣ����������work�ģ���Ҫ�Ļ�ע��ȡ���Ϳ�����
void CResult::WriteFile(char *path) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	setHeaderInfo(fileHeader, infoHeader, size);

	FILE *fw;
	fw = fopen(path, "wb");

	fwrite(&fileHeader.bfType, sizeof(WORD), 1, fw);
	fwrite(&fileHeader.bfSize, sizeof(DWORD), 1, fw);
	fwrite(&fileHeader.bfReserved1, sizeof(WORD), 1, fw);
	fwrite(&fileHeader.bfReserved2, sizeof(WORD), 1, fw);
	fwrite(&fileHeader.bfOffBits, sizeof(DWORD), 1, fw);
	fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fw);

	fwrite(pData, picSize, 1, fw);
	fclose(fw);
	cout << "����������" << path << endl;
}

void myDisplay(void) {
	glDrawPixels(GLSize, GLSize, GL_BGR_EXT, GL_UNSIGNED_BYTE, GLData);
	glutSwapBuffers();
}

int oldx;
int oldy;
CFile *pObj;

// ������ת������ļ��� name_rotate_XX.bmp
void makeFilename(char *path) {
	static int rank = 1;

	strcat(path, pathHead);
	strcat(path, "_rotate_");
	int tmp = rank++;
	int cur = 0;
	char seq[5];
	while (0 != tmp) {
		seq[cur++] = '0' + tmp % 10;
		tmp /= 10;
	}
	char c;
	for (int i = 0;i < cur / 2;i++) {
		c = seq[i];
		seq[i] = seq[cur-1-i];
		seq[cur-1-i] = c;
	}
	seq[cur] = '\0';
	strcat(path, seq);
	strcat(path, ".bmp");
}

// ����ƶ��¼�
void Mouse(int button, int state, int x, int y) {
	// ����¼���¼����
	if(GLUT_DOWN == state) {
		oldx = x;
		oldy = y;
	}
	else { // ����ɿ�����������
		int dx = x - oldx;
		int dy = y - oldy;
		char path[50] = "";
		makeFilename(path);

		// ������ת�Ƕ�
		float thetax = dy * Pi / 400;
		float thetay = dx * Pi / 400;

		start = clock();
		pObj->rotate(thetax, thetay); // ��ת�任

		CZbuffer zbuffer = CZbuffer(pObj); // ��ʼ��zbuffer��һЩ����
		zbuffer.makeEdgeList(); // �����߱�ET
		zbuffer.makePolygonList(); // ��������α�PT

		zbuffer.scan(); // ɨ�裬ɨ������ѡ��ĺͶ���εĸ����󽻵㣬����AET��IPL
		CResult result = CResult(zbuffer, GLSize); // �����û�ָ����С����AET��IPL����������
		
		endT = clock();
		cout << "zBuffer���ݽṹ������ʱ��" << (double)(endT-start)/CLOCKS_PER_SEC << endl;

		/**
			func������ʾ���д��bmp�ļ�
			����д���ļ���Ҫ��ʱ��Ӱ�������ק��ת����Ĺ۲�Ч����������
			����������ע���ˣ������Ҫ�������嵱ǰ״̬�Ķ�άͼƬ���Էſ�
		*/
		// result.WriteFile(path);

		// �µĽ������
		GLData = result.pData;

		cout << "������Ⱦ" << endl;
		glDrawPixels(GLSize, GLSize, GL_BGR_EXT, GL_UNSIGNED_BYTE, GLData);
		glutSwapBuffers();
		glFlush();
	}
}

//void onMouseMove(int x, int y) {
//	//cout << "mx=" << x << "; my=" << y << endl;
//	dx = x - oldx;
//	dy = y - oldy;
//
//	cout << "dx=" << dx << "; dy=" << dy << endl;
//	//if(h>1.0f) h=1.0f; //�ӵ�y������һЩ���ƣ�����ʹ�ӵ�̫���
//	//else if(h<-1.0f) h=-1.0f;
//	//oldmx=x,oldmy=y; //�Ѵ�ʱ�����������Ϊ��ֵ��Ϊ��һ�μ���������׼��
//
//	glutPostRedisplay();
//}

void CResult::Rendering(int argc, char *argv[], CFile obj, char *path) {
	cout << "������Ⱦ" << endl;
	GLData = pData;
	GLSize = size;
	pObj = &obj;
	pathHead = path;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(GLSize, GLSize);
	glutCreateWindow("ZBuffer CallżΧ�� XXXXXXXX");
	glutDisplayFunc(&myDisplay);
	glutMouseFunc(Mouse);
	//glutMotionFunc(onMouseMove);
	glutMainLoop();

	cout << "end" << endl;
}