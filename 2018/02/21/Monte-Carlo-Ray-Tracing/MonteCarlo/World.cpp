#include "World.h"

World::World(void) {
	
}

World::World(Model *_model, char _sc)
	: vp(NULL), background_color(black), tracer_ptr(NULL), camera_ptr(NULL),
	ambient_ptr(new Ambient), image(NULL), model(_model), sc(_sc) {

}

World::~World(void) {

}

// 构建场景
void
	World::build(unsigned char *image, int window_size) {
		if ('1' == sc) {
			int num_samples = 200;
			Sampler *sampler_ptr1 = new MultiJittered(num_samples); // 新建采样器

			// 设置视平面参数
			vp = new ViewPlane();
			vp->hres = window_size;
			vp->vres = window_size;
			vp->s = 0.5;
			vp->num_samples = num_samples;
			vp->max_depth = 10;
			vp->sampler_ptr = sampler_ptr1;
			tracer_ptr = new AreaLighting(this);

			// 黑色背景
			background_color = RGBColor(black);

			// 设置相机参数
			Pinhole *pinhole_ptr = new Pinhole;
			pinhole_ptr->set_eye(0, 0, 35);
			pinhole_ptr->set_lookat(0, 0, 0);
			pinhole_ptr->set_d(160);
			pinhole_ptr->compute_uvw();
			camera_ptr = pinhole_ptr;

			// 设置自发光材料参数
			Emissive* emissive_ptr = new Emissive;
			emissive_ptr->set_ls(50);
			Emissive* emissive_ptr1 = new Emissive;
			emissive_ptr1->set_ls(1);

			// 光源
			Rectangle* rectangle_ptr = new Rectangle(Point3D(2, 7, 0), Vector3D(-4, 0, 0), Vector3D(0, 0, 4), Normal(0, -1, 0));
			rectangle_ptr->set_material(emissive_ptr);
			rectangle_ptr->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr);

			// 区域光照
			AreaLight* area_light_ptr = new AreaLight;
			area_light_ptr->set_object_ptr(rectangle_ptr);
			add_light(area_light_ptr);

			// 设置有光泽材质的参数
			GlossyReflector* glossy_ptr = new GlossyReflector;
			glossy_ptr->set_samples(num_samples, 10000);
			glossy_ptr->set_ka(0.0);
			glossy_ptr->set_kd(0.0);
			glossy_ptr->set_ks(0.0);
			glossy_ptr->set_exp(10000);
			glossy_ptr->set_cd(black);
			glossy_ptr->set_ks(0.8);
			glossy_ptr->set_exp(10000);
			glossy_ptr->set_cr(white);

			// 设置粗糙材料的参数
			Matte* matte_ptr1 = new Matte;
			matte_ptr1->set_ka(0.5);
			matte_ptr1->set_kd(0.75);
			matte_ptr1->set_cd(0.7, 0.7, 0.7);

			Matte* lambert2SG = new Matte;
			lambert2SG->set_cd(0.8, 0.3, 0.2);
			lambert2SG->set_ka(0.25);
			lambert2SG->set_kd(0.75);

			Matte* lambert3SG = new Matte;
			lambert3SG->set_cd(0.3, 0.16, 0.8);
			lambert3SG->set_ka(0.25);
			lambert3SG->set_kd(0.75);

			// 构造长方体，加入场景
			Rectangle* rectangle_ptr1 = new Rectangle(Point3D(-10, 7.5, 10), Vector3D(0, 0, -20), Vector3D(0, -15, 0), Normal(1, 0, 0));
			rectangle_ptr1->set_material(lambert2SG);
			rectangle_ptr1->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr1);

			Rectangle* rectangle_ptr2 = new Rectangle(Point3D(-10, 7.5, -10), Vector3D(20, 0, 0), Vector3D(0, -15, 0), Normal(0, 0, 1));
			rectangle_ptr2->set_material(matte_ptr1);
			rectangle_ptr2->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr2);

			Rectangle* rectangle_ptr3 = new Rectangle(Point3D(10, 7.5, -10), Vector3D(0, 0, 20), Vector3D(0, -15, 0), Normal(-1, 0, 0));
			rectangle_ptr3->set_material(lambert3SG);
			rectangle_ptr3->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr3);

			Rectangle* rectangle_ptr4 = new Rectangle(Point3D(10, 7.5, -10), Vector3D(-20, 0, 0), Vector3D(0, 0, 20), Normal(0, -1, 0));
			rectangle_ptr4->set_material(matte_ptr1);
			rectangle_ptr4->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr4);

			Rectangle* rectangle_ptr5 = new Rectangle(Point3D(10, -7.5, -10), Vector3D(-20, 0, 0), Vector3D(0, 0, 20), Normal(0, 1, 0));
			rectangle_ptr5->set_material(matte_ptr1);
			rectangle_ptr5->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr5);

			// 构造球，设置参数，加入场景
			Sphere *sphere = new Sphere(Point3D(4, -5, 4), 2.5);
			sphere->set_material(glossy_ptr);
			add_object(sphere);

			Sphere *sphere2 = new Sphere(Point3D(-3, -5, -3), 2.5);
			sphere2->set_material(glossy_ptr);
			add_object(sphere2);
		}
		else {
			int num_samples = 160;
			Sampler* sampler_ptr1 = new MultiJittered(num_samples); // 新建采样器

			// 设置视平面参数
			vp = new ViewPlane();
			vp->hres = 200;
			vp->vres = 200;
			vp->s = 0.5;
			vp->num_samples = num_samples;
			vp->max_depth = 0;
			vp->sampler_ptr = sampler_ptr1;
			tracer_ptr = new AreaLighting(this);

			// 灰色背景
			background_color = RGBColor(gray);

			// 设置相机参数
			Pinhole* pinhole_ptr = new Pinhole;
			pinhole_ptr->set_eye(2, 45, 100);
			pinhole_ptr->set_lookat(2, 2, 0);
			pinhole_ptr->set_d(800);
			pinhole_ptr->compute_uvw();
			camera_ptr = pinhole_ptr;

			// 设置自发光材料参数
			Emissive* emissive_ptr = new Emissive;
			emissive_ptr->set_ls(500);

			// 构造长方体，加入场景
			Rectangle* rectangle_ptr = new Rectangle(Point3D(0, 50, 0), Vector3D(-10, 0, 0), Vector3D(0, 0, 10), Normal(0, -1, 0));
			rectangle_ptr->set_material(emissive_ptr);
			rectangle_ptr->set_sampler(sampler_ptr1);
			add_object(rectangle_ptr);

			// 设置区域光照参数
			AreaLight* area_light_ptr = new AreaLight;
			area_light_ptr->set_object_ptr(rectangle_ptr);
			add_light(area_light_ptr);

			// 设置有光泽材质的参数
			GlossyReflector* glossy_ptr = new GlossyReflector;
			glossy_ptr->set_samples(num_samples, 10000);
			glossy_ptr->set_ka(0.0);
			glossy_ptr->set_kd(0.0);
			glossy_ptr->set_ks(0.0);
			glossy_ptr->set_exp(10000);
			glossy_ptr->set_cd(black);
			glossy_ptr->set_ks(0.8);
			glossy_ptr->set_exp(10000);
			glossy_ptr->set_cr(white);

			GlossyReflector* glossy_ptr2 = new GlossyReflector;
			glossy_ptr2->set_samples(num_samples, 5000);
			glossy_ptr2->set_ka(0.0);
			glossy_ptr2->set_kd(0.0);
			glossy_ptr2->set_ks(0.0);
			glossy_ptr2->set_exp(5000);
			glossy_ptr2->set_cd(black);
			glossy_ptr2->set_ks(0.8);
			glossy_ptr2->set_exp(5000);
			glossy_ptr2->set_cr(white);

			GlossyReflector* glossy_ptr3 = new GlossyReflector;
			glossy_ptr3->set_samples(num_samples, 1000);
			glossy_ptr3->set_ka(0.0);
			glossy_ptr3->set_kd(0.0);
			glossy_ptr3->set_ks(0.0);
			glossy_ptr3->set_exp(1000);
			glossy_ptr3->set_cd(black);
			glossy_ptr3->set_ks(0.8);
			glossy_ptr3->set_exp(1000);
			glossy_ptr3->set_cr(white);

			GlossyReflector* glossy_ptr4 = new GlossyReflector;
			glossy_ptr4->set_samples(num_samples, 500);
			glossy_ptr4->set_ka(0.0);
			glossy_ptr4->set_kd(0.0);
			glossy_ptr4->set_ks(0.0);
			glossy_ptr4->set_exp(500);
			glossy_ptr4->set_cd(black);
			glossy_ptr4->set_ks(0.8);
			glossy_ptr4->set_exp(500);
			glossy_ptr4->set_cr(white);

			// 设置粗糙材料参数
			Matte* matte_ptr1 = new Matte;
			matte_ptr1->set_ka(0.25);
			matte_ptr1->set_kd(0.5);
			matte_ptr1->set_cd(1, 1, 1);

			Matte* lambert2SG = new Matte;
			lambert2SG->set_cd(1.0, 1.0, 1.0);
			lambert2SG->set_ka(1);
			lambert2SG->set_kd(1);

			Matte* lambert3SG = new Matte;
			lambert3SG->set_cd(1.0, 1.0, 1.0);
			lambert3SG->set_ka(1);
			lambert3SG->set_kd(1);

			Matte* lambert4SG = new Matte;
			lambert4SG->set_cd(1, 1, 1);
			lambert4SG->set_ka(1);
			lambert4SG->set_kd(1);

			Matte* lambert5SG = new Matte;
			lambert5SG->set_cd(1, 1, 1);
			lambert5SG->set_ka(1);
			lambert5SG->set_kd(1);

			// 设置Phong光照参数
			Phong* phong_ptr = new Phong;
			phong_ptr->set_ka(0.25);
			phong_ptr->set_kd(0.75);
			phong_ptr->set_cd(0.5);
			phong_ptr->set_cd(0.2, 0.5, 0.4);
			phong_ptr->set_ks(0.2);
			phong_ptr->set_exp(20.0);

			// 设置三角片参数，加入场景
			// cout << model->faceList.size() << endl;
			for (vector<Face>::iterator it = model->faceList.begin(); it != model->faceList.end(); it++) {
				Material *m;
				if ((*it).material == "initialShadingGroup")
					m = matte_ptr1;
				else if ((*it).material == "lambert2SG")
					m = lambert2SG;
				else if ((*it).material == "lambert3SG")
					m = lambert3SG;
				else if ((*it).material == "lambert4SG")
					m = lambert4SG;
				else if ((*it).material == "lambert5SG")
					m = lambert5SG;
				else if ((*it).material == "mia_material_x_passes1SG")
					m = glossy_ptr;
				else if ((*it).material == "mia_material_x_passes4SG")
					m = glossy_ptr2;
				else if ((*it).material == "mia_material_x_passes2SG")
					m = glossy_ptr3;
				else if ((*it).material == "mia_material_x_passes3SG")
					m = glossy_ptr4;
				else
					m = matte_ptr1;
				Vertex v1 = model->vertexList[(*it).v1 - 1];
				Vertex v2 = model->vertexList[(*it).v2 - 1];
				Vertex v3 = model->vertexList[(*it).v3 - 1];
				if ((*it).v4 == -1) {
					Triangle* tr = new Triangle(Point3D(v1.x, v1.y, v1.z), Point3D(v2.x, v2.y, v2.z), Point3D(v3.x, v3.y, v3.z));
					tr->set_material(m);
					tr->set_sampler(sampler_ptr1);
					add_object(tr);
				}
				else { // 有第四个顶点时再构造一个新的三角片
					Vertex v4 = model->vertexList[(*it).v4 - 1];
					Triangle* tr1 = new Triangle(Point3D(v1.x, v1.y, v1.z), Point3D(v2.x, v2.y, v2.z), Point3D(v3.x, v3.y, v3.z));
					tr1->set_material(m);
					tr1->set_sampler(sampler_ptr1);
					Triangle* tr2 = new Triangle(Point3D(v1.x, v1.y, v1.z), Point3D(v3.x, v3.y, v3.z), Point3D(v4.x, v4.y, v4.z));
					tr2->set_material(m);
					tr2->set_sampler(sampler_ptr1);
					add_object(tr1);
					add_object(tr2);
				}
			}
		}
		this->image = image;
}

