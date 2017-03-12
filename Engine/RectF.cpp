#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(Vec2 top_left, Vec2 bottom_right)
	:
	RectF(top_left.y,bottom_right.y,top_left.x,bottom_right.x)
{
}

RectF::RectF(Vec2 top_left, float width, float height)
	:
	RectF(top_left, top_left + Vec2(width, height))
{
}

RectF RectF::CenInit(Vec2 centre, float halfwidth, float halfheight)
{
	return RectF(centre - Vec2(halfwidth,halfheight), centre+Vec2(halfwidth,halfheight));
}

bool RectF::isColliding(RectF & a)
{
	return top <= a.top && right >= a.right && left <= a.left && bottom >= a.bottom;
}
