#ifndef FILESTREAM
#define FILESTREAM

#include "header.h"

class CFileStream {
	char outerLoopPointsFileName[1000];
	char innerLoopsPointsFileName[1000];
	char directFileName[1000];
public:
	CFileStream();
	CCoordinate* ReadOuterLoopPoints(int *numPoints);
	void ReadInnerLoopsPoints(CCoordinate innerLoops_points[][20], int *numLoop, int *numPoints);
	CCoordinate ReadDirect();
	void GenerateDataStructure(CSolid *solid);
	void MakeBRP(CSolid *solid);
};

#endif