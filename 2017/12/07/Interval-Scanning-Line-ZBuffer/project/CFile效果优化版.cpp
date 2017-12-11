#include "CFile.h"

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
using namespace std;

#define MAX 999
#define MIN -999
#define TIME 800
#define OFFSET 100

// 读取obj文件构造FaceList和VertexList
void CFile::ReadObj(string path, int psize) {
	maxy = MIN;
	maxx = MIN;
	maxz = MIN;
	minx = MAX;
	miny = MAX;
	minz = MAX;

	size = psize;

	ifstream fp(path);
	if (NULL == fp) {
		cout << "OBJ文件打开失败，请重新确认文件！" << endl;
		exit(0);
	}

	string s;
	stringstream ss;
	float x, y, z;
	int id1, id2, id3;
	while (getline(fp,s)) {
		if (s.length() < 2) {
			continue;
		}

		if ('v' == s[0] && ' ' == s[1]) { // 点
			s = s.substr(2);
			ss << s;
			ss >> x >> y >> z;
			
			// 寻找坐标最值
			if (x > maxx) {
				maxx = x;
			}
			else if (x < minx) {
				minx = x;
			}

			if (y > maxy) {
				maxy = y;
			}
			else if (y < miny) {
				miny = y;
			}

			if (z > maxz) {
				maxz = z;
			}
			else if (z < minz) {
				minz = z;
			}

			CVertex tmp = CVertex(x, y, z);
			VertexList.push_back(tmp);
			ss.clear();
		}
		else if ('f' == s[0] && ' ' == s[1]) { // 三角形面片
			s = s.substr(2);
			sscanf_s(s.c_str(),"%d//%*d %d//%*d %d//%*d",&id1,&id2,&id3);
			CFace tmp = CFace(id1, id2, id3);
			FaceList.push_back(tmp);
		}
	}

	fp.close();
	Move();
}

// 按用户指定结果窗口大小缩放和平移物体各点
void CFile::Move() {
	int time = size * 0.8;

	float diffx = maxx - minx;
	float diffy = maxy - miny;
	float diffz = maxz - minz;

	float diff = diffx;
	if (diffy > diff) diff = diffy;
	if (diffz > diff) diff = diffz;

	int offsetx = diff / diffx * size * 0.1;
	int offsety = diff / diffy * size * 0.12;
	int offsetz = diff / diffz * size * 0.1;

	for (int i = 0;i < VertexList.size();i++) {
		VertexList[i].x = (VertexList[i].x - minx) * time / diff + offsetx;
		//cout << VertexList[i].x << endl;
		VertexList[i].y = (VertexList[i].y - miny) * time / diff + offsety;
		//cout << VertexList[i].y << endl;
		VertexList[i].z = (VertexList[i].z - minz) * time / diff + offsetz;
		//cout << VertexList[i].z << endl << endl;
	}

	minx = offsetx;
	maxx = diffx * time / diff + offsetx;
	miny = offsety;
	maxy = diffy * time / diff + offsety;
	minz = offsetz;
	maxz = diffz * time / diff + offsetz;
}

// 旋转物体
void CFile::rotate(float thetax, float thetay) {
	float cx = cos(thetax);
	float sx = sin(thetax);
	float cy = cos(thetay);
	float sy = sin(thetay);

	// 找到物体的中心坐标，旋转围绕物体中心进行
	int centerx = (maxx + minx) / 2;
	int centery = (maxy + miny) / 2;
	int centerz = (maxz + minz) / 2;

	int tx, ty, tz;
	maxy = MIN;
	maxx = MIN;
	maxz = MIN;
	minx = MAX;
	miny = MAX;
	minz = MAX;
	for (int i = 0;i < VertexList.size();i++) {
		tx = (VertexList[i].x - centerx);
		ty = (VertexList[i].y - centery);
		tz = (VertexList[i].z - centerz);

		// 旋转变换
		VertexList[i].x = tx * cy + tz * sy + centerx;
		//if (VertexList[i].x < 0) cout << "i=" << i << "; x" << endl;
		VertexList[i].y = ty * cx - sx * (-tx * sy + tz * cy) + centery;
		//if (VertexList[i].y < 0) cout << "i=" << i << "; y" << endl;
		VertexList[i].z = ty * sx + cx * (-tx * sy + tz * cy) + centerz;
		//if (VertexList[i].z < 0) cout << "i=" << i << "; z" << endl;

		// 重新获取物体坐标的最值
		if (VertexList[i].x > maxx) {
			maxx = VertexList[i].x;
		}
		else if (VertexList[i].x < minx) {
			minx = VertexList[i].x;
		}

		if (VertexList[i].y > maxy) {
			maxy = VertexList[i].y;
		}
		else if (VertexList[i].y < miny) {
			miny = VertexList[i].y;
		}

		if (VertexList[i].z > maxz) {
			maxz = VertexList[i].z;
		}
		else if (VertexList[i].z < minz) {
			minz = VertexList[i].z;
		}
	}

	//cout << "maxx=" << maxx << "; minx=" << minx << endl;
	//cout << "maxy=" << maxy << "; miny=" << miny << endl;
	//cout << "maxz=" << maxz << "; minz=" << minz << endl;

	cx = cos(0.0);
	sx = sin(0.0);
	cy = cos(0.0);
	sy = sin(0.0);

	// 找到物体的中心坐标，旋转围绕物体中心进行
	centerx = (maxx + minx) / 2;
	centery = (maxy + miny) / 2;
	centerz = (maxz + minz) / 2;

	maxy = MIN;
	maxx = MIN;
	maxz = MIN;
	minx = MAX;
	miny = MAX;
	minz = MAX;
	for (int i = 0;i < VertexList.size();i++) {
		tx = (VertexList[i].x - centerx);
		ty = (VertexList[i].y - centery);
		tz = (VertexList[i].z - centerz);

		// 旋转变换
		VertexList[i].x = tx * cy + tz * sy + centerx;
		//if (VertexList[i].x < 0) cout << "i=" << i << "; x" << endl;
		VertexList[i].y = ty * cx - sx * (-tx * sy + tz * cy) + centery;
		//if (VertexList[i].y < 0) cout << "i=" << i << "; y" << endl;
		VertexList[i].z = ty * sx + cx * (-tx * sy + tz * cy) + centerz;
		//if (VertexList[i].z < 0) cout << "i=" << i << "; z" << endl;

		// 重新获取物体坐标的最值
		if (VertexList[i].x > maxx) {
			maxx = VertexList[i].x;
		}
		else if (VertexList[i].x < minx) {
			minx = VertexList[i].x;
		}

		if (VertexList[i].y > maxy) {
			maxy = VertexList[i].y;
		}
		else if (VertexList[i].y < miny) {
			miny = VertexList[i].y;
		}

		if (VertexList[i].z > maxz) {
			maxz = VertexList[i].z;
		}
		else if (VertexList[i].z < minz) {
			minz = VertexList[i].z;
		}
	}
}