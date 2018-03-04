#ifndef __RGBCOLOR__
#define __RGBCOLOR__

#include <math.h>

class RGBColor {
public:

	RGBColor(void);
	RGBColor(float c);
	RGBColor(float _r, float _g, float _b);
	RGBColor(const RGBColor &copy);

	~RGBColor(void);

	// RGB信息的四则运算
	RGBColor&
		operator= (const RGBColor &rhs);

	RGBColor
		operator+ (const RGBColor &sc) const;

	RGBColor&
		operator+= (const RGBColor &rhs);

	RGBColor
		operator- (const RGBColor &c) const;

	RGBColor&
		operator-= (const RGBColor &rhs);

	RGBColor
		operator* (const RGBColor &c) const;

	RGBColor&
		operator*= (const RGBColor &rhs);

	RGBColor
		operator/ (const RGBColor &c) const;

	RGBColor&
		operator/= (const RGBColor &rhs);

	RGBColor
		operator+ (const float c) const;

	RGBColor&
		operator+= (const float rhs);

	RGBColor
		operator- (const float c) const;

	RGBColor&
		operator-= (const float rhs);

	RGBColor
		operator* (const float c) const;

	RGBColor&
		operator*= (const float rhs);

	RGBColor
		operator/ (const float c) const;

	RGBColor&
		operator/= (const float rhs);

	bool
		operator== (const RGBColor& rhs) const;

	RGBColor
		powc(float p) const;

	float
		average(void) const;

	void 
		print(void) const;

public:

	// RGB信息
	float r;
	float g;
	float b;
};

inline RGBColor&
	RGBColor::operator= (const RGBColor &rhs) {
		if (this == &rhs) return (*this);
		r = rhs.r; g = rhs.g; b = rhs.b;
		return (*this);
}

inline RGBColor 
	RGBColor::operator+ (const RGBColor &c) const {
		return RGBColor(r+c.r, g+c.g, b+c.b);
}

inline RGBColor& 
	RGBColor::operator+= (const RGBColor &rhs) {
		r += rhs.r; g += rhs.g; b += rhs.b;
		return (*this);
}

inline RGBColor 
	RGBColor::operator- (const RGBColor &c) const {
		return RGBColor(r-c.r, g-c.g, b-c.b);
}

inline RGBColor& 
	RGBColor::operator-= (const RGBColor &rhs) {
		r -= rhs.r; g -= rhs.g; b -= rhs.b;
		return (*this);
}

inline RGBColor 
	RGBColor::operator* (const RGBColor &c) const {
		return RGBColor(r*c.r, g*c.g, b*c.b);
}

inline RGBColor& 
	RGBColor::operator*= (const RGBColor &rhs) {
		r *= rhs.r; g *= rhs.g; b *= rhs.b;
		return (*this);
}

inline RGBColor 
	RGBColor::operator/ (const RGBColor &c) const {
		return RGBColor(r/c.r, g/c.g, b/c.b);
}

inline RGBColor& 
	RGBColor::operator/= (const RGBColor &rhs) {
		r /= rhs.r; g /= rhs.g; b /= rhs.b;
		return (*this);
}

inline RGBColor 
	RGBColor::operator+ (const float c) const {
		return RGBColor(r+c, g+c, b+c);
}

inline RGBColor& 
	RGBColor::operator+= (const float rhs) {
		r += rhs; g += rhs; b += rhs;
		return (*this);
}

inline RGBColor 
	RGBColor::operator- (const float c) const {
		return RGBColor(r-c, g-c, b-c);
}

inline RGBColor& 
	RGBColor::operator-= (const float rhs) {
		r -= rhs; g -= rhs; b -= rhs;
		return (*this);
}

inline RGBColor 
	RGBColor::operator* (const float c) const {
		return RGBColor(r*c, g*c, b*c);
}

inline RGBColor& 
	RGBColor::operator*= (const float rhs) {
		r *= rhs; g *= rhs; b *= rhs;
		return (*this);
}

inline RGBColor 
	RGBColor::operator/ (const float c) const {
		return RGBColor(r/c, g/c, b/c);
}

inline RGBColor& 
	RGBColor::operator/= (const float rhs) {
		r /= rhs; g /= rhs; b /= rhs;
		return (*this);
}

inline bool
	RGBColor::operator== (const RGBColor &rhs) const {
		return (r==rhs.r && g==rhs.g && b==rhs.b);
}

inline RGBColor
	RGBColor::powc(float p) const {
		return (RGBColor(pow(r, p), pow(g, p), pow(b, p)));
}

inline float											
	RGBColor::average(void) const {
		return float(0.333*(r+g+b));
}

//RGBColor
//	operator* (const float c, const RGBColor &c);
//
//inline RGBColor
//	operator* (const float c, const RGBColor &c) {
//		return (RGBColor(c*c.r, c*c.g, c*c.b));
//}

#endif