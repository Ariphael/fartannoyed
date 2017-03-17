#pragma once
#include "Ball.h"
#include "Vec2.h"
class Lives
{
public:
	Lives()=default;
	Lives(Vec2 LivesDisplay);
	void DrawIndicator(Graphics& gfx);
	bool Update(Ball& b);
	~Lives();
private:
	int lives=5;
	Vec2 LivesDisplay;
	bool GameOver = false;
};

