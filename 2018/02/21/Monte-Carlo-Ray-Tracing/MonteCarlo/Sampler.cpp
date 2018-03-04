#include "Sampler.h"

#define NUMSET 83

Sampler::Sampler(void)
	: num_samples(1), num_sets(NUMSET), count(0), jump(0) {
		samples.reserve(num_samples*num_sets);
		setup_shuffled_indices();
}

Sampler::Sampler(const int _num_samples)
	: num_samples(_num_samples), num_sets(NUMSET), count(0), jump(0) {
		samples.reserve(num_samples*num_sets);
		setup_shuffled_indices();
}

Sampler::Sampler(const int _num_samples, const int _num_sets)
	: num_samples(_num_samples), num_sets(_num_sets), count(0), jump(0) {
		samples.reserve(num_samples*num_sets);
		setup_shuffled_indices();
}

Sampler::Sampler(const Sampler &copy)
	: num_samples(copy.num_samples),
	  num_sets(copy.num_sets),
	  samples(copy.samples),
	  shuffled_indices(copy.shuffled_indices),
	  disk_samples(copy.disk_samples),
	  hemisphere_samples(copy.hemisphere_samples),
	  sphere_samples(copy.sphere_samples),
	  count(copy.count),
	  jump(copy.jump) {

}

Sampler&
	Sampler::operator= (const Sampler &rhs)	{
		if (this == &rhs)
			return (*this);

		num_samples = rhs.num_samples;
		num_sets = rhs.num_sets;
		samples = rhs.samples;
		shuffled_indices = rhs.shuffled_indices;
		disk_samples = rhs.disk_samples;
		hemisphere_samples = rhs.hemisphere_samples;
		sphere_samples = rhs.sphere_samples;
		count = rhs.count;
		jump = rhs.jump;

		return (*this);
}

Sampler::~Sampler(void) {

}

// 设置样本集的数目
void
	Sampler::set_num_sets(const int np) {
		num_sets = np;
}

// 获取单位区域内采用点的数量
int
	Sampler::get_num_samples(void) {
		return num_samples;
}

// 随机混乱x坐标
void
	Sampler::shuffle_x_coordinates(void) {
		for (int p = 0;p < num_sets;p++) {
			for (int i = 0;i <  num_samples-1;i++) {
				// 随机生成索引位置，并与当前位置交换x值
				int target = rand_int() % num_samples + p * num_samples;
				float temp = samples[i+p*num_samples+1].x;
				samples[i+p*num_samples+1].x = samples[target].x;
				samples[target].x = temp;
			}
		}
}

// 随机混乱y坐标
void
	Sampler::shuffle_y_coordinates(void) {
		for (int p = 0;p < num_sets;p++) {
			for (int i = 0;i <  num_samples-1;i++) {
				// 随机生成索引位置，并与当前位置交换y值
				int target = rand_int() % num_samples + p * num_samples;
				float temp = samples[i+p*num_samples+1].y;
				samples[i+p*num_samples+1].y = samples[target].y;
				samples[target].y = temp;
			}
		}
}

// 设置混乱的索引
void											
	Sampler::setup_shuffled_indices(void) {
		shuffled_indices.reserve(num_samples*num_sets);
		vector<int> indices;

		for (int i = 0;i < num_samples;i++)
			indices.push_back(i);

		for (int p = 0;p < num_sets;p++) {
			// 每个集合的索引都要打乱
			random_shuffle(indices.begin(), indices.end()); 	

			// 将打乱的索引放入混乱样本索引的数组
			for (int i = 0;i < num_samples;i++)
				shuffled_indices.push_back(indices[i]);
		}	
}

