#include "MultiJittered.h"

MultiJittered::MultiJittered(void)
	: Sampler() {

}

MultiJittered::MultiJittered(const int _num_samples)
	: Sampler(_num_samples) {
		generate_samples();
}

MultiJittered::MultiJittered(const int _num_samples, const int _num_set)
	: Sampler(_num_samples, _num_set) {
		generate_samples();
}

MultiJittered::MultiJittered(const MultiJittered &copy)
	: Sampler(copy) {
		generate_samples();
}

MultiJittered::~MultiJittered(void) {

}

MultiJittered&
	MultiJittered::operator= (const MultiJittered &rhs) {
		if (this == &rhs)
			return (*this);
		Sampler::operator=(rhs);
		return (*this);
}

// 克隆新的MultiJittered，返回指针
MultiJittered*
	MultiJittered::clone(void) const {
		return (new MultiJittered(*this));
}

void
	MultiJittered::print(void) const {
		cout << "Regular" << endl;
		Sampler::print();
}

// 生成样本
void
	MultiJittered::generate_samples(void) {
		int n = (int)sqrt((float)num_samples);
		float subcell_width = 1.0 / ((float)num_samples);

		Point2D fill_point;
		for (int j = 0; j < num_samples * num_sets; j++)
			samples.push_back(fill_point);

		for (int p = 0; p < num_sets; p++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0, subcell_width);
					samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0, subcell_width);
				}
			}
		}

		for (int p = 0; p < num_sets; p++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int k = rand_int(j, n - 1);
					float t = samples[i * n + j + p * num_samples].x;
					samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
					samples[i * n + k + p * num_samples].x = t;
				}
			}
		}

		for (int p = 0; p < num_sets; p++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int k = rand_int(j, n - 1);
					float t = samples[j * n + i + p * num_samples].y;
					samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
					samples[k * n + i + p * num_samples].y = t;
				}
			}
		}
}