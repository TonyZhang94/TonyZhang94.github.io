#include "Coordinate.h"

CCoordinate::CCoordinate() {
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

CCoordinate::CCoordinate(double x, double y, double z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

CCoordinate::~CCoordinate() {

}

void CCoordinate::CoordinateCopy(const CCoordinate *xyz) {
	this->m_x = xyz->m_x;
	this->m_y = xyz->m_y;
	this->m_z = xyz->m_z;
}

bool CCoordinate::CoordinateEqual(const CCoordinate *xyz) {
	if (this->m_x != xyz->m_x) return false;
	if (this->m_y != xyz->m_y) return false;
	if (this->m_z != xyz->m_z) return false;
	return true;
}

CCoordinate* CCoordinate::CCoordinateAdd(const CCoordinate *xyz) {
	double x = m_x + xyz->m_x;
	double y = m_y + xyz->m_y;
	double z = m_z + xyz->m_z;
	CCoordinate *temp = new CCoordinate(x, y, z);

	return temp;
}

double* CCoordinate::PointToDouble() {
	double point[3];
	point[0] = m_x;
	point[1] = m_y;
	point[2] = m_z;

	return point;
}