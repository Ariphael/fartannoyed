#pragma once
#include "vec2.h"
class RectF {
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(Vec2 top_left, Vec2 bottom_right);
	RectF(Vec2 top_left, float width, float height);
	static RectF CenInit(Vec2 centre, float halfwidth, float halfheight);
	bool isColliding(RectF& a);
public:
	float top;
	float bottom;
	float left;
	float right;
};