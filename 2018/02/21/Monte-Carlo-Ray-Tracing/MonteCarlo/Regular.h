#ifndef __REGULAR__
#define __REGULAR__

#include "Sampler.h"

class Regular: public Sampler {
public:

	Regular(void);
	Regular(const int _num_samples);
	Regular(const int _num_samples, const int _num_sets);
	Regular(const Regular &copy);

	virtual ~Regular(void);

	Regular&
		operator= (const Regular &rhs);

	// 克隆新的Regular，返回指针
	virtual Regular*
		clone(void) const;

	void
		print(void) const;
	
private:

	// 生成样本
	virtual void
		generate_samples(void);	
};

#endif