#ifndef __PINHOLE__
#define __PINHOLE__

#include "Point2D.h"
#include "World.h"

class Pinhole : public Camera {
public:

	Pinhole();
	Pinhole(const Pinhole &copy);

	virtual
		~Pinhole();

	Pinhole&
		operator= (const Pinhole &rhs);

	// ������ƽ�����
	void
		set_d(float _d);

	// ��������ϵ��
	void
		set_zoom(float _zoom);

	// ������߷���
	Vector3D
		get_direction(const Point2D &p) const;

	// ��¡
	virtual Camera*
		clone(void) const;

	// ��Ⱦ
	virtual void
		render_scene(World *wr);

	void
		print(void) const;

private:

	float d; // ��ƽ�����
	float zoom; // ����ϵ��
};

// ������ƽ�����
void inline
	Pinhole::set_d(float _d) {
		d = _d;
}

// ��������ϵ��
void inline
	Pinhole::set_zoom(float _zoom) {
		zoom = _zoom;
}

#endif