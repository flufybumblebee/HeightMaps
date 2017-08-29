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

	// colors

	int num = 5;
	// red0
		 if (wnd.kbd.KeyIsPressed('Q'))
	{
		red0 = red0 + num;
		if (red0 > 255) { red0 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('A'))
	{
		red0 = red0 - num;
		if (red0 < 0) { red0 = 0; }
	}
	// green0
		 if (wnd.kbd.KeyIsPressed('W'))
	{
			green0 = green0 + num;
		if (green0 > 255) { green0 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('S'))
	{
		green0 = green0 - num;
		if (green0 < 0) { green0 = 0; }
	}
	// blue0
		 if (wnd.kbd.KeyIsPressed('E'))
	{
		blue0 = blue0 + num;
		if (blue0 > 255) { blue0 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('D'))
	{
		blue0 = blue0 - num;
		if (blue0 < 0) { blue0 = 0; }
	}
	
	// red1
		 if (wnd.kbd.KeyIsPressed('R'))
	{
			 red1 = red1 + num;
		if (red1 > 255) { red1 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('F'))
	{
		red1 = red1 - num;
		if (red1 < 0) { red1 = 0; }
	}
	// green1
		 if (wnd.kbd.KeyIsPressed('T'))
	{
		green1 = green1 + num;
		if (green1 > 255) { green1 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('G'))
	{
		green1 = green1 - num;
		if (green1 < 0) { green1 = 0; }
	}
	// blue1
		 if (wnd.kbd.KeyIsPressed('Y'))
	{
		blue1 = blue1 + num;
		if (blue1 > 255) { blue1 = 255; }
	}
	else if (wnd.kbd.KeyIsPressed('H'))
	{
		blue1 = blue1 - num;
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
	if (false /*rotatable and scalable equalateral triangle*/ )
	{
		DrawEqualateralTriangle(scale, angle, position, sideSize, Colors::White);
	}
	
	if (false /*rotatable and scalable equalateral triangle made from an interpolated triangle*/)
	{
		DrawEqualateralTriangleInterpolated(scale, angle, position, sideSize);
	}

	if (true /*rotatable and scalable equalateral triangle with interpolated colors*/)
	{
		Vec2 v0 = p0;
		Vec2 v1 = p1;
		Vec2 v2 = p2;

		v0 = v0 * Mat2::Scaling(scale) * Mat2::Rotation(angle);
		v1 = v1 * Mat2::Scaling(scale) * Mat2::Rotation(angle);
		v2 = v2 * Mat2::Scaling(scale) * Mat2::Rotation(angle);

		v0 = v0 + position;
		v1 = v1 + position;
		v2 = v2 + position;
		Color c = Colors::White;
		DrawThreeColorsInterpolated(v0, v1, v2, c, c, c);
	}

	if (false /*square with two interpolated colors*/)
	{
		Vec2 e0 = { 100.0f,100.0f };
		Vec2 e1 = { 540.0f,540.0f };
		
		DrawTwoColorsInterpolated(e0, e1, Color( red0, green0, blue0 ), Color(red1, green1, blue1));
	}

	if (false /*rotatable and scalable square made from two interpolated triangles*/)
	{
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
		
		DrawTriangleInterpolated(o0, o1, o2);
		DrawTriangleInterpolated(o0, o2, o3);
	}
}


void Game::DrawEqualateralTriangle( const float& scale, const float& angle, const Vec2& center, const float& sideSize, const Color& c)
{
	const float side = sideSize;
	const float sideHalf = side / 2.0f;
	const float sideSq = sq(side);
	const float sideHalfSq = sq(sideHalf);
	const float littleY = sideHalf * tan(PI / 6);
	const float bigY = sqrt(sideSq - sideHalfSq) - littleY;

	const Vec2 p0 = { -sideHalf, littleY };
	const Vec2 p1 = { 0.0f, -bigY };
	const Vec2 p2 = { sideHalf, littleY };

	Vec2 v0 = p0; 
	Vec2 v1 = p1;
	Vec2 v2 = p2;
	
	v0 = v0 * Mat2::Scaling(scale) * Mat2::Rotation(angle);
	v1 = v1 * Mat2::Scaling(scale) * Mat2::Rotation(angle);
	v2 = v2 * Mat2::Scaling(scale) * Mat2::Rotation(angle);

	v0 = v0 + center;
	v1 = v1 + center;
	v2 = v2 + center;

	gfx.DrawTriangle(v0, v1, v2, c);
}

void Game::DrawEqualateralTriangleInterpolated(const float& scale, const float& angle, const Vec2& center, const float& sideSize )
{
	const float side = sideSize;
	const float sideHalf = side / 2.0f;
	const float sideSq = sq(side);
	const float sideHalfSq = sq(sideHalf);
	const float littleY = sideHalf * tan(PI / 6);
	const float bigY = sqrt(sideSq - sideHalfSq) - littleY;

	const Vec2 p0 = { -sideHalf, littleY };
	const Vec2 p1 = { 0.0f, -bigY };
	const Vec2 p2 = { sideHalf, littleY };

	Vec2 v0 = p0;
	Vec2 v1 = p1;
	Vec2 v2 = p2;

	v0 = v0 * Mat2::Scaling(scale) * Mat2::Rotation(angle);
	v1 = v1 * Mat2::Scaling(scale) * Mat2::Rotation(angle);
	v2 = v2 * Mat2::Scaling(scale) * Mat2::Rotation(angle);

	v0 = v0 + center;
	v1 = v1 + center;
	v2 = v2 + center;

	DrawTriangleInterpolated(v0, v1, v2);
}

void Game::DrawThreeColorsInterpolated(const Vec2& v0, const Vec2& v1, const Vec2& v2, Color c0, Color c1, Color c2 )
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
			Vec2 lineA = *pv1 - *pv0;
			float lenA = lineA.Len();

			int changeRedA = -(c0.GetR() - c1.GetR());
			int changeGreenA = -(c0.GetG() - c1.GetG());
			int changeBlueA = -(c0.GetB() - c1.GetB());

			float incrementRedA = changeRedA / lenA;
			float incrementGreenA = changeGreenA / lenA;
			float incrementBlueA = changeBlueA / lenA;

			Vec2 lineB = *pv2 - *pv0;
			float lenB = lineB.Len();
			
			

			int changeRedB = -(c0.GetR() - c2.GetR());
			int changeGreenB = -(c0.GetG() - c2.GetG());
			int changeBlueB = -(c0.GetB() - c2.GetB());

			float incrementRedB = changeRedB / lenB;
			float incrementGreenB = changeGreenB / lenB;
			float incrementBlueB = changeBlueB / lenB;

			Color c = Color(incrementRedB * vi.Len(), incrementGreenB * vi.Len(), incrementBlueB * vi.Len());

			DrawFlatBottomTriangleColor(*pv0, *pv1, vi, c0, c1, c);
			// flat top triangle

			DrawFlatTopTriangleColor(*pv1, vi, *pv2, c1, c, c2);			
		}
		else // major left
		{
			
		}
	}

	/*float xLen = pv1->x - pv0->x;
	float yLen = pv1->y - pv0->y;

	int changeRed = -(c0.GetR() - c1.GetR());
	int changeGreen = -(c0.GetG() - c1.GetG());
	int changeBlue = -(c0.GetB() - c1.GetB());

	float incrementRed = changeRed / xLen;
	float incrementGreen = changeGreen / xLen;
	float incrementBlue = changeBlue / xLen;

	for (unsigned int iy = 0; iy < yLen; iy++)
	{
		for (unsigned int ix = 0; ix < xLen; ix++)
		{
			Color c = Color(
				int(c0.GetR()) + int(incrementRed   * ix),
				int(c0.GetG()) + int(incrementGreen * ix),
				int(c0.GetB()) + int(incrementBlue  * ix));

			gfx.PutPixel(int(pv0->x) + ix, int(pv0->y) + iy, c);
		}
	}*/
}

void Game::DrawTwoColorsInterpolated(const Vec2& p0, const Vec2& p1, Color c0, Color c1)
{
	float xLen = p1.x - p0.x;
	float yLen = p1.y - p0.y;

	int changeRed   = -(c0.GetR() - c1.GetR());
	int changeGreen = -(c0.GetG() - c1.GetG());
	int changeBlue  = -(c0.GetB() - c1.GetB());

	float incrementRed   = changeRed   / xLen;
	float incrementGreen = changeGreen / xLen;
	float incrementBlue  = changeBlue  / xLen;

	for (unsigned int iy = 0; iy < yLen; iy++)
	{
		for (unsigned int ix = 0; ix < xLen; ix++)
		{
			Color c = Color(
				int(c0.GetR()) + int(incrementRed   * ix),
				int(c0.GetG()) + int(incrementGreen * ix),
				int(c0.GetB()) + int(incrementBlue  * ix));

			gfx.PutPixel(int(p0.x) + ix, int(p0.y) + iy, c);
		}
	}
}

void Game::DrawTriangleInterpolated(const Vec2& v0, const Vec2& v1, const Vec2& v2)
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

void Game::DrawFlatBottomTriangleColor(const Vec2& v0, const Vec2& v1, const Vec2& v2, Color c0, Color c1, Color c2)
{
	// define the slopes
	const float m0 = (v1.x - v0.x) / (v1.y - v0.y);
	const float m1 = (v2.x - v0.x) / (v2.y - v0.y);

	// set the top rule
	const int yStart = int(ceil(v0.y - 0.5f));
	const int yEnd = int(ceil(v2.y - 0.5f));

	const float lengthA = (v1 - v0).Len();

	const float changeRedA   = -(c0.GetR() - c1.GetR());
	const float changeGreenA = -(c0.GetG() - c1.GetG());
	const float changeBlueA  = -(c0.GetB() - c1.GetB());

	const float incrementRedA   = changeRedA   / lengthA;
	const float incrementGreenA = changeGreenA / lengthA;
	const float incrementBlueA  = changeBlueA  / lengthA;

	const float lengthB = (v2 - v0).Len();

	const float changeRedB   = -(c0.GetR() - c2.GetR());
	const float changeGreenB = -(c0.GetG() - c2.GetG());
	const float changeBlueB  = -(c0.GetB() - c2.GetB());

	const float incrementRedB   = changeRedB   / lengthB;
	const float incrementGreenB = changeGreenB / lengthB;
	const float incrementBlueB  = changeBlueB  / lengthB;

	for (int y = yStart; y < yEnd; y++)
	{
		// set the start and end x pixels ( before setting the left rule )
		const float px0 = m0 * (float(y) + 0.5f - v0.y) + v0.x;
		const float px1 = m1 * (float(y) + 0.5f - v0.y) + v0.x;

		// set left rule
		const int xStart = int(ceil(px0 - 0.5f));
		const int xEnd   = int(ceil(px1 - 0.5f));

		// find color change by finding length of line then magic
		const Color cA = Color(c0.GetR() + (incrementRedA * y), c0.GetG() + (incrementGreenA * y), c0.GetB() + (incrementBlueA * y));
		const Color cB = Color(c1.GetR() + (incrementRedB * y), c1.GetG() + (incrementGreenB * y), c1.GetB() + (incrementBlueB * y));
		
		// total line length to interpolate color across
		float xLength = xEnd - xStart;
		
		int incrementRed = 1;
		int incrementGreen = 1;
		int incrementBlue = 1;

		for (int x = xStart, int i = 0; x < xEnd; x++, i++ )
		{
			Color c = Color(ci0.GetR() + (incrementRed * i), ci0.GetG() + (incrementGreen * i), ci0.GetB() + (incrementBlue * i));
			gfx.PutPixel(x, y, c);
		}
	}
}

void Game::DrawFlatTopTriangleColor(const Vec2& v0, const Vec2& v1, const Vec2& v2, Color c0, Color c1, Color c2)
{
	// define the slopes
	const float m0 = (v2.x - v0.x) / (v2.y - v0.y);
	const float m1 = (v2.x - v1.x) / (v2.y - v1.y);

	// set the top rule
	const int yStart = int(ceil(v0.y - 0.5f));
	const int yEnd = int(ceil(v2.y - 0.5f));

	for (int y = yStart; y < yEnd; y++)
	{
		// set the start and end x pixels ( before setting the left rule )
		const float px0 = m0 * (float(y) + 0.5f - v0.y) + v0.x;
		const float px1 = m1 * (float(y) + 0.5f - v1.y) + v1.x;

		// set left rule
		const int xStart = int(ceil(px0 - 0.5f));
		const int xEnd = int(ceil(px1 - 0.5f));

		for (int x = xStart; x < xEnd; x++)
		{
			gfx.PutPixel(x, y, Colors::Gray);
		}
	}
}
