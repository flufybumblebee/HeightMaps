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
	if( wnd.kbd.KeyIsPressed( VK_LEFT ) )
	{
		angle = angle - 0.02f;
	}
	else if( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
	{
		angle = angle + 0.02f;
	}

	// scaling 
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		scale = scale - 0.01f;
		if (scale < 0) { scale = 0; }
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		scale = scale + 0.01f;
	}

		 if (wnd.kbd.KeyIsPressed('Q'))
	{
		red0++;
		if (red0 > 255) { red0 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('A'))
	{
		red0--;
		if (red0 < 0) { red0 = 0; }
	}
		 if (wnd.kbd.KeyIsPressed('W'))
	{
		green0++;
		if (green0 > 255) { green0 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		green0--;
		if (green0 < 0) { green0 = 0; }
	}
		 if (wnd.kbd.KeyIsPressed('E'))
	{
		blue0++;
		if (blue0 > 255) { blue0 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('D'))
	{
		blue0--;
		if (blue0 < 0) { blue0 = 0; }
	}
	
		 if (wnd.kbd.KeyIsPressed('R'))
	{
		red1++;
		if (red1 > 255) { red1 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('F'))
	{
		red1--;
		if (red1 < 0) { red1 = 0; }
	}
		 if (wnd.kbd.KeyIsPressed('T'))
	{
		green1++;
		if (green1 > 255) { green1 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('G'))
	{
		green1--;
		if (green1 < 0) { green1 = 0; }
	}
		 if (wnd.kbd.KeyIsPressed('Y'))
	{
		blue1++;
		if (blue1 > 255) { blue1 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('H'))
	{
		blue1--;
		if (blue1 < 0) { blue1 = 0; }
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
	/*Vec2 v0 = p0;
	Vec2 v1 = p1;
	Vec2 v2 = p2;

	v0 = v0 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	v1 = v1 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	v2 = v2 * Mat2::Rotation(angle) * Mat2::Scaling(scale);

	v0 = v0 + position;
	v1 = v1 + position;
	v2 = v2 + position;*/

	//gfx.DrawTriangle(v0, v1, v2, Colors::White);

	Vec2 o0 = n0;
	Vec2 o1 = n1;
	Vec2 o2 = n2;
	Vec2 o3 = n3;

	o0 = o0 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	o1 = o1 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	o2 = o2 * Mat2::Rotation(angle) * Mat2::Scaling(scale);
	o3 = o3 * Mat2::Rotation(angle) * Mat2::Scaling(scale);

	o0 = o0 + position;
	o1 = o1 + position;
	o2 = o2 + position;
	o3 = o3 + position;

	DrawTriangleInterpolated(o0, o1, o2, Colors::Red, Colors::Green, Colors::Blue);
	DrawTriangleInterpolated(o0, o2, o3, Colors::Red, Colors::Green, Colors::Blue);

	/*gfx.DrawLine(o0, o1, Colors::White);
	gfx.DrawLine(o1, o2, Colors::White);
	gfx.DrawLine(o2, o3, Colors::White);
	gfx.DrawLine(o3, o0, Colors::White);

	gfx.DrawLine(o0, o2, Colors::White);*/

	
	// draw a horizontal line from one of two corners of the square
	// till it intersects with the diagonal line that bisects the
	// square into two trianlges.

	// find the slope of the line.
	/*int x = 0;
	int y = 0;

	Vec2 e0 = { 100.0f,100.0f };
	Vec2 e1 = { 140.0f,100.0f };

	Color c0 = Color( red0,green0,blue0 );
	Color c1 = Color( red1,green1,blue1 );

	Vec2 e = e1 - e0;

	float xLen = e1.x - e0.x;
	float yLen = e1.y - e0.y;
	float xyLen = sqrt(sq(xLen) + sq(yLen));
	float eLen = xyLen;
	//float eLen = e.Len();


	int changeRed   = -(c0.GetR() - c1.GetR());
	int changeGreen = -(c0.GetG() - c1.GetG());
	int changeBlue  = -(c0.GetB() - c1.GetB());
	
	float incrementRed   = changeRed   / eLen;
	float incrementGreen = changeGreen / eLen;
	float incrementBlue  = changeBlue  / eLen;	

	for (unsigned int iy = 0; iy < eLen; iy++)
	{
		for (unsigned int ix = 0; ix < eLen; ix++)
		{
			Color c = 
				Color(
					int(c0.GetR()) + int(incrementRed   * ix),
					int(c0.GetG()) + int(incrementGreen * ix),
					int(c0.GetB()) + int(incrementBlue  * ix));
			gfx.PutPixel(int(e0.x) + ix, int(e0.y) + iy, c);
		}
	}*/
}

void Game::DrawTriangleInterpolated(Vec2 v0, Vec2 v1, Vec2 v2, Color c0, Color c1, Color c2)
{
	const Vec2* pv0 = &v0;
	const Vec2* pv1 = &v1;
	const Vec2* pv2 = &v2;

	// sorting vertices by y
	if (pv1->y < pv0->y) std::swap(pv1, pv0);
	if (pv2->y < pv1->y) std::swap(pv2, pv1);
	if (pv1->y < pv0->y) std::swap(pv1, pv0);

	if (*pv0 == *pv1) // flat top triangle
	{
		// sort x's left to right
		if (pv1->x < pv0->x) std::swap(pv1, pv0);

		gfx.DrawTriangle(*pv0, *pv1, *pv2, Colors::Red);
	}
	else if (*pv1 == *pv2) // flat bottom triangle
	{
		// sort x's left to right
		if (pv2->x < pv1->x) std::swap(pv2, pv1);

		gfx.DrawTriangle(*pv0, *pv1, *pv2, Colors::Green);
	}
	else // general triangle
	{
		// find the splitting vertex
		const float split = (pv1->y - pv0->y) / (pv2->y - pv0->y);
		const Vec2 vi = *pv0 + ((*pv2 - *pv0) * split);

		if (pv1->x < vi.x) // major right
		{
			// flat bottom triangle
			gfx.DrawTriangle(*pv0, vi, *pv1, Colors::White);
			// flat top triangle
			gfx.DrawTriangle(*pv1, vi, *pv2, Colors::Gray);			
		}
		else // major left
		{
			// flat bottom triangle
			gfx.DrawTriangle(*pv0, vi, *pv1, Colors::Cyan);
			// flat top triangle
			gfx.DrawTriangle(*pv1, vi, *pv2, Colors::Purple);
		}		
	}
}
