#ifndef CLASSCOORDINATE
#define CLASSCOORDINATE

class CCoordinate {
public:
	double m_x;
	double m_y;
	double m_z;
public:
	CCoordinate();
	CCoordinate(double x, double y, double z);
	~CCoordinate();
	void CoordinateCopy(const CCoordinate *xyz);
	bool CoordinateEqual(const CCoordinate *xyz);
	CCoordinate* CCoordinateAdd(const CCoordinate *xyz);
	double* PointToDouble();
};

#endif