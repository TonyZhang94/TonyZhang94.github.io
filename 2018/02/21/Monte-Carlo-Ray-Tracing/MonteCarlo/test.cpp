#include "test.h"

void print() {
	cout << endl;
}

void test_RGBColor(void) {
	cout << endl << "==========================" << endl << "test RGBColor" << endl;

	RGBColor a = RGBColor();
	RGBColor b = RGBColor(1.5);
	RGBColor c = RGBColor(1.0, 2.0, 3.0);
	RGBColor d;

	d = a + b;
	d.print();

	d += d;
	d.print();

	d = d - c;
	d.print();

	d -= d;
	d.print();

	d = b  *c;
	d.print();

	d *= c;
	d.print();

	d = d / c;
	d.print();

	d /= b;
	d.print();

	d = a + 3;
	d.print();

	d += 1;
	d.print();

	d = d - 2;
	d.print();

	d -= (-1);
	d.print();

	d = d  *2.5;
	d.print();

	d *= 2;
	d.print();

	d = d / 5;
	d.print();

	d /= 2;
	d.print();

	RGBColor e = d;
	e.print();

	e = e.powc(2);
	e.print();

	cout << e.average() << endl;
	e.print();
}

void test_Point2D(void) {
	cout << endl << "==========================" << endl << "test Point2D" << endl;

	Point2D a = Point2D();
	Point2D b = Point2D(2.0);
	Point2D c = Point2D(4.0, 4.0);
	Point2D d = Point2D(c);

	a.print();
	b.print();
	c.print();
	d.print();

	d = a + b;
	d.print();

	d += b;
	d.print();

	d = d - c;
	d.print();

	d -= c;
	d.print();

	d = d  *d;
	d.print();

	d *= b;
	d.print();

	d = d / c;
	d.print();

	d /= c;
	d.print();

	d = d + 1;
	d.print();

	d += 1;
	d.print();

	d = d - 1;
	d.print();

	d -= 1;
	d.print();

	d = d  *3;
	d.print();

	d *= 2;
	d.print();

	d = d / 3;
	d.print();

	d /= 2;
	d.print();

	cout << b.distance2(c) << endl;
	cout << b.distance(c) << endl;
}

void test_Point3Dold(void) {
	/*cout << endl << "==========================" << endl << "test Point3Dold" << endl;

	Point3D a = Point3D();
	Point3D b = Point3D(2.0);
	Point3D c = Point3D(4.0, 4.0, 4.0);
	Point3D d = Point3D(c);

	a.print();
	b.print();
	c.print();
	d.print();

	d = a + b;
	d.print();

	d += b;
	d.print();

	d = d - c;
	d.print();

	d -= c;
	d.print();

	d = d  *d;
	d.print();

	d *= b;
	d.print();

	d = d / c;
	d.print();

	d /= c;
	d.print();

	d = d + 1;
	d.print();

	d += 1;
	d.print();

	d = d - 1;
	d.print();

	d -= 1;
	d.print();

	d = d  *3;
	d.print();

	d *= 2;
	d.print();

	d = d / 3;
	d.print();

	d /= 2;
	d.print();

	cout << b.distance2(c) << endl;
	cout << b.distance(c) << endl;*/
}

