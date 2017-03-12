#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Ball {
public:
	Ball(Vec2 pos_in, Vec2 vel_in);
	void DrawBall(Graphics& gfx);
	void Update(float dt);
	bool Overlapped();
	void InvertX();
	void InvertY();
	RectF GetRect();
	Vec2 GetVel();
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
	RectF rect = RectF::CenInit(pos,radius,radius);
};