// 添加几何物体
void
	World::add_object(GeometricObject *object_ptr) {
		objects.push_back(object_ptr);
}

// 添加光线
void World::add_light(Light *light_ptr) {
	lights.push_back(light_ptr);
}

// 光线是否和几何物体碰撞
ShadeRec*
	World::hit_objects(const Ray &ray) {
	ShadeRec *sr = new ShadeRec(this);
	double t;
	Normal normal;
	Point3D local_hit_point;
	float tmin = kHugeValue;
	int num_objects = objects.size();

	for (int j = 0;j < num_objects;j++) {
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr->hit_an_object = true;
			tmin = t;
			sr->material_ptr = objects[j]->get_material();
			sr->hit_point = ray.o + t * ray.d;
			normal = sr->normal;
			local_hit_point = sr->local_hit_point;
		}
	}

	if (sr->hit_an_object) {
		sr->t = tmin;
		sr->normal = normal;
		sr->local_hit_point = local_hit_point;
	}

	return sr;
}

// 着色
void
	World::display_pixel(int r, int c, RGBColor &pixel_color) {
		*(image + (r * 3 * vp->hres + c * 3)) = (int)(pixel_color.r*255);
		*(image + (r * 3 * vp->hres + c * 3 + 1)) = (int)(pixel_color.g*255);
		*(image + (r * 3 * vp->hres + c * 3 + 2)) = (int)(pixel_color.b*255);
}

// 克隆
World*
	World::clone(void) const {
		return new World(*this);
}

void
	World::print(void) const {
		cout << "World" << endl;
		vp->print();
		background_color.print();
		tracer_ptr->print();
		camera_ptr->print();
		int cnt = objects.size();
		for (int i = 0;i < cnt;i++) {
			objects.at(i)->print();
		}
		cnt = lights.size();
		for (int i = 0;i < cnt;i++) {
			lights.at(i)->print();
		}
		ambient_ptr->print();
		cout << "image: " << image << endl;
		model->print();
		cout << "sc: " << sc << endl;
}