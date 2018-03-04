#include "Light.h"

Light::Light(void) {

}

Light::Light(const Light &copy) {

}

Light::~Light(void) {

}

Light&
	Light::operator= (const Light &rhs) {
		return (*this);
}

float Light::
	G(ShadeRec *sr) const {
		return 0;
}

// 调用物体的pdf方法
float Light::
	pdf(ShadeRec *sr) const {
		return 0;
}

// 计算入射辐射度
RGBColor
	Light::L(ShadeRec *sr) {
		return (black);
}

// 检测阴影光线是否与碰撞点和采样点之间的对象发生碰撞
bool
	Light::in_shadow(const Ray &ray, const ShadeRec *sr) {
		return false;
}

void
	Light::print(void) const {
		cout << "Light" << endl;
}