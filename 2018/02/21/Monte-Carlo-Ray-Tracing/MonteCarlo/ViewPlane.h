#ifndef __VIEWPLANE__
#define __VIEWPLANE__

#include "Sampler.h"
#include "Regular.h"
#include "MultiJittered.h"

class ViewPlane {
public:

	ViewPlane();
	ViewPlane(const ViewPlane &copy);
	
	~ViewPlane(void);

	// 设置水平分辨率
	void
		set_hres(int _hres);

	// 设置垂直分辨率
	void
		set_vres(int _hres);

	// 设置像素大小
	void
		set_s(float _s);

	// 设置显示器的gamma因子及其倒数
	void
		set_gammas(float _gamma);

	// 设置样本参数
	void
		set_samples(int _num_samples);

	// 设置样本数量
	void 
		set_num_samples(int _num_samples);

	// 设置最大深度值
	void
		set_max_depth(int _max_depth);

	void
		print(void) const;

public:

	int hres; // 水平分辨率
	int vres; // 垂直分辨率
	float s; // 像素大小
	float gamma; // 显示器的gamma因子
	float inv_gamma; // 显示器的gamma因子的倒数
	Sampler *sampler_ptr; // 样本指针
	int num_samples; // 样本数量
	int max_depth; // 最大深度值
};

// 设置水平分辨率
inline void
	ViewPlane::set_hres(int _hres) {
		hres = _hres;
}

// 设置垂直分辨率
inline void
	ViewPlane::set_vres(int _vres) {
		vres = _vres;
}

// 设置像素大小
inline void
	ViewPlane::set_s(float _s) {
		s = _s;
}

// 设置显示器的gamma因子及其倒数
inline void
	ViewPlane::set_gammas(float _gamma) {
		gamma = _gamma;
		if (0.0 == _gamma)
			inv_gamma = 0.0;
		else
			inv_gamma = 1 / _gamma;
}

// 设置样本数量
inline void
	ViewPlane::set_num_samples(int _num_samples) {
		num_samples = _num_samples;
}

// 设置最大深度值
inline void
	ViewPlane::set_max_depth(int _max_depth) {
		max_depth = _max_depth;
}

#endif