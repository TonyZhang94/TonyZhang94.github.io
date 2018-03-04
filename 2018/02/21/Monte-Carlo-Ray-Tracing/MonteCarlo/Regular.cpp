#include "Regular.h"

Regular::Regular(void)
	: Sampler() {

}

Regular::Regular(const int _num_samples)
	: Sampler(_num_samples) {
		generate_samples();
}

Regular::Regular(const int _num_samples, const int _num_sets)
	: Sampler(_num_samples, _num_sets) {
		generate_samples();
}

Regular::Regular(const Regular &copy)
	: Sampler(copy) {
		generate_samples();
}

Regular::~Regular(void) {

}

Regular&
	Regular::operator= (const Regular &rhs)	{
		if (this == &rhs)
			return (*this);
		Sampler::operator= (rhs);
		return (*this);
}

// 克隆新的Regular，返回指针
Regular*
	Regular::clone(void)const {
		return new Regular(*this);
}

void
	Regular::print(void) const {
		cout << "Regular" << endl;
		Sampler::print();
}

// 生成样本
void
	Regular::generate_samples(void) {
		int n = (int) sqrt((float)num_samples);

		for (int j = 0; j < num_sets; j++)
			// 将样本组成方阵形式
			for (int p = 0; p < n; p++)
				for (int q = 0; q < n; q++)
					samples.push_back(Point2D((q+0.5)/n, (p+0.5)/n));
}