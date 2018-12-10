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
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gb = 0;
	}
	else
	{
		gb = 255;
	}


	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight){		}
		else
		{
			vx = vx + 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}


	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft){		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}


	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp){		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}


	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown){		}
		else
		{
			vy = vy + 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}


	x = x + vx;
	y = y + vy;

	if (x + 5 >= gfx.ScreenWidth)
	{
		x = gfx.ScreenWidth - 6;
		vx = 0;
	}
	if (x - 5 < 0)
	{
		x = 5;
		vx = 0;
	}
	if (y + 5 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
		vy = 0;
	}
	if (y - 5 < 0)
	{
		y = 5;
		vy = 0;
	}

	shapeIsChanged = true;
	if ((x > (200-11) && x < (200+11)) && (y >(300 - 11) && y < (300 + 11)))
	{
		gb = 100; 
	}

	// shapeIsChanged = wnd.kbd.KeyIsPressed( VK_SHIFT );
}

void Game::ComposeFrame()
{
	const int r_fixed = 0;
	const int g_fixed = 255;
	const int b_fixed = 0;
	
	// rita ut fixed shape
	gfx.PutPixel(x_fixed - 5, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed - 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed - 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 4, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 3, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 5, y_fixed + 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 4, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed - 3, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed - 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 4, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 3, y_fixed - 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 4, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 5, y_fixed + 3, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 4, y_fixed + 5, r_fixed, g_fixed, b_fixed);
	gfx.PutPixel(x_fixed + 3, y_fixed + 5, r_fixed, g_fixed, b_fixed);
			

	int r_mobile, g_mobile, b_mobile;

	if (colliding)
	{
		r_mobile = 255;
		g_mobile = 0;
		b_mobile = 0;
	}
	else
	{
		r_mobile = 255;
		g_mobile = 255;
		b_mobile = 255;
	}

	//if (shapeIsChanged)
	//{
	gfx.PutPixel(x_mobile - 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile - 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile - 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 4, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 3, y_mobile - 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 4, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 5, y_mobile + 3, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 4, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	gfx.PutPixel(x_mobile + 3, y_mobile + 5, r_mobile, g_mobile, b_mobile);
	//}
	//else
	//{
	//gfx.PutPixel(x_mobile - 5, y, 255, gb, gb);
	//gfx.PutPixel(x_mobile - 4, y, 255, gb, gb);
	//gfx.PutPixel(x_mobile - 3, y, 255, gb, gb);
	//gfx.PutPixel(x_mobile + 3, y, 255, gb, gb);
	//gfx.PutPixel(x_mobile + 4, y, 255, gb, gb);
	//gfx.PutPixel(x_mobile + 5, y, 255, gb, gb);
	//gfx.PutPixel(x_mobile, y - 5, 255, gb, gb);
	//gfx.PutPixel(x_mobile, y - 4, 255, gb, gb);
	//gfx.PutPixel(x_mobile, y - 3, 255, gb, gb);
	//gfx.PutPixel(x_mobile, y + 3, 255, gb, gb);
	//gfx.PutPixel(x_mobile, y + 4, 255, gb, gb);
	//gfx.PutPixel(x_mobile, y + 5, 255, gb, gb);
	//}
}
