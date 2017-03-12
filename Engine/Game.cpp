/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	b(Vec2(100.0f,100.0f),Vec2(300.0f,300.0f)),
	BallReflection(L"Sounds\\arkpad.wav"),
	BallDestroy(L"Sounds\\arkbrick.wav"),
	paddle(Vec2(100,500),Vec2(300.0f,0),Colors::White)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt = ft.Mark();
	b.Update(dt);
	for (Brick& a : brick) {
		if (a.CollisionHandle(b)) {
			BallDestroy.Play();
			break;
		}
	}
	paddle.Update(wnd.kbd, dt);
	paddle.Overlapped();
	if (b.Overlapped() || paddle.ReflectionHandle(b)) {
		BallReflection.Play();
	}
	if (!n) {
		const Vec2 offset(0.0f, 0.0f);
		int i = 0;
		for (float y = 0; y < nBricksDown; y++) {
			const Color c = BrickColors[(int)y];
			for (float x = 0; x < nBricksAcross; x++) {
				brick[i] = Brick(RectF(offset + Vec2(x*nBrickWidth, y*nBrickHeight), nBrickWidth, nBrickHeight), c);
				i++;
			}
		}
		n = true;
	}
}

void Game::ComposeFrame()
{
	b.DrawBall(gfx);
	for (Brick& a : brick) {
		a.Draw(gfx);
	}
	paddle.Draw(gfx);
}
