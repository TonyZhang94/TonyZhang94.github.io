#include "EulerOperator.h"
#include "FileStream.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <gl\glut.h>
#include <windows.h>
#include <time.h>

CFileStream *myFileStream = new CFileStream();

CSolid* GenerateSolid() {
	int numOuterLoopPoints = 0;
	CCoordinate *outerLoop_points = myFileStream->ReadOuterLoopPoints(&numOuterLoopPoints);

	int numLoops = 0;
	int numInnerLoopsPoints[1000];
	CCoordinate innerLoops_points[1000][20];
	myFileStream->ReadInnerLoopsPoints(innerLoops_points, &numLoops, numInnerLoopsPoints);
	
	CEulerOperator *euler = new CEulerOperator;
	CSolid *solid = euler->mvfs(&outerLoop_points[0]);

	CLoop *newLoop = solid->firstFace->firstLoop;
	CLoop *outerLoop = newLoop;
	for (int i = 0;i < numOuterLoopPoints-1;i++) {
		euler->mev(&outerLoop_points[i], &outerLoop_points[i+1], newLoop);
	}
	euler->mef(&outerLoop_points[numOuterLoopPoints-1], &outerLoop_points[0], newLoop);

	for (int i = 0;i < numLoops;i++) {
		newLoop = solid->firstFace->nextFace->firstLoop;
		euler->mev(&outerLoop_points[0], &innerLoops_points[i][0], newLoop);
		newLoop = euler->kemr(&outerLoop_points[0], &innerLoops_points[i][0], newLoop);
		for (int j = 0;j < numInnerLoopsPoints[i]-1;j++) {
			euler->mev(&innerLoops_points[i][j], &innerLoops_points[i][j+1], newLoop);
		}
		CLoop* innerLoop = euler->mef(&innerLoops_points[i][numInnerLoopsPoints[i]-1], &innerLoops_points[i][0], newLoop);
		euler->kfmrh(outerLoop, innerLoop);
		//newLoop = solid->firstFace->nextFace->firstLoop;
		//euler->kef(&outerLoop_points[0], &innerLoops_points[i][0], newLoop);
	}

	CCoordinate direct = myFileStream->ReadDirect();
	euler->Sweep(solid->firstFace, &direct);

	return solid;
}

CSolid *mSolid;

void ChangeSize(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void RenderScene(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(4, 1.5, 2, 0, 0, 0, 1, 1, 0);

	glColor3f(0, 0, 0);
	glLineWidth(2.0f);

	glBegin(GL_LINES);
	CEdge *window_edge = mSolid->firstEdge;
	double *point;
	while (NULL != window_edge) {
		point = window_edge->v1->xyz->PointToDouble();
		glVertex3f(point[0], point[1], point[2]);
		point = window_edge->v2->xyz->PointToDouble();
		glVertex3f(point[0], point[1], point[2]);
		window_edge = window_edge->nextEdge;
		double a = 0.5, b = 0;
	}

	glEnd();
	glFlush();
}

void Rendering(CSolid *solid, int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(400, 150);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("CallÅ¼Î§³ÇXXXXXXXX");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
}

int main(int argc, char* argv[]) {
	CSolid *solid = GenerateSolid();
	mSolid = solid;

	myFileStream->GenerateDataStructure(solid);
	myFileStream->MakeBRP(solid);

	Rendering(solid, argc, argv);

	return 0;
}