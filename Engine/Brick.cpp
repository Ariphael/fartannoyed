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
		if (_brick.top < b.GetRect().top && _brick.bottom > b.GetRect().bottom) {
			b.InvertX();
		}
		else if (b.GetRect().top <= _brick.bottom && b.GetRect().left <= _brick.right && b.GetCen().x >= _brick.right) {
			if (b.GetVel().x < 0) {
				b.InvertX();
			}
			if (b.GetVel().y < 0) {
				b.InvertY();
			}
		}
		else if (b.GetRect().left <= _brick.right && b.GetRect().bottom >= _brick.top && b.GetCen().x>=_brick.right) {
			if (b.GetVel().x < 0) {
				b.InvertX();
			}
			if (b.GetVel().y > 0) {
				b.InvertY();
			}
		}
		else if (b.GetRect().right <= _brick.left && b.GetRect().bottom >= _brick.top && b.GetCen().x <= _brick.left) {
			if (b.GetVel().x > 0) {
				b.InvertX();
			}
			if (b.GetVel().y > 0) {
				b.InvertY();
			}
		}
		else if (b.GetRect().top <= _brick.bottom && b.GetRect().right >= _brick.left && b.GetCen().x <= _brick.left) {
			if (b.GetVel().x > 0) {
				b.InvertX();
			}
			if (b.GetVel().y < 0) {
				b.InvertY();
			}
		}
		else {
			b.InvertY();
		}
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
