#include "Lives.h"



Lives::Lives(Vec2 LivesDisplay)
	:
	LivesDisplay(LivesDisplay)
{
}

void Lives::DrawIndicator(Graphics & gfx)
{
	int x = LivesDisplay.x;
	const int y = LivesDisplay.y;
	const int spacing = 20;
	for (int i = 0; i < lives; i++) {
		for (int w = 0; w <= 15; w++) {
			for (int h = 0; h <= 15; h++) {
				gfx.PutPixel(x + w, y + h, Colors::Magenta);
			}
		}
		x += spacing;
	}
}

bool Lives::Update(Ball & b)
{
	if (lives > 0) {
		if (b.GetRect().bottom > Graphics::ScreenHeight) {
			lives--;
		}
	}
	else {
		GameOver = true;
	}
	return GameOver;
}


Lives::~Lives()
{
}
