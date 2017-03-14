#include "Brick.h"

Brick::Brick(RectF brick_in, Color color)
	:
	_brick(brick_in),
	color(color),
	pos(Vec2(brick_in.left,brick_in.top))
{
}

void Brick::Init(RectF brick_in, Color color)
{
	_brick = brick_in;
	 this->color = color;
}

bool Brick::CollisionHandle(Ball & b)
{
	bool collided = false;
	if (!destroyed && _brick.isColliding(b.GetRect())) {
		b.InvertY();
		destroyed = true;
		collided = true;
	}
	return collided;
}

void Brick::Draw(Graphics& gfx)
{
	if (!destroyed) {
		gfx.DrawRect(_brick,color);
	}
}

void Brick::Expand(float n)
{
	_brick.bottom += n;
	_brick.right += n;
	pos.x -= n;
	pos.y -= n;
}

RectF Brick::GetRect()
{
	return _brick;
}
