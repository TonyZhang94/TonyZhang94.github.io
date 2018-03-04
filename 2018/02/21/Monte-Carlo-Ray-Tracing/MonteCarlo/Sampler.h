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

	int num_samples; // 单位区域内采样点的数量
	int num_sets; // 样本集的数目
	vector<Point2D> samples; // 单位区域内的样本点
	vector<int> shuffled_indices; // 混乱样本索引的数组
	vector<Point2D> disk_samples;
	vector<Point3D> hemisphere_samples;
	vector<Point3D> sphere_samples;
	unsigned long count; // 现在用了多少个样本点
	int jump; // 索引随机的jump

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

	// 设置样本集的数目
	void
		set_num_sets(const int np);

	// 纯虚函数，在单位正方形内生成采样点
	virtual void
		generate_samples(void) = 0;

	// 获取单位区域内采用点的数量
	int
		get_num_samples(void);

	// 随机混乱x坐标
	void
		shuffle_x_coordinates(void);

	// 随机混乱y坐标
	void
		shuffle_y_coordinates(void);

	// 设置混乱的索引
	void
		setup_shuffled_indices(void);

	void
		map_samples_to_unit_disk(void);

	void
		map_samples_to_hemisphere(const float p);

	void
		map_samples_to_sphere(void);

	// 返回存储于采样器的下一个采样点
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