#include <iostream>
using namespace std;

#include "Matrix.h"

Matrix::Matrix(void) {
	for (int x = 0;x < X;x++)
		for (int y = 0;y < Y;y++) {
			if (x == y)
				m[x][y] = 1.0;
			else
				m[x][y] = 0.0;
		}
}

Matrix::Matrix(int c) {
	for (int x = 0;x < X;x++)
		for (int y = 0;y < Y;y++)
			m[x][y] = c;
}

Matrix::Matrix(double mat[][Y]) {
	for (int x = 0;x < X;x++)
		for (int y = 0;y < Y;y++)
			m[x][y] = mat[x][y];
}

Matrix::Matrix(const Matrix &mat) {
	for (int x = 0;x < X;x++)
		for (int y = 0;y < Y;y++)
			m[x][y] = mat.m[x][y];
}

Matrix::~Matrix(void) {

}

Matrix&
	Matrix::operator= (const Matrix &rhs) {
		if (this == &rhs)
			return (*this);

		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] = rhs.m[x][y];

		return (*this);
}

Matrix
	Matrix::operator- (const Matrix &rhs) {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = -m[x][y];

		return Matrix(t);
}

Matrix
	Matrix::operator+ (const Matrix &c) const {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = m[x][y] + c.m[x][y];

		return Matrix(t);
}

Matrix&
	Matrix::operator+= (const Matrix &rhs) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] += rhs.m[x][y];

		return (*this);
}

Matrix
	Matrix::operator- (const Matrix &c) const {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = m[x][y] - c.m[x][y];

		return Matrix(t);
}

Matrix&
	Matrix::operator-= (const Matrix &rhs) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] -= rhs.m[x][y];

		return (*this);
}

Matrix
	Matrix::operator* (const Matrix &c) const {
		double t[X][Y];
		for (int y = 0;y < Y;y++) {
			for (int x = 0;x < X;x++) {
				double sum = 0.0;
				for (int j = 0;j < X;j++)
					sum += m[x][j] * c.m[j][y];

				t[x][y] = sum;			
			}
		}

		return Matrix(t);
}

Matrix&
	Matrix::operator*= (const Matrix &rhs) {
		double t[X][Y];
		for (int y = 0;y < Y;y++) {
			for (int x = 0;x < X;x++) {
				double sum = 0.0;
				for (int j = 0;j < X;j++)
					sum += m[x][j] * rhs.m[j][y];

				t[x][y] = sum;			
			}
		}
		
		(*this) = Matrix(t);
		return (*this);
}

Matrix
	Matrix::operator/ (const Matrix &c) const {
		// invert
		return NULL;
}

Matrix&
	Matrix::operator/= (const Matrix &rhs) {
		// invert
		return (*this);
}

Matrix
	Matrix::operator+ (const double c) const {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = m[x][y] + c;

		return Matrix(t);
}

Matrix&
	Matrix::operator+= (const double rhs) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] += rhs;

		return (*this);
}

Matrix
	Matrix::operator- (const double c) const {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = m[x][y] - c;

		return Matrix(t);
}

Matrix&
	Matrix::operator-= (const double rhs) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] -= rhs;

		return (*this);
}

Matrix
	Matrix::operator* (const double c) const {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = m[x][y] * c;

		return Matrix(t);
}

Matrix&
	Matrix::operator*= (const double rhs) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] *= rhs;

		return (*this);
}

Matrix
	Matrix::operator/ (const double c) const {
		double t[X][Y];
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				t[x][y] = m[x][y] / c;

		return Matrix(t);
}

Matrix&
	Matrix::operator/= (const double rhs) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				m[x][y] /= rhs;

		return (*this);
}

bool
	Matrix::operator== (const Matrix &rhs) const {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++)
				if (m[x][y] != rhs.m[x][y]) return false;
		return true;
}

// 变为单位矩阵
void
	Matrix::set_identity(void) {
		for (int x = 0;x < X;x++)
			for (int y = 0;y < Y;y++) {
				if (x == y)
					m[x][y] = 1.0;
				else
					m[x][y] = 0.0;
			}
}

void
	Matrix::print(void) const {
		for (int x = 0;x < X;x++) {
			for (int y = 0;y < Y;y++)
				printf("%5.2lf", m[x][y]);
			cout << endl;
		}
		cout << endl;
}