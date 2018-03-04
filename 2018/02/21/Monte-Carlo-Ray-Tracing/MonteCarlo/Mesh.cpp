#include "Mesh.h"

Mesh::Mesh(void)
	: num_vertices(0), num_triangles(0)	{

}

Mesh::Mesh(const Mesh &copy)
	: vertices(copy.vertices), normals(copy.normals), u(copy.u), v(copy.v),
	num_vertices(copy.num_vertices), num_triangles(copy.num_triangles) {

}

Mesh::~Mesh(void) {

}

Mesh&
	Mesh::operator= (const Mesh &rhs) {
		if (this == &rhs)
			return (*this);

		vertices = rhs.vertices;
		normals = rhs.normals;
		u = rhs.u;
		v = rhs.v;
		num_vertices = rhs.num_vertices;
		num_triangles = rhs.num_triangles;

		return (*this);
}

void
	Mesh::print(void) const {
		cout << "Mesh:" << endl;
		cout << "vertices:" << endl;
		int cnt = vertices.size();
		for (int i = 0; i < cnt;i++)
			vertices.at(i).print();

		cout << "normals:" << endl;
		cnt = normals.size();
		for (int i = 0; i < cnt;i++)
			normals.at(i).print();

		cout << "u:" << endl;
		cnt = u.size();
		for (int i = 0; i < cnt;i++)
			cout << u.at(i) << endl;

		cout << "v:" << endl;
		cnt = v.size();
		for (int i = 0; i < cnt;i++)
			cout << v.at(i) << endl;

		cout << "vertex_faces:" << endl;
		cnt = vertex_faces.size();
		for (int i = 0; i < cnt;i++) {
			int num = vertex_faces[i].size();
			for (int j = 0; j < num;j++)
				cout << vertex_faces[i][j] << "  ";
			cout << endl;
		}

		cout << "num_vertices = " << num_vertices << endl;
		cout << "num_triangles = " << num_triangles << endl;
}