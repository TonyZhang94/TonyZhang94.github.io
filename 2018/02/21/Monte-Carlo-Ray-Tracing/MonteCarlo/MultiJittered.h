#ifndef __MULTIJITTERED__
#define __MULTIJITTERED__

#include "Maths.h"
#include "Sampler.h"

class MultiJittered: public Sampler {
public:

	MultiJittered(void);
	MultiJittered(const int _num_samples);
	MultiJittered(const int _num_samples, const int _num_sets);
	MultiJittered(const MultiJittered &copy);

	virtual ~MultiJittered(void);

	MultiJittered&
		operator= (const MultiJittered &rhs);

	// ��¡�µ�MultiJittered������ָ��
	virtual MultiJittered*
		clone(void) const;

	void
		print(void) const;

private:

	// ��������
	virtual void
		generate_samples(void);
};

#endif