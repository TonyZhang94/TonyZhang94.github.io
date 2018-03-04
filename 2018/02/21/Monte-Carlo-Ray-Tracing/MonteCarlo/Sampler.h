#ifndef __SAMPLER__
#define __SAMPLER__

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#include "Point2D.h"
#include "Point3D.h"
#include "Constants.h"
#include "Maths.h"

class Sampler {
protected:

	int num_samples; // ��λ�����ڲ����������
	int num_sets; // ����������Ŀ
	vector<Point2D> samples; // ��λ�����ڵ�������
	vector<int> shuffled_indices; // ������������������
	vector<Point2D> disk_samples;
	vector<Point3D> hemisphere_samples;
	vector<Point3D> sphere_samples;
	unsigned long count; // �������˶��ٸ�������
	int jump; // ���������jump

public:

	Sampler(void);
	Sampler(const int _num_samples);
	Sampler(const int _num_samples, const int _num_sets);
	Sampler(const Sampler &copy);

	virtual ~Sampler(void);

	Sampler&
		operator= (const Sampler &rhs);

	virtual Sampler*
		clone(void) const = 0;

	// ��������������Ŀ
	void
		set_num_sets(const int np);

	// ���麯�����ڵ�λ�����������ɲ�����
	virtual void
		generate_samples(void) = 0;

	// ��ȡ��λ�����ڲ��õ������
	int
		get_num_samples(void);

	// �������x����
	void
		shuffle_x_coordinates(void);

	// �������y����
	void
		shuffle_y_coordinates(void);

	// ���û��ҵ�����
	void
		setup_shuffled_indices(void);

	void
		map_samples_to_unit_disk(void);

	void
		map_samples_to_hemisphere(const float p);

	void
		map_samples_to_sphere(void);

	// ���ش洢�ڲ���������һ��������
	Point2D
		sample_unit_square(void);

	Point2D
		sample_unit_disk(void);

	Point3D
		sample_hemisphere(void);

	Point3D
		sample_sphere(void);

	Point2D
		sample_one_set(void);

	void
		print(void) const;
};

#endif