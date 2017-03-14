#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Ball.h"

class Brick {
public:
	Brick() = default;
	Brick(RectF brick_in, Color color);
	void Init(RectF brick_in, Color color);
	bool CollisionHandle(Ball& b);
	void Draw(Graphics& gfx);
	void Expand(float n);
	RectF GetRect();
private:
	RectF _brick;
	Color color;
	Vec2 pos;
	bool destroyed = false;
};