void test_Point3D_Vector(void) {
	cout << endl << "==========================" << endl << "test Point3D" << endl;

	Point3D p1 = Point3D();
	Point3D p2 = Point3D(2.0);
	Point3D p3 = Point3D(4.0, 4.0, 4.0);
	Point3D p4 = Point3D(p3);

	p1.print();
	p2.print();
	p3.print();
	p4.print();

	Vector3D v1 = Vector3D();
	Vector3D v2 = Vector3D(2);
	Vector3D v3 = Vector3D(1, 2, 3);
	Vector3D v4 = Vector3D(v2);
	Vector3D v5 = Vector3D(p3);
	Vector3D v6 = Vector3D(Normal());

	v1.print();
	v2.print();
	v3.print();
	v4.print();
	v5.print();
	v6.print();

	print();

	p4 = p2;
	p4.print();

	p4 = -p4;
	p4.print();

	v6 = p3 - p2;
	v6.print();

	p4 = p3 + v3;
	p4.print();
	p4 = p3 - v3;
	p4.print();

	p4 = p4 + 2;
	p4.print();
	p4 = p4 - 3;
	p4.print();
	p4 = p4  *2;
	p4.print();
	p4 = p4 / 2;
	p4.print();

	print();
	p2.print();
	p4.print();
	cout << p4.distance(p2) << endl;
	cout << p4.distance2(p2) << endl;

	print();
	v6 = p3;
	v6.print();
	v6 = Normal();
	v6.print();
	v6 = v3;
	v6.print();
	v6 = -v6;
	v6.print();

	v6 = v6 + 1;
	v6.print();
	v6 = v6 - 2;
	v6.print();
	v6 = v6  *2;
	v6.print();
	v6 = v6 / 2;
	v6.print();

	v6 = v6 + v2;
	v6.print();
	v6 += v2;
	v6.print();
	v6 = v6 - v3;
	v6.print();
	cout << v6  *v2;
	v6 = v6 ^ v2;
	v6.print();

	v6 = 4  *v2;
	v6.print();

	double t[X][Y] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	Matrix c = Matrix(t);
	c.print();
	v6 = c  *v2;
	v6.print();
	(c  *v2).print();
	cout << 1 << endl;
}

void test_Normal(void) {
	cout << endl << "==========================" << endl << "test Normal" << endl;

	Point3D p = Point3D(3, 2, 1);
	Vector3D v = Vector3D(1, 2, 3);

	Normal n1 = Normal();
	Normal n2 = Normal(1);
	Normal n3 = Normal(2, 3, 4);
	Normal n4 = Normal(n3);
	Normal n5 = Normal(p);
	Normal n6 = Normal(v);

	n1.print();
	n2.print();
	n3.print();
	n4.print();
	n5.print();
	n6.print();

	n6 = v;
	n6.print();
	n6 = p;
	n6.print();
	n6 = n2;
	n6.print();
	n6 = -n6;
	n6.print();

	print();
	n6 = n6 + n3;
	n6.print();
	n6 += n3;
	n6.print();
	cout << n2  *v << endl;
	n6 = n2  *4;
	n6.print();

	n6.normalize();
	n6.print();
	n5 = n3.hat();
	n5.print();
}

void test_Matrix(void) {
	cout << endl << "==========================" << endl << "test Matrix" << endl;

	Matrix a = Matrix();
	Matrix b = Matrix(2.0);
	Matrix c = a + b;

	a.print();
	b.print();
	c.print();

	Matrix d = Matrix(1);
	c = c  *d;
	c.print();

	double t[X][Y] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	c = Matrix(t);
	c.print();
	a = c  *d;
	a.print();

	a = d  *c;
	a.print();

	a.set_identity();
	a.print();
}

void test_Maths(void) {
	cout << endl << "==========================" << endl << "test Maths" << endl;

	double c[3] = {1, -3, 2};
	double s[2];
	SolveQuadric(c, s);
	cout << s[0] << endl;
	cout << s[1] << endl;

	double c1[4] = {-14, 1, 1, 1};
	double s1[3];
	SolveCubic(c1, s1);
	cout << s1[0] << endl;
	cout << s1[1] << endl;
	cout << s1[2] << endl;

	double c2[5] = {-10, 1, 1, 1, 1};
	double s2[4];
	SolveQuartic(c2, s2);
	cout << s2[0] << endl;
	cout << s2[1] << endl;
	cout << s2[2] << endl;
	cout << s2[3] << endl;
}

void test_Ray(void) {
	cout << endl << "==========================" << endl << "test Ray" << endl;
	Ray r1 = Ray();
	r1.print();

	Point3D p = Point3D(1, 2, 3);
	Vector3D v = Vector3D(4, 5, 6);

	Ray r2 = Ray(p, v);
	r2.print();
	r2.depth = 10;

	r2.print();
	Ray r3;
	r3 = r2;
	r3.print();
}

void test_ShadeRec(void) {
	cout << endl << "==========================" << endl << "test ShadeRec" << endl;
	World wr;
	ShadeRec r = ShadeRec(&wr);
	r.print();
}

void test_BBox(void) {
	cout << endl << "==========================" << endl << "test BBox" << endl;
	BBox b1 = BBox();
	b1.print();

	BBox b2 = BBox(6, 5, 4, 3, 2, 1);
	b2.print();

	Point3D p1 = Point3D(1, 2, 3);
	Point3D p2 = Point3D(4, 5, 6);

	BBox b3 = BBox(p1, p2);
	b3.print();

	BBox b4 = BBox(b1);
	b4.print();
	BBox b5 = b2;
	b5.print();

	Point3D p3 = Point3D(0);
	cout << b1.inside(p1) << endl;
	cout << b1.inside(p2) << endl;
	cout << b1.inside(p3) << endl;
}

void test_Sampler(void) {
	cout << endl << "==========================" << endl << "test Sampler" << endl;

	//Sampler s = Sampler(1, 2);
}

void test_Regular(void) {
	cout << endl << "==========================" << endl << "test Regular" << endl;

	Regular r1 = Regular();
	// r1.print();

	Regular r2 = Regular(10, 2);
	// r2.print();

	Regular r3 = Regular(r2);
	r3.print();

	Regular r4 = r2;
	r4.print();
}

void test_MultiJittered(void) {
	cout << endl << "==========================" << endl << "test MultiJittered" << endl;

	MultiJittered m1 = MultiJittered();
	// m1.print();

	MultiJittered m2 = MultiJittered(10, 2);
	// m2.print();

	MultiJittered m3 = MultiJittered(m2);
	m3.print();

	MultiJittered m4 = m2;
	m4.print();
}

void test_BRDF(void) {
	cout << endl << "==========================" << endl << "test BRDF" << endl;

	// BRDF o1 = BRDF();
}

void test_Lambertian(void) {
	cout << endl << "==========================" << endl << "test Lambertian" << endl;
	Lambertian l1 = Lambertian();
	l1.print();

	Lambertian l2 = Lambertian(1, 2);
	l2.print();

	Lambertian l3 = Lambertian(1, RGBColor(3));
	l3.print();

	Lambertian l4 = Lambertian(1, 2, 3, 4);
	l4.print();

	Lambertian l5 = Lambertian(l2);
	l5.print();

	Lambertian l6 = l3;
	l6.print();

	l5.set_kd(1.4);
	l5.set_cd(5);
	l5.print();
	l5.set_ka(1.9);
	l5.set_cd(1, 2, 3);
	l5.print();
	l5.set_cd(RGBColor(10));
	l5.print();

	(l6.f(new ShadeRec(new World), Vector3D(2), Vector3D(3))).print();
	//Vector3D wi = Vector3D(4);
	//float pdf;
	//l6.set_sampler(&l2);
	//(l6.sample_f(new ShadeRec(new World), Vector3D(2), wi, pdf)).print();
	//wi.print();

	(l6.rho(new ShadeRec(new World), Vector3D(2))).print();
}

void test_GlossySpecular(void) {
	cout << endl << "==========================" << endl << "test GlossySpecular" << endl;

	GlossySpecular g1 = GlossySpecular();
	g1.print();

	GlossySpecular g2 = g1;
	GlossySpecular g3 = GlossySpecular(g2);

	g2.set_cr(5);
	g2.print();
	g3.set_ks(4);
	g3.set_cs(1, 3, 4);
	g3.set_exp(1.5);
	g3.print();

	(g3.f(new ShadeRec(new World), Vector3D(2), Vector3D(3))).print();

	// Vector3D wi = Vector3D(4);
	// float pdf;
	// l6.set_sampler(&l2);
	// (l6.sample_f(new ShadeRec(new World), Vector3D(2), wi, pdf)).print();
	// wi.print();

	(g3.rho(new ShadeRec(new World), Vector3D(2))).print();
}

void test_Material(void) {
	cout << endl << "==========================" << endl << "test Material" << endl;

	// Material m = Material();
}

void test_Emissive(void) {
	cout << endl << "==========================" << endl << "test Emissive" << endl;

	Emissive e1 = Emissive();
	e1.print();

	Emissive e2 = Emissive(e1);
	e2.print();

	Emissive e3 = e2;
	e2.print();

	e3.set_ls(2);
	e3.set_ce(1, 2, 3);
	e3.print();

	e3.set_ce(10);
	e3.print();

	e3.set_ce(RGBColor(5, 4, 3));
	e3.print();

	ShadeRec *sr = new ShadeRec(new World);
	sr->normal = Normal(1, 2, 3);
	sr->ray.d = Vector3D(-5);
	(e3.get_Le(sr)).print();
	(e3.shade(sr)).print();
	(e3.area_light_shade(sr)).print();
}

void test_Matte(void) {
	cout << endl << "==========================" << endl << "test Matte" << endl;
	
	Matte m1 = Matte();
	m1.print();

	Matte m2 = Matte(m1);
	m2.print();

	Matte m3 = m2;
	m2.print();

	m3.set_ka(2);
	m3.set_kd(3);
	m3.set_cd(1, 2, 3);
	m3.print();

	m3.set_cd(10);
	m3.print();

	m3.set_cd(RGBColor(5, 4, 3));
	m3.print();

	ShadeRec *sr = new ShadeRec(new World);
	sr->normal = Normal(1, 2, 3);
	sr->ray.d = Vector3D(-5);
	(m3.shade(sr)).print();
	(m3.area_light_shade(sr)).print();
}

void test_Phong(void) {
	cout << endl << "==========================" << endl << "test Phong" << endl;

	Phong p1 = Phong();
	// p1.print();

	Phong p2 = Phong(p1);
	// p2.print();

	Phong p3 = p2;
	// p3.print();

	p1.set_ka(2);
	p1.set_kd(3);
	p1.set_cd(1, 2, 3);
	p1.set_samples(3, 2.5);
	p1.set_ks(12);
	p1.print();

	p1.set_cr(10);
	p1.set_cs(20);
	p1.set_exp(1.5);
	p1.print();
}

void test_GlossyReflector(void) {
	cout << endl << "==========================" << endl << "test GlossyReflector" << endl;

	GlossyReflector g1 = GlossyReflector();
	// g1.print();

	GlossyReflector g2 = GlossyReflector(g1);
	g2.set_cr(100);
	// g2.print();

	GlossyReflector g3 = g2;
	g3.set_exp(2.5);
	g3.print();
}

void test_ViewPlane(void) {
	cout << endl << "==========================" << endl << "test ViewPlane" << endl;

	ViewPlane v1 = ViewPlane();
	v1.print();

	print();

	ViewPlane v2 = ViewPlane(v1);
	v2.print();
}

void test_Light(void) {
	cout << endl << "==========================" << endl << "test Light" << endl;

	// Light l1 = Light();
}

void test_Ambient(void) {
	cout << endl << "==========================" << endl << "test Ambient" << endl;

	Ambient a1 = Ambient();
	a1.print();
	
	print();

	a1.set_ce(2);
	Ambient a2 = Ambient(a1);
	a2.print();

	print();

	a2.set_ce(5);
	Ambient a3 = a2;
	a2.print();

	print();

	a2.set_ls(5);
	a2.set_ce(10);
	a2.print();
}

void test_AreaLight(void) {
	cout << endl << "==========================" << endl << "test AreaLight" << endl;

	AreaLight a1 = AreaLight();
	a1.print();

	print();

	AreaLight a2 = AreaLight(a1);
	a2.print();

	print();

	AreaLight a3 = a2;
	a3.print();

	print();

	a3.set_object_ptr(NULL);
	a3.set_material_ptr(new Emissive);
	a3.set_sample_point(Point3D(4));
	a3.set_wi(Vector3D(5));
	a3.set_light_normal(Normal(6));

	a3.print();
}

void test_GeometricObject(void) {
	cout << endl << "==========================" << endl << "test GeometricObject" << endl;

	//GeometricObject g1 = GeometricObject();
}

void test_Triangle(void) {
	cout << endl << "==========================" << endl << "test Triangle" << endl;

	Triangle t1 = Triangle();
	t1.print();

	Triangle t2 = Triangle(t1);
	t2.print();

	Triangle t3 = Triangle(1, 2, 3);
	t3.print();

	ShadeRec *sr = new ShadeRec(new World);
	double a = 1.0;
	cout << t3.hit(Ray(), a, sr) << endl;

}

void test_Sphere(void) {
	cout << endl << "==========================" << endl << "test Sphere" << endl;

	Sphere s1 = Sphere();
	s1.print();

	Sphere s2 = Sphere(1, 2);
	s2.print();

	s2.set_center(Point3D(1, 2, 3));
	Sphere s3 = Sphere(s2);
	s3.print();

	s2.set_radius(10);
	Sphere s4 = s2;
	s4.print();

	double a = 1.0;
	cout << s3.shadow_hit(Ray(), a) << endl;
	cout << s3.hit(Ray(), a, new ShadeRec(new World)) << endl;
}

void test_Rectangle(void) {
	cout << endl << "==========================" << endl << "test Rectangle" << endl;

	Rectangle r1 = Rectangle();
	r1.print();

	Rectangle r2 = Rectangle(1, 2, 3);
	r2.print();


	double a = 1.0;
	cout << r1.shadow_hit(Ray(), a) << endl;
	cout << r1.hit(Ray(), a, new ShadeRec(new World)) << endl;
}

void test_Mesh(void) {
	cout << endl << "==========================" << endl << "test Mesh" << endl;

	Mesh m1 = Mesh();
	m1.print();
}

void test_MeshTriangle(void) {
	cout << endl << "==========================" << endl << "test MeshTriangle" << endl;

	// MeshTriangle m1 = MeshTriangle();
	// m1.print();
}

void test_Model(void) {
	cout << endl << "==========================" << endl << "test Model" << endl;

	// Model m = Model("scene01.obj", "scene01.mtl");
	// Model m = Model("scene02.obj", "scene02.mtl");
	Model m = Model('1');

	m.print();
}

void test_World(void) {
	cout << endl << "==========================" << endl << "test World" << endl;

	World wr = World();
	// wr.print();
}

void test_Tracer(void) {
	cout << endl << "==========================" << endl << "test Tracer" << endl;

	Tracer t = Tracer();
	t.print();
}

void test_AreaLighting(void) {
	cout << endl << "==========================" << endl << "test AreaLighting" << endl;

	AreaLighting a = AreaLighting();
	a.print();
}

void test_RayCast(void) {
	cout << endl << "==========================" << endl << "test RayCast" << endl;

	RayCast r = RayCast();
	r.print();
}

void test_Camera(void) {
	cout << endl << "==========================" << endl << "test Camera" << endl;

	// Camera c = Camera();
}

void test_Pinhole(void) {
	cout << endl << "==========================" << endl << "test Pinhole" << endl;

	 Pinhole p = Pinhole();
	 p.print();
}

void test_Result(void) {
	cout << endl << "==========================" << endl << "test Result" << endl;

	Result r = Result(1, 200);
	//r.set_scene('1');
	r.writeBMP();
}

void test(void) {
	// test_RGBColor();

	// test_Point2D();
	// test_Point3Dold();
	// test_Point3D_Vector();
	// test_Normal();

	// test_Matrix();
	// test_Maths();

	// test_Ray();

	// test_ShadeRec();

	// test_BBox();

	// test_Sampler();
	// test_Regular();
	// test_MultiJittered();

	// test_BRDF();
	// test_Lambertian();
	// test_GlossySpecular();

	// test_Material();
	// test_Emissive();
	// test_Matte();
	// test_Phong();
	// test_GlossyReflector();

	// test_ViewPlane();

	// test_Light();
	// test_Ambient();
	// test_AreaLight();

	// test_GeometricObject();
	// test_Triangle();
	// test_Sphere();
	// test_Rectangle();
	// test_Mesh();
	// test_MeshTriangle();

	// test_Model();
	// test_World();

	// test_Tracer();
	// test_AreaLighting();
	// test_RayCast();

	// test_Camera();
	// test_Pinhole();

	test_Result();
}