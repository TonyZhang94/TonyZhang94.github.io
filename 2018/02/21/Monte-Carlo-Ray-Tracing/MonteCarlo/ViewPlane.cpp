#include "ViewPlane.h"

ViewPlane::ViewPlane(void)
	: hres(0), vres(0), s(0), gamma(0), inv_gamma(0), sampler_ptr(NULL), num_samples(0), max_depth(0) {

};

ViewPlane::ViewPlane(const ViewPlane &copy) {
	sampler_ptr = copy.sampler_ptr;
	hres = copy.hres;
	vres = copy.vres;
	s = copy.s;
	gamma = copy.gamma;
	inv_gamma = copy.inv_gamma;
	num_samples = copy.num_samples;
	max_depth = copy.max_depth;
}

ViewPlane::~ViewPlane(void) {
	if (NULL != sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
}

// 设置样本参数
void ViewPlane::set_samples(int _num_samples) {
	if (NULL != sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if (_num_samples > 1)
		sampler_ptr = new MultiJittered(_num_samples);
	else
		sampler_ptr = new Regular(1);
}

void
	ViewPlane::print(void) const {
		cout << "hres = " << hres << endl;
		cout << "vres = " << vres << endl;
		cout << "s = " << s << endl;
		cout << "gamma = " << gamma << endl;
		cout << "inv_gamma = " << inv_gamma << endl;
		if (NULL != sampler_ptr) {
			cout << "sampler_ptr:" << endl;
			sampler_ptr->print();
		}
		else
			cout << "sampler_ptr is NULL" << endl;
		cout << "num_samples = " << num_samples << endl;
		cout << "max_depth = " << max_depth << endl;
}