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

	// ����ˮƽ�ֱ���
	void
		set_hres(int _hres);

	// ���ô�ֱ�ֱ���
	void
		set_vres(int _hres);

	// �������ش�С
	void
		set_s(float _s);

	// ������ʾ����gamma���Ӽ��䵹��
	void
		set_gammas(float _gamma);

	// ������������
	void
		set_samples(int _num_samples);

	// ������������
	void 
		set_num_samples(int _num_samples);

	// ����������ֵ
	void
		set_max_depth(int _max_depth);

	void
		print(void) const;

public:

	int hres; // ˮƽ�ֱ���
	int vres; // ��ֱ�ֱ���
	float s; // ���ش�С
	float gamma; // ��ʾ����gamma����
	float inv_gamma; // ��ʾ����gamma���ӵĵ���
	Sampler *sampler_ptr; // ����ָ��
	int num_samples; // ��������
	int max_depth; // ������ֵ
};

// ����ˮƽ�ֱ���
inline void
	ViewPlane::set_hres(int _hres) {
		hres = _hres;
}

// ���ô�ֱ�ֱ���
inline void
	ViewPlane::set_vres(int _vres) {
		vres = _vres;
}

// �������ش�С
inline void
	ViewPlane::set_s(float _s) {
		s = _s;
}

// ������ʾ����gamma���Ӽ��䵹��
inline void
	ViewPlane::set_gammas(float _gamma) {
		gamma = _gamma;
		if (0.0 == _gamma)
			inv_gamma = 0.0;
		else
			inv_gamma = 1 / _gamma;
}

// ������������
inline void
	ViewPlane::set_num_samples(int _num_samples) {
		num_samples = _num_samples;
}

// ����������ֵ
inline void
	ViewPlane::set_max_depth(int _max_depth) {
		max_depth = _max_depth;
}

#endif