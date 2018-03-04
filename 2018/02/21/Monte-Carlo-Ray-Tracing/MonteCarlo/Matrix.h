#ifndef __MATRIX__
#define __MATRIX__

#define X 4
#define Y 4

class Matrix {
public:

	Matrix(void);
	Matrix(int c);
	Matrix(double mat[][Y]);
	Matrix(const Matrix &mat);

	~Matrix(void);

	Matrix&
		operator= (const Matrix &rhs);

	Matrix
		operator- (const Matrix &rhs);

	Matrix
		operator+ (const Matrix &c) const;

	Matrix&
		operator+= (const Matrix &rhs);

	Matrix
		operator- (const Matrix &c) const;

	Matrix&
		operator-= (const Matrix &rhs);

	Matrix
		operator* (const Matrix &c) const;

	Matrix&
		operator*= (const Matrix &rhs);

	Matrix
		operator/ (const Matrix &c) const;

	Matrix&
		operator/= (const Matrix &rhs);

	Matrix
		operator+ (const double c) const;

	Matrix&
		operator+= (const double rhs);

	Matrix
		operator- (const double c) const;

	Matrix&
		operator-= (const double rhs);

	Matrix
		operator* (const double c) const;

	Matrix&
		operator*= (const double rhs);

	Matrix
		operator/ (const double c) const;

	Matrix&
		operator/= (const double rhs);

	bool
		operator== (const Matrix &rhs) const;

	// 变为单位矩阵
	void
		set_identity(void);

	void
		print(void) const;

public:

	double m[X][Y];
};

#endif