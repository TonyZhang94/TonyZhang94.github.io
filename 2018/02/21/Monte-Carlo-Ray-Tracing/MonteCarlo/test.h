#ifndef __TEST__
#define __TEST__

#include <iostream>
using namespace std;

#include "RGBColor.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "Matrix.h"
#include "Maths.h"
#include "Ray.h"
#include "World.h"
#include "Material.h"
#include "ShadeRec.h"
#include "BBox.h"
#include "Sampler.h"
#include "Regular.h"
#include "MultiJittered.h"
#include "BRDF.h"
#include "Lambertian.h"
#include "GlossySpecular.h"
#include "Emissive.h"
#include "Matte.h"
#include "Phong.h"
#include "GlossyReflector.h"
#include "ViewPlane.h"
#include "Light.h"
#include "Ambient.h"
#include "AreaLight.h"
#include "GeometricObject.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Rectangle.h"
#include "Mesh.h"
#include "MeshTriangle.h"
#include "Model.h"
#include "World.h"
#include "Tracer.h"
#include "AreaLighting.h"
#include "RayCast.h"
#include "Camera.h"
#include "Pinhole.h"
#include "Result.h"


void print();

void test_RGBColor(void);

void test_Point2D(void);

void test_Point3Dold(void);

void test_Point3D_Vector(void);

void test_Normal(void);

void test_Matrix(void);

void test_Maths(void);

void test_Ray(void);

void test_ShadeRec(void);

void test_BBox(void);

void test_Sampler(void);

void test_Regular(void);

void test_MultiJittered(void);

void test_BRDF(void);

void test_Lambertian(void);

void test_GlossySpecular(void);

void test_Material(void);

void test_Emissive(void);

void test_Matte(void);

void test_Phong(void);

void test_GlossyReflector(void);

void test_ViewPlane(void);

void test_Light(void);

void test_Ambient(void);

void test_AreaLight(void);

void test_GeometricObject(void);

void test_Triangle(void);

void test_Sphere(void);

void test_Rectangle(void);

void test_Mesh(void);

void test_MeshTriangle(void);

void test_Model(void);

void test_World(void);

void test_Tracer(void);

void test_AreaLighting(void);

void test_RayCast(void);

void test_Camera(void);

void test_Pinhole(void);

void test_Result(void);

void test(void);

#endif