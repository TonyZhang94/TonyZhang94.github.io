#include "FileStream.h"
#include <fstream>
using namespace std;

CFileStream::CFileStream() {
	strcpy(outerLoopPointsFileName, "OuterLoopPoints.txt");
	strcpy(innerLoopsPointsFileName, "InnerLoopsPoints.txt");
	strcpy(directFileName, "Direct.txt");
}

CCoordinate* CFileStream::ReadOuterLoopPoints(int *numOuterLoopPoints) {
	FILE *fp = fopen(outerLoopPointsFileName, "r");
	double x, y, z;
	CCoordinate outerLoopPoints[1000];
	while (!feof(fp)) {
		fscanf(fp, "%lf%lf%lf", &x, &y, &z);
		CCoordinate temp = CCoordinate(x, y, z);
		outerLoopPoints[(*numOuterLoopPoints)++] = temp;
	}
	return outerLoopPoints;
}

void CFileStream::ReadInnerLoopsPoints(CCoordinate innerLoops_points[][20], int *numLoop, int *numInnerLoopsPoints) {
	FILE *fp = fopen(innerLoopsPointsFileName, "r");
	double x, y, z, flag;
	while (!feof(fp)) {
		fscanf(fp, "%lf", &flag);
		if (-999.00 == flag) {
			numInnerLoopsPoints[*numLoop] = 0;
			(*numLoop)++;
		}
		else {
			if (0 == (*numLoop)) return;
			x = flag;
			fscanf(fp, "%lf%lf", &y, &z);
			CCoordinate temp = CCoordinate(x, y, z);
			
			innerLoops_points[(*numLoop)-1][numInnerLoopsPoints[(*numLoop)-1]] = temp;
			numInnerLoopsPoints[(*numLoop)-1]++;
		}
	}

	return;
}

CCoordinate CFileStream::ReadDirect() {
	FILE *fp = fopen(directFileName, "r");
	double x, y, z;
	fscanf(fp, "%lf%lf%lf", &x, &y, &z);
	CCoordinate direct = CCoordinate(x, y, z);
	return direct;
}

void CFileStream::GenerateDataStructure(CSolid *solid) {
	ofstream outfile;
	outfile.open("structure.txt", ios::out);
	outfile << "Solid: " << solid->idSolid << endl;

	CFace *face = solid->firstFace;
	while (NULL != face) {
		outfile << "\n\nFace: " << face->idFace << endl;
		CLoop *loop = face->firstLoop;
		while (NULL != loop) {
			outfile << "\nLoop: " << loop->idLoop << "  " << endl;
			CHalfEdge *halfEdge = loop->firstHalfEdge;
			while (NULL != halfEdge) {
				outfile << halfEdge->v1->idVertex << " ";
				halfEdge = halfEdge->nextHalfEdge;
				if (halfEdge == loop->firstHalfEdge)
					break;
			}
			loop = loop->nextLoop;
		}
		face = face->nextFace;
	}
	outfile.close();
}

void sortLoop(CLoop **loops, int num) {
	CLoop *tmp;
	int index;
	for (int i = 0;i < num;i++) {
		index = i;
		for (int j = i + 1;j < num;j++) {
			if (loops[index]->idLoop > loops[j]->idLoop)
				index = j;
		}
		if (i != index) {
			tmp = loops[i];
			loops[i] = loops[index];
			loops[index] = tmp;
		}
	}
}

void CFileStream::MakeBRP(CSolid *solid) {
	ofstream outfile;
	outfile.open("XXXXXXXXCall偶围城.brp", ios::out);

	CFace *face = solid->firstFace;
	CLoop *loops[1000];
	CVertex *v1 = solid->firstVertex;	

	int numFace = 0;
	int numLoop = 0;
	int numVertex = solid->numVertex;

	while (NULL != face) {
		numFace++;
		CLoop *loop = face->firstLoop;
		while (NULL != loop) {
			loops[numLoop++] = loop;
			loop = loop->nextLoop;
		}
		face = face->nextFace;
	}

	sortLoop(loops, numLoop);

	outfile << "BRP" << endl;
	outfile << numVertex << " " << numLoop << " " << numFace << " " << 1 << endl;

	v1 = solid->firstVertex;
	while (NULL != v1) {
		double *point = v1->xyz->PointToDouble();
		outfile << point[0] << " " <<  point[1] << " " << point[2] << endl;
		v1 = v1->nextVertex;
	}
	outfile << endl;

	for (int i = 0; i < numLoop; i++) {
		CLoop *loop = loops[i];
		CHalfEdge *halfEdge = loop->firstHalfEdge;
		int time = 0;
		while (NULL != halfEdge) {
			time++;
			halfEdge = halfEdge->nextHalfEdge;
			if (halfEdge == loop->firstHalfEdge) break;
		}
		outfile << time << " ";
		while (NULL != halfEdge) {
			CVertex *v1 = halfEdge->v1;
			outfile << v1->idVertex << " ";
			halfEdge = halfEdge->nextHalfEdge;
			if (halfEdge == loop->firstHalfEdge)
				break;
		}
		outfile << endl;
	}

	face = solid->firstFace;
	outfile << endl;

	while (NULL != face) {
		CLoop *loop = face->firstLoop;
		int time = 0;
		outfile << face->firstLoop->idLoop << " ";
		while (NULL != loop) {
			time++;
			loops[numLoop++] = loop;
			loop = loop->nextLoop;
		}
		if (1 == time) {
			outfile << 0 << " ";
		}
		else if(time > 1) {
			outfile << time - 1 << " ";
			int temp = time - 1;
			int t = 1;
			while (temp--) {
				outfile << loops[numLoop-t++]->idLoop << " ";
			}
		}
		outfile << 0 << " " << endl;
		face = face->nextFace;
	}

	outfile.close();
}