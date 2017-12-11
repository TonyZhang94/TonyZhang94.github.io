#include "CResult.h"
#include <time.h>

#define Pi 3.1415926

unsigned char *GLData;
int GLSize;
char *pathHead;
clock_t start;
clock_t endT;

CResult::CResult() {
	cout << "请不要使用默认参数初始化CResult!" << endl;
}

CResult::CResult(CZbuffer zbuffer, int psize) {
	size = psize;
	int width = size * 3;
	int height = size;

	picSize = width * height;
	pData = new unsigned char[picSize];

	// 设置背景色为白色
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

	// 用IPL行数作为最外层循环
	for (int y = 0;y < zbuffer.IPL.size();y++) {
		// 此行只有背景
		if (1 == zbuffer.IPL[y].size()) {
			continue;
		}

		// 扫描线存在奇异情况下
		if (0 != zbuffer.IPL[y][zbuffer.IPL[y].size()-1]) {
			//cout << "y=" << y << endl;
			//cout << "IPL size = " << zbuffer.IPL[y].size() << "; AET size = " << zbuffer.AET[y].size() << "; i=" << i << endl;
			for (int k = 0;k < width;k++) {
				*(pData+y*width+k) = *(pData+(y-1)*width+k);
			}
			continue;
		}

		// 遍历IPL具体一行
		for (int i = 0;i < zbuffer.IPL[y].size()-1;i++) {
			int cur = zbuffer.IPL[y][i+1] - 1;
			// 此区域没有面片覆盖，保持背景色
			if (cur < 0) {
				continue;
			}

			// 查询AET信息，将颜色信息写入结果矩阵
			for (int x = zbuffer.AET[y][i];x < zbuffer.AET[y][i+1];x++) {
				*(pData+y*width+x*3+0) = zbuffer.PolygonList[cur].R;
				*(pData+y*width+x*3+1) = zbuffer.PolygonList[cur].G;
				*(pData+y*width+x*3+2) = zbuffer.PolygonList[cur].B;
			}
		}
	}

	// 由于像素坐标为整数，浮点数坐标转化为整型所造成奇异性消除
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

// bmp文件信息
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

// 将当前显示写入文件保存，为了旋转流畅，代码调用这个方法的地方我注释了，这个方法是work的，需要的话注释取消就可以了
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
	cout << "结果已输出到" << path << endl;
}

void myDisplay(void) {
	glDrawPixels(GLSize, GLSize, GL_BGR_EXT, GL_UNSIGNED_BYTE, GLData);
	glutSwapBuffers();
}

int oldx;
int oldy;
CFile *pObj;

// 生成旋转结果的文件名 name_rotate_XX.bmp
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

// 鼠标移动事件
void Mouse(int button, int state, int x, int y) {
	// 点击事件记录坐标
	if(GLUT_DOWN == state) {
		oldx = x;
		oldy = y;
	}
	else { // 鼠标松开后计算坐标差
		int dx = x - oldx;
		int dy = y - oldy;
		char path[50] = "";
		makeFilename(path);

		// 计算旋转角度
		float thetax = dy * Pi / 400;
		float thetay = dx * Pi / 400;

		start = clock();
		pObj->rotate(thetax, thetay); // 旋转变换

		CZbuffer zbuffer = CZbuffer(pObj); // 初始化zbuffer的一些变量
		zbuffer.makeEdgeList(); // 建立边表ET
		zbuffer.makePolygonList(); // 建立多边形表PT

		zbuffer.scan(); // 扫描，扫描线有选择的和多边形的各边求交点，建立AET和IPL
		CResult result = CResult(zbuffer, GLSize); // 按照用户指定大小利用AET和IPL构造结果矩阵
		
		endT = clock();
		cout << "zBuffer数据结构生成用时：" << (double)(endT-start)/CLOCKS_PER_SEC << endl;

		/**
			func：将显示结果写入bmp文件
			由于写入文件需要耗时，影响鼠标拖拽旋转物体的观察效果的连续性
			所以我这里注释了，如果需要保存物体当前状态的二维图片可以放开
		*/
		// result.WriteFile(path);

		// 新的结果矩阵
		GLData = result.pData;

		cout << "正在渲染" << endl;
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
//	//if(h>1.0f) h=1.0f; //视点y坐标作一些限制，不会使视点太奇怪
//	//else if(h<-1.0f) h=-1.0f;
//	//oldmx=x,oldmy=y; //把此时的鼠标坐标作为旧值，为下一次计算增量做准备
//
//	glutPostRedisplay();
//}

void CResult::Rendering(int argc, char *argv[], CFile obj, char *path) {
	cout << "正在渲染" << endl;
	GLData = pData;
	GLSize = size;
	pObj = &obj;
	pathHead = path;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(GLSize, GLSize);
	glutCreateWindow("ZBuffer Call偶围城 XXXXXXXX");
	glutDisplayFunc(&myDisplay);
	glutMouseFunc(Mouse);
	//glutMotionFunc(onMouseMove);
	glutMainLoop();

	cout << "end" << endl;
}