#include "Paddle.h"
#define VK_LEFT 0x25
#define VK_RIGHT 0x27

Paddle::Paddle(Vec2 pos,Vec2 vel, Color c)
	:
	pos(pos),
	c(c),
	vel(vel)
{

}

void Paddle::Draw(Graphics& gfx)
{
	for (int y = pos.y; y <= pos.y + height; y++) {
		for (int x = pos.x; x <= pos.x + width; x++) {
			gfx.PutPixel(x, y, c);
		}
	}
}

void Paddle::Update(Mouse& mouse)
{
	if (mouse.LeftIsPressed()) {
		pos.x = mouse.GetPosX();
	}
}

bool Paddle::ReflectionHandle(Ball & c)
{
	bool reflect = false;
	if (c.GetVel().y > 0 && GetRect().isColliding(c.GetRect())) {
		c.InvertY();
		reflect = true;
	}
	return reflect;
}

bool Paddle::Overlapped()
{
	bool over = false;
	if (pos.x < 0) {
		over = true;
		pos.x += 0 - pos.x;
	}
	if (pos.x+width >= Graphics::ScreenWidth) {
		over = true;
		pos.x -= (pos.x+width) - Graphics::ScreenWidth+1;
	}
	return over;
}

RectF Paddle::GetRect()
{
	return RectF(pos, width, height);
}


Paddle::~Paddle()
{
}