void
	Sampler::map_samples_to_unit_disk(void) {
		int size = samples.size();
		float r, phi;
		Point2D sp;
	
		disk_samples.reserve(size);
		
		for (int j = 0;j < size;j++) {
			sp.x = 2.0 * samples[j].x - 1.0;
			sp.y = 2.0 * samples[j].y - 1.0;
			
			if (sp.x > -sp.y) {
				if (sp.x > sp.y) {
					r = sp.x;
					phi = sp.y / sp.x;
				}
				else {
					r = sp.y;
					phi = 2 - sp.x / sp.y;
				}
			}
			else {
				if (sp.x < sp.y) {
					r = -sp.x;
					phi = 4 + sp.y / sp.x;
				}
				else {
					r = -sp.y;
					if (sp.y != 0.0)
						phi = 6 - sp.x / sp.y;
					else
						phi  = 0.0;
				}
			}
		
			phi *= PI / 4.0;
			
			disk_samples[j].x = r * cos(phi);
			disk_samples[j].y = r * sin(phi);
		}

		samples.erase(samples.begin(), samples.end());
}

void
	Sampler::map_samples_to_hemisphere(const float exp) {
		int size = samples.size();
		hemisphere_samples.reserve(num_samples * num_sets);
		
		for (int j = 0;j < size;j++) {
			float cos_phi = cos(2.0 * PI * samples[j].x);
			float sin_phi = sin(2.0 * PI * samples[j].x);
			float cos_theta = pow((1.0 - samples[j].y), 1.0 / (exp + 1.0));
			float sin_theta = sqrt (1.0 - cos_theta * cos_theta);
			float pu = sin_theta * cos_phi;
			float pv = sin_theta * sin_phi;
			float pw = cos_theta;
			hemisphere_samples.push_back(Point3D(pu, pv, pw));
		}
}

void
	Sampler::map_samples_to_sphere(void) {
		float r1, r2;
		float x, y, z;
		float r, phi;
		
		sphere_samples.reserve(num_samples * num_sets);
		
		for (int j = 0;j < num_samples * num_sets;j++) {
			r1 	= samples[j].x;
    		r2 	= samples[j].y;
    		z 	= 1.0 - 2.0 * r1;
    		r 	= sqrt(1.0 - z * z);
    		phi = TWO_PI * r2;
    		x 	= r * cos(phi);
    		y 	= r * sin(phi);
			sphere_samples.push_back(Point3D(x, y, z));
		}
}

//Point2D
//	Sampler::sample_unit_square(void) {
//		if (count % num_samples == 0)
//			jump = (rand_int() % num_sets) * num_samples;
//
//		return (samples[jump + count++ % num_samples]);
//}

//Point2D
//	Sampler::sample_unit_square(void) {
//		return (samples[count++ % (num_samples * num_sets)]);
//}

Point2D
	Sampler::sample_unit_square(void) {
		if (0 == count % num_samples)
			jump = (rand_int() % num_sets) * num_samples;

		return samples[jump+shuffled_indices[jump+count++%num_samples]];
}

Point2D
	Sampler::sample_unit_disk(void) {
		if (0 == count % num_samples)
			jump = (rand_int() % num_sets) * num_samples;
	
		return disk_samples[jump+shuffled_indices[jump+count++%num_samples]];
}

Point3D
	Sampler::sample_hemisphere(void) {
		if (0 == count % num_samples)
			jump = (rand_int() % num_sets) * num_samples;
		
		return hemisphere_samples[jump+shuffled_indices[jump+count++%num_samples]];
}

Point3D
	Sampler::sample_sphere(void) {
		if (0 == count % num_samples)
			jump = (rand_int() % num_sets) * num_samples;
		
		return sphere_samples[jump+shuffled_indices[jump+count++%num_samples]];
}

Point2D
	Sampler::sample_one_set(void) {
		return(samples[count++ % num_samples]); 
}

void
	Sampler::print(void) const {
		cout << "num_samples = " << num_samples << endl
			<< "num_sets = " << num_sets << endl;
		cout << "samples:" << endl;
		int cnt = samples.size();
		for (int i = 0; i < cnt;i++)
			samples.at(i).print();
		cout << "shuffled_indices:" << endl;
		cnt = shuffled_indices.size();
		for (int i = 0; i < cnt;i++)
			cout << shuffled_indices.at(i) << endl;
		cout << "count = " << count << endl
			<< "jump" << jump << endl;
}



