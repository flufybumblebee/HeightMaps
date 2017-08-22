/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
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

#include "Mat2.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	// ---------------------------------------
	// rotation
	//
	//// rotate around X
	//if( wnd.kbd.KeyIsPressed( 'E' ) )
	//{
	//	angle.x = angle.x - 0.02f;
	//}
	//else if( wnd.kbd.KeyIsPressed( 'D' ) )
	//{
	//	angle.x = angle.x + 0.02f;
	//}
	//
	//// rotate around Y
	//if( wnd.kbd.KeyIsPressed( 'W' ) )
	//{
	//	angle.y = angle.y - 0.02f;
	//}
	//else if( wnd.kbd.KeyIsPressed( 'S' ) )
	//{
	//	angle.y = angle.y + 0.02f;
	//}

	// rotate around Z
	if( wnd.kbd.KeyIsPressed( 'Q' ) )
	{
		angle = angle - 0.02f;
	}
	else if( wnd.kbd.KeyIsPressed( 'A' ) )
	{
		angle = angle + 0.02f;
	}

	// scaling 
	if (wnd.kbd.KeyIsPressed('T'))
	{
		scale = scale - 0.01f;
		if (scale < 0) { scale = 0; }
	}
	else if (wnd.kbd.KeyIsPressed('G'))
	{
		scale = scale + 0.01f;
	}
	//-----------------------------------------
	// scaling 
	//if (wnd.kbd.KeyIsPressed('T'))
	//{
	//	scale.z = scale.z - 0.01f;
	//	if (scale.z < 0) { scale.z = 0; }
	//}
	//else if (wnd.kbd.KeyIsPressed('G'))
	//{
	//	scale.z = scale.z + 0.01f;
	//}
	//
	//if (wnd.kbd.KeyIsPressed('Y'))
	//{
	//	scale.y = scale.y - 0.01f;
	//	if (scale.y < 0) { scale.y = 0; }
	//}
	//else if (wnd.kbd.KeyIsPressed('H'))
	//{
	//	scale.y = scale.y + 0.01f;
	//}
	//if (wnd.kbd.KeyIsPressed('U'))
	//{
	//	scale.x = scale.x - 0.01f;
	//	if (scale.x < 0) { scale.x = 0; }
	//}
	//else if (wnd.kbd.KeyIsPressed('J'))
	//{
	//	scale.x = scale.x + 0.01f;
	//}
	////-----------------------------------------
	//// translation
	//
	//// translate along X axis
	//if (wnd.kbd.KeyIsPressed(VK_LEFT))
	//{
	//	position.x = position.x -= 0.02f;
	//}
	//else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	//{
	//	position.x = position.x += 0.02f;
	//}
	//
	//// translate along Y axis
	//if (wnd.kbd.KeyIsPressed(VK_UP))
	//{
	//	position.y = position.y += 0.02f;
	//}
	//else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	//{
	//	position.y = position.y -= 0.02f;
	//}
	//
	//// translate along Z axis
	//if( wnd.kbd.KeyIsPressed( 'R' ) )
	//{
	//	position.z = position.z += 0.02f;
	//}
	//else if( wnd.kbd.KeyIsPressed( 'F' ) )
	//{
	//	position.z = position.z -= 0.02f;
	//}
}

void Game::ComposeFrame()
{
	Vec2 v0 = p0;
	Vec2 v1 = p1;
	Vec2 v2 = p2;

	v0 = v0 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	v1 = v1 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	v2 = v2 * Mat2::Rotation(angle) * Mat2::Scaling(scale);

	v0 = v0 + position;
	v1 = v1 + position;
	v2 = v2 + position;

	//gfx.DrawTriangle(v0, v1, v2, Colors::White);

	int x = 0;
	int y = 0;

	Vec2 e0 = { 100.0f,100.0f };
	Vec2 e1 = { 200.0f,100.0f };

	Vec2 e = e1 - e0;
	float eLen = e.Len();

	Color c0 = { 155,155,0 };
	Color c1 = { 255,0,0 };

	int changeRed   = -(c0.GetR() - c1.GetR());
	int changeGreen = -(c0.GetG() - c1.GetG());
	int changeBlue  = -(c0.GetB() - c1.GetB());
	
	float incrementRed   = changeRed   / eLen;
	float incrementGreen = changeGreen / eLen;
	float incrementBlue  = changeBlue  / eLen;
	

	for (unsigned int iy = 0; iy < 100; iy++)
	{
		for (unsigned int ix = 0; ix < 100; ix++)
		{
			Color c = 
				Color(
					int(c0.GetR()) + int(incrementRed   * ix),
					int(c0.GetG()) + int(incrementGreen * ix),
					int(c0.GetB()) + int(incrementBlue  * ix));
			gfx.PutPixel(200 + ix, 200 + iy, c);
		}
	}
}
