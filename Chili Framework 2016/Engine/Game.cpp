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
	gfx( wnd )
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
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x_mobile = x_mobile + 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x_mobile = x_mobile - 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y_mobile = y_mobile - 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y_mobile = y_mobile + 1;
	}

	if (x_mobile + 5 >= gfx.ScreenWidth)
	{
		x_mobile = gfx.ScreenWidth - 6;
	}
	if (x_mobile - 5 < 0)
	{
		x_mobile = 5;
	}
	if (y_mobile + 5 >= gfx.ScreenHeight)
	{
		y_mobile = gfx.ScreenHeight - 6;
	}
	if (y_mobile - 5 < 0)
	{
		y_mobile = 5;
	}

	colliding = OverlapTest(x_fixed, y_fixed, x_mobile, y_mobile);
}

void Game::ComposeFrame()
{
	DrawBox(x_fixed, y_fixed, 0,255,0);

	if (colliding)
	{
		DrawBox(x_mobile, y_mobile, 255, 0, 0);
	}
	else
	{
		DrawBox(x_mobile, y_mobile, 255, 255, 255);
	}

}

void Game::DrawBox(int x, int y, int r, int g, int b)
{
	// rita ut shapeen
	gfx.PutPixel(x - 5, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y - 4, r, g, b);
	gfx.PutPixel(x - 5, y - 3, r, g, b);
	gfx.PutPixel(x - 4, y - 5, r, g, b);
	gfx.PutPixel(x - 3, y - 5, r, g, b);
	gfx.PutPixel(x - 5, y + 5, r, g, b);
	gfx.PutPixel(x - 5, y + 4, r, g, b);
	gfx.PutPixel(x - 5, y + 3, r, g, b);
	gfx.PutPixel(x - 4, y + 5, r, g, b);
	gfx.PutPixel(x - 3, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y - 4, r, g, b);
	gfx.PutPixel(x + 5, y - 3, r, g, b);
	gfx.PutPixel(x + 4, y - 5, r, g, b);
	gfx.PutPixel(x + 3, y - 5, r, g, b);
	gfx.PutPixel(x + 5, y + 5, r, g, b);
	gfx.PutPixel(x + 5, y + 4, r, g, b);
	gfx.PutPixel(x + 5, y + 3, r, g, b);
	gfx.PutPixel(x + 4, y + 5, r, g, b);
	gfx.PutPixel(x + 3, y + 5, r, g, b);

}

bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
	// gränserna för varje box
	const int left_box0 = box0x - 5;
	const int right_box0 = box0x + 5;
	const int top_box0 = box0y - 5;
	const int bottom_box0 = box0y + 5;

	const int left_box1 = box1x - 5;
	const int right_box1 = box1x + 5;
	const int top_box1 = box1y - 5;
	const int bottom_box1 = box1y + 5;

	// koll ifall boxarna överlappar
	return (left_box0 <= right_box1 &&
		right_box0 >= left_box1 &&
		top_box0 <= bottom_box1 &&
		bottom_box0 >= top_box1);
}
