#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 pos_in, Vec2 vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::DrawBall(Graphics& gfx)
{
	SpriteCodex::DrawBall(pos,gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
	rect.top = pos.y - radius;
	rect.right = pos.x + radius;
	rect.bottom = pos.y + radius;
	rect.left = pos.x - radius;
}

bool Ball::Overlapped()
{
	bool over=false;
	if (rect.left < 0) {
		over = true;
		pos.x += 0 - rect.left;
		InvertX();
	}
	if (rect.top < 0) {
		over = true;
		pos.y += 0 - rect.top;
		InvertY();
	}
	if (rect.right >= Graphics::ScreenWidth) {
		over = true;
		pos.x -= rect.right - Graphics::ScreenWidth;
		InvertX();
	}
	if (rect.bottom >= Graphics::ScreenHeight) {
		over = true;
		pos.y -= rect.bottom - Graphics::ScreenHeight;
		InvertY();
	}
	return over;
}

void Ball::InvertX()
{
	vel.x = -vel.x;
}

void Ball::InvertY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect()
{
	return RectF(pos,radius*2,radius*2);
}

Vec2 Ball::GetVel()
{
	return vel;
}
