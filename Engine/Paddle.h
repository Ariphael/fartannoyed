#pragma once
#include "Colors.h"
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Mouse.h"

class Paddle
{
public:
	Paddle()=default;
	Paddle(Vec2 pos,Vec2 vel, Color c);
	void Draw(Graphics& gfx);
	void Update(Mouse& mouse);
	bool ReflectionHandle(Ball &c);
	bool Overlapped();
	RectF GetRect();
	~Paddle();
private:
	Color c;
	static constexpr float width = 100.0f;
	static constexpr float height = 20.0f;
	Vec2 pos;
	Vec2 vel;
};

