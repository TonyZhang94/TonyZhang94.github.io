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

// ���������pdf����
float Light::
	pdf(ShadeRec *sr) const {
		return 0;
}

// ������������
RGBColor
	Light::L(ShadeRec *sr) {
		return (black);
}

// �����Ӱ�����Ƿ�����ײ��Ͳ�����֮��Ķ�������ײ
bool
	Light::in_shadow(const Ray &ray, const ShadeRec *sr) {
		return false;
}

void
	Light::print(void) const {
		cout << "Light" << endl;
}