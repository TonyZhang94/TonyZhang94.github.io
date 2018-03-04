#include "MeshTriangle.h"

MeshTriangle::MeshTriangle(void)
	: GeometricObject(), mesh_ptr(NULL), index0(0), index1(0), index2(0), normal() {

}

MeshTriangle::MeshTriangle(Mesh *_mesh_ptr, int i0, int i1, int i2)
	: GeometricObject(), mesh_ptr(_mesh_ptr), index0(i0), index1(i1), index2(i2) {

}

MeshTriangle::MeshTriangle(const MeshTriangle &copy)
	: GeometricObject(copy), mesh_ptr(copy.mesh_ptr), index0(copy.index0),
	index1(copy.index1), index2(copy.index2), normal(copy.normal) {

}

MeshTriangle::~MeshTriangle(void) {
	GeometricObject::~GeometricObject();

	if (NULL != mesh_ptr) {
		delete mesh_ptr;
		mesh_ptr = NULL;
	}
}

MeshTriangle&
	MeshTriangle::operator= (const MeshTriangle &rhs) {
		if (this == &rhs)
			return (*this);

		GeometricObject::operator= (rhs);

		mesh_ptr = rhs.mesh_ptr;
		index0 = rhs.index0;
		index1 = rhs.index1;
		index2 = rhs.index2;
		normal = rhs.normal;

		return (*this);
}

void
	MeshTriangle::compute_normal(bool reverse_normal) {
		normal = (mesh_ptr->vertices[index1] - mesh_ptr->vertices[index0]) ^
			(mesh_ptr->vertices[index2] - mesh_ptr->vertices[index0]);
		normal.normalize();

		if (reverse_normal)
			normal = -normal;
}

Normal
	MeshTriangle::get_normal(void) const {
		return normal;
}

BBox
	MeshTriangle::get_bounding_box(void) {
		double delta = 0.0001;

		Point3D v1(mesh_ptr->vertices[index0]);
		Point3D v2(mesh_ptr->vertices[index1]);
		Point3D v3(mesh_ptr->vertices[index2]);

		return(BBox(min(min(v1.x, v2.x), v3.x) - delta, max(max(v1.x, v2.x), v3.x) + delta,
			min(min(v1.y, v2.y), v3.y) - delta, max(max(v1.y, v2.y), v3.y) + delta,
			min(min(v1.z, v2.z), v3.z) - delta, max(max(v1.z, v2.z), v3.z) + delta));
}

float
	MeshTriangle::interpolate_u(float beta, float gamma) const {
		return( (1 - beta - gamma) * mesh_ptr->u[index0]
		+ beta * mesh_ptr->u[index1]
		+ gamma * mesh_ptr->u[index2]);
}

float
	MeshTriangle::interpolate_v(float beta, float gamma) const {
		return( (1 - beta - gamma) * mesh_ptr->v[index0]
		+ beta * mesh_ptr->v[index1]
		+ gamma * mesh_ptr->v[index2]);
}

bool
	MeshTriangle::shadow_hit(const Ray &ray, double &tmin) const {
		Point3D v0(mesh_ptr->vertices[index0]);
		Point3D v1(mesh_ptr->vertices[index1]);
		Point3D v2(mesh_ptr->vertices[index2]);

		double a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
		double e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
		double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.z - ray.o.z;

		double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
		double q = g * i - e * k, s = e * j - f * i;

		double inv_denom  = 1.0 / (a * m + b * q + c * s);

		double e1 = d * m - b * n - c * p;
		double beta = e1 * inv_denom;

		if (beta < 0.0)
			return false;

		double r = r = e * l - h * i;
		double e2 = a * n + d * q + c * r;
		double gamma = e2 * inv_denom;

		if (gamma < 0.0 )
			return false;

		if (beta + gamma > 1.0)
			return false;

		double e3 = a * p - b * r + d * s;
		double t = e3 * inv_denom;

		if (t < kEpsilon)
			return false;

		tmin = t;

		return true;
}

void
	MeshTriangle::print(void) const {
		GeometricObject::print();
		if (NULL != mesh_ptr)
			mesh_ptr->print();
		else
			cout << "mesh_ptr is NULL" << endl;

		cout << "index0 = " << index0 << "; index1 = " << index1 << "; index2 = " << index2 << endl;
		cout << "normal: "; normal.print();
		cout << "area = " << area << endl;
}