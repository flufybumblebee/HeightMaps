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
		angle = angle - 0.01f;
	}
	else if( wnd.kbd.KeyIsPressed( VK_RIGHT ) )
	{
		angle = angle + 0.01f;
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
	if (false /*rotatable and scalable equalateral triangle*/)
	{
		DrawEqualateralTriangle(scale, angle, position, sideSize, Colors::White);
	}

	if (false /*rotatable and scalable equalateral triangle made from an interpolated triangle*/)
	{
		DrawEqualateralTriangleInterpolated(scale, angle, position, sideSize);
	}

	if (false /*rotatable and scalable equalateral triangle with interpolated colors*/)
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
		//DrawThreeColorsInterpolated(v0, v1, v2, c, c, c);
	}

	if (false /*square with two interpolated colors*/)
	{
		Vec2 e0 = { 100.0f,100.0f };
		Vec2 e1 = { 540.0f,540.0f };

		DrawTwoColorsInterpolated(e0, e1, Color(red0, green0, blue0), Color(red1, green1, blue1));
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

	if (true)
	{
		/*const Vec2 V0 = { 0.0f, -200.0f };
		const Vec2 V1 = { -200.0f, 200.0f };
		const Vec2 V2 = { 200.0f,  200.0f };*/

		Vec2Color A, B, C;

		A.v = p0;
		A.c = color0;

		B.v = p1;
		B.c = color1;

		C.v = p2;
		C.c = color2;

		A.v = A.v * Mat2::Scaling(scale) * Mat2::Rotation(angle);
		B.v = B.v * Mat2::Scaling(scale) * Mat2::Rotation(angle);
		C.v = C.v * Mat2::Scaling(scale) * Mat2::Rotation(angle);

		A.v = A.v + position;
		B.v = B.v + position;
		C.v = C.v + position;

		DrawTriangleThreeColor(A, B, C);

		//Color c = Colors::Green;
		//gfx.DrawLine(A.x, A.y, B.x, B.y, c);
		//gfx.DrawLine(A.x, A.y, C.x, C.y, c);
		//gfx.DrawLine(B.x, B.y, C.x, C.y, c);
	}
}

void Game::DrawFlatBottomTriangleThreeColor(const Vec2Color& A, const Vec2Color& B, const Vec2Color& C)
{	
	// color stuff --------------------------------------
	
	// AB
	const float   redChangeAB = -(float(A.c.GetR() - B.c.GetR()));
	const float greenChangeAB = -(float(A.c.GetG() - B.c.GetG()));
	const float  blueChangeAB = -(float(A.c.GetB() - B.c.GetB()));

	const float sizeAB = (B.v - A.v).Len();

	const float   redIncrementAB =   redChangeAB / sizeAB;
	const float greenIncrementAB = greenChangeAB / sizeAB;
	const float  blueIncrementAB =  blueChangeAB / sizeAB;

	// AC
	const float redChangeAC   = -(float(A.c.GetR() - C.c.GetR()));
	const float greenChangeAC = -(float(A.c.GetG() - C.c.GetG()));
	const float blueChangeAC  = -(float(A.c.GetB() - C.c.GetB()));
	
	const float sizeAC = (C.v - A.v).Len();

	const float redIncrementAC   = redChangeAC   / sizeAC;
	const float greenIncrementAC = greenChangeAC / sizeAC;
	const float blueIncrementAC  = blueChangeAC  / sizeAC;

	//-----------------------------------------------------

	const float slopeAB = (B.v.x - A.v.x) / (B.v.y - A.v.y);
	const float slopeAC = (C.v.x - A.v.x) / (C.v.y - A.v.y);

	// set the top rule
	const int yStart = int(ceil(A.v.y - 0.5f));
	const int yEnd   = int(ceil(C.v.y - 0.5f));

	for (int y = yStart; y < yEnd; y++)
	{
		// set the start and end x pixels ( before setting the left rule )
		const float px0 = slopeAB * (float(y) + 0.5f - A.v.y) + A.v.x;
		const float px1 = slopeAC * (float(y) + 0.5f - A.v.y) + A.v.x;

		// set left rule
		const int xStart = int(ceil(px0 - 0.5f));
		const int xEnd   = int(ceil(px1 - 0.5f));

		// color stuff ------------------------------------------------

		const float lengthBC = float(xEnd - xStart);
		const float lengthAB = sqrt(sq(A.v.x - xStart) + sq(y - A.v.y));
		const float lengthAC = sqrt(sq(A.v.x - xEnd)   + sq(y - A.v.y));

		const float   redStart = A.c.GetR() + (lengthAB *   redIncrementAB);
		const float greenStart = A.c.GetG() + (lengthAB * greenIncrementAB);
		const float  blueStart = A.c.GetB() + (lengthAB *  blueIncrementAB);

		const float   redEnd = A.c.GetR() + (lengthAC *   redIncrementAC);
		const float greenEnd = A.c.GetG() + (lengthAC * greenIncrementAC);
		const float  blueEnd = A.c.GetB() + (lengthAC *  blueIncrementAC);

		const float   redChange = -(  redStart -   redEnd);
		const float greenChange = -(greenStart - greenEnd);
		const float  blueChange = -( blueStart -  blueEnd);

		const float   redIncrement = redChange   / lengthBC;
		const float greenIncrement = greenChange / lengthBC;
		const float  blueIncrement = blueChange  / lengthBC;

		// -----------------------------------------------

		for (int x = xStart; x < xEnd; x++)
		{
			const int lengthX = x - xStart;

			const unsigned char red   = unsigned char(redStart   + (lengthX * redIncrement));
			const unsigned char green = unsigned char(greenStart + (lengthX * greenIncrement));
			const unsigned char blue  = unsigned char(blueStart  + (lengthX * blueIncrement));

			const Color c = Color( red, green, blue );

			gfx.PutPixel(x, y, c);
		}
	}
}

void Game::DrawFlatTopTriangleThreeColor(const Vec2Color& A, const Vec2Color& B, const Vec2Color& C)
{
	// color stuff --------------------------------------
	
	// AC
	const float   redChangeAC = -(float(A.c.GetR() - C.c.GetR()));
	const float greenChangeAC = -(float(A.c.GetG() - C.c.GetG()));
	const float  blueChangeAC = -(float(A.c.GetB() - C.c.GetB()));

	const float sizeAC = (C.v - A.v).Len();

	const float   redIncrementAC =   redChangeAC / sizeAC;
	const float greenIncrementAC = greenChangeAC / sizeAC;
	const float  blueIncrementAC =  blueChangeAC / sizeAC;

	// BC
	const float   redChangeBC = -(float(B.c.GetR() - C.c.GetR()));
	const float greenChangeBC = -(float(B.c.GetG() - C.c.GetG()));
	const float  blueChangeBC = -(float(B.c.GetB() - C.c.GetB()));

	const float sizeBC = (C.v - B.v).Len();

	const float   redIncrementBC =   redChangeBC / sizeBC;
	const float greenIncrementBC = greenChangeBC / sizeBC;
	const float  blueIncrementBC =  blueChangeBC / sizeBC;

	//-----------------------------------------------------

	const float slopeAC = (C.v.x - A.v.x) / (C.v.y - A.v.y);
	const float slopeBC = (C.v.x - B.v.x) / (C.v.y - B.v.y);

	// set the top rule
	const int yStart = int(ceil(A.v.y - 0.5f));
	const int yEnd = int(ceil(C.v.y - 0.5f));

	for (int y = yStart; y < yEnd; y++)
	{
		// set the start and end x pixels ( before setting the left rule )
		const float px0 = slopeAC * (float(y) + 0.5f - A.v.y) + A.v.x;
		const float px1 = slopeBC * (float(y) + 0.5f - B.v.y) + B.v.x;

		// set left rule
		const int xStart = int(ceil(px0 - 0.5f));
		const int xEnd = int(ceil(px1 - 0.5f));

		// color stuff ------------------------------------------------

		const float lengthAB = float(xEnd - xStart);
		const float lengthAC = sqrt(sq(A.v.x - xStart) + sq(y - A.v.y));
		const float lengthBC = sqrt(sq(B.v.x - xEnd) + sq(y - B.v.y));

		const float   redStart = A.c.GetR() + (lengthAC *   redIncrementAC);
		const float greenStart = A.c.GetG() + (lengthAC * greenIncrementAC);
		const float  blueStart = A.c.GetB() + (lengthAC *  blueIncrementAC);

		const float   redEnd = B.c.GetR() + (lengthBC *   redIncrementBC);
		const float greenEnd = B.c.GetG() + (lengthBC * greenIncrementBC);
		const float  blueEnd = B.c.GetB() + (lengthBC *  blueIncrementBC);

		const float   redChange = -(redStart - redEnd);
		const float greenChange = -(greenStart - greenEnd);
		const float  blueChange = -(blueStart - blueEnd);

		const float   redIncrement =   redChange / lengthAB;
		const float greenIncrement = greenChange / lengthAB;
		const float  blueIncrement =  blueChange / lengthAB;

		// -----------------------------------------------

		for (int x = xStart; x < xEnd; x++)
		{
			const int lengthX = x - xStart;
			const unsigned char   red = unsigned char(  redStart + (lengthX *   redIncrement));
			const unsigned char green = unsigned char(greenStart + (lengthX * greenIncrement));
			const unsigned char  blue = unsigned char( blueStart + (lengthX *  blueIncrement));

			const Color c = Color(red, green, blue);

			gfx.PutPixel(x, y, c);
		}
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

void Game::DrawTriangleThreeColor(const Vec2Color& v0, const Vec2Color& v1, const Vec2Color& v2)
{
	const Vec2Color* pv0 = &v0;
	const Vec2Color* pv1 = &v1;
	const Vec2Color* pv2 = &v2;

	// sorting vertices by y
	if (pv1->v.y < pv0->v.y) { std::swap(pv1, pv0); }
	if (pv2->v.y < pv1->v.y) { std::swap(pv2, pv1); }
	if (pv1->v.y < pv0->v.y) { std::swap(pv1, pv0); }

	if (pv0->v == pv1->v) // flat top triangle
	{
		// sort x's left to right
		if (pv1->v.x < pv0->v.x) { std::swap(pv1, pv0); }

		DrawFlatTopTriangleThreeColor(*pv0, *pv1, *pv2);
	}
	else if (pv1->v == pv2->v) // flat bottom triangle
	{
		// sort x's left to right
		if (pv2->v.x < pv1->v.x) { std::swap(pv2, pv1); }

		DrawFlatBottomTriangleThreeColor(*pv0, *pv1, *pv2 );
	}
	else // general triangle
	{
		// find the splitting vertex
		const float split = (pv1->v.y - pv0->v.y) / (pv2->v.y - pv0->v.y);
		const Vec2 vi = pv0->v + ((pv2->v - pv0->v) * split);

		if (pv1->v.x < vi.x) // major right
		{
			// Left Side Line = A
			/*float lenA = (*pv1 - *pv0).Len();

			float   redChangeA = -(float(c0.GetR() - c1.GetR()));
			float greenChangeA = -(float(c0.GetG() - c1.GetG()));
			float  blueChangeA = -(float(c0.GetB() - c1.GetB()));

			float   redIncrementA =   redChangeA / lenA;
			float greenIncrementA = greenChangeA / lenA;
			float  blueIncrementA =  blueChangeA / lenA;*/

			// Right Side Line = B
			const float lenB = (pv2->v - pv0->v).Len();

			const float   redChangeB = -(float(pv0->c.GetR() - pv2->c.GetR()));
			const float greenChangeB = -(float(pv0->c.GetG() - pv2->c.GetG()));
			const float  blueChangeB = -(float(pv0->c.GetB() - pv2->c.GetB()));

			const float   redIncrementB =   redChangeB / lenB;
			const float greenIncrementB = greenChangeB / lenB;
			const float  blueIncrementB =  blueChangeB / lenB;

			const Color c = Color(
				unsigned char(  redIncrementB * (vi - pv0->v).Len()),
				unsigned char(greenIncrementB * (vi - pv0->v).Len()),
				unsigned char( blueIncrementB * (vi - pv0->v).Len()));

			Vec2Color Vi;
			Vi.v = vi;
			Vi.c = c;

			DrawFlatBottomTriangleThreeColor(*pv0, *pv1, Vi);
			DrawFlatTopTriangleThreeColor(   *pv1, Vi, *pv2);			
		}
		else // major left
		{
			// line left
			float lenA = (pv2->v - pv0->v).Len();

			const float   redChangeA = -(float(pv0->c.GetR() - pv2->c.GetR()));
			const float greenChangeA = -(float(pv0->c.GetG() - pv2->c.GetG()));
			const float  blueChangeA = -(float(pv0->c.GetB() - pv2->c.GetB()));

			const float   redIncrementA = redChangeA / lenA;
			const float greenIncrementA = greenChangeA / lenA;
			const float  blueIncrementA = blueChangeA / lenA;

			// line right
			/*float lenB = (*pv2 - *pv0).Len();

			float   redChangeB = -(float(c0.GetR() - c2.GetR()));
			float greenChangeB = -(float(c0.GetG() - c2.GetG()));
			float  blueChangeB = -(float(c0.GetB() - c2.GetB()));

			float   redIncrementB =   redChangeB / lenB;
			float greenIncrementB = greenChangeB / lenB;
			float  blueIncrementB =  blueChangeB / lenB;*/

			const Color c = Color(
				unsigned char(  redIncrementA * (vi - pv0->v).Len()),
				unsigned char(greenIncrementA * (vi - pv0->v).Len()),
				unsigned char( blueIncrementA * (vi - pv0->v).Len()));
			
			Vec2Color Vi;
			Vi.v = vi;
			Vi.c = c;

			DrawFlatBottomTriangleThreeColor(*pv0, Vi,*pv1);
			DrawFlatTopTriangleThreeColor(   Vi, *pv1, *pv2);
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

	const float changeRedA   = float(-(c0.GetR() - c1.GetR()));
	const float changeGreenA = float(-(c0.GetG() - c1.GetG()));
	const float changeBlueA  = float(-(c0.GetB() - c1.GetB()));

	const float incrementRedA   = changeRedA   / lengthA;
	const float incrementGreenA = changeGreenA / lengthA;
	const float incrementBlueA  = changeBlueA  / lengthA;

	const float lengthB = (v2 - v0).Len();

	const float changeRedB   = float(-(c0.GetR() - c2.GetR()));
	const float changeGreenB = float(-(c0.GetG() - c2.GetG()));
	const float changeBlueB  = float(-(c0.GetB() - c2.GetB()));

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
		//const Color cA = Color(c0.GetR() + (incrementRedA * y), c0.GetG() + (incrementGreenA * y), c0.GetB() + (incrementBlueA * y));
		//const Color cB = Color(c1.GetR() + (incrementRedB * y), c1.GetG() + (incrementGreenB * y), c1.GetB() + (incrementBlueB * y));
		
		// total line length to interpolate color across
		int xLength = xEnd - xStart;
		
		int incrementRed = 1;
		int incrementGreen = 1;
		int incrementBlue = 1;

		for (int x = xStart, i = 0; x < xEnd; x++, i++ )
		{
			//Color c = Color(ci0.GetR() + (incrementRed * i), ci0.GetG() + (incrementGreen * i), ci0.GetB() + (incrementBlue * i));
			gfx.PutPixel(x, y, Colors::Cyan);
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

//void Game::DrawFlatBottomTriangleThreeColor(const Vec2& A, const Vec2& B, const Vec2& C, const Color& color0, const Color& color1, const Color& color2)
//{
//	float sizeABY = abs(A.y - B.y);
//	float sizeABX = abs(A.x - B.x);
//	float slopeAB = sizeABX / sizeABY;
//
//	float sizeACY = abs(A.y - C.y);
//	float sizeACX = abs(A.x - C.x);
//	float slopeAC = sizeACX / sizeACY;
//
//	// color stuff --------------------------------------
//
//	Color c0 = color0;
//	Color c1 = color1;
//	Color c2 = color2;
//
//	// AB
//	float redChangeAB = -(float(c0.GetR() - c1.GetR()));
//	float greenChangeAB = -(float(c0.GetG() - c1.GetG()));
//	float blueChangeAB = -(float(c0.GetB() - c1.GetB()));
//	float redIncrementAB;
//	float greenIncrementAB;
//	float blueIncrementAB;
//
//	float sizeAB = (B - A).Len();
//	redIncrementAB = redChangeAB / sizeAB;
//	greenIncrementAB = greenChangeAB / sizeAB;
//	blueIncrementAB = blueChangeAB / sizeAB;
//
//	// AC
//	float redChangeAC = -(float(c0.GetR() - c2.GetR()));
//	float greenChangeAC = -(float(c0.GetG() - c2.GetG()));
//	float blueChangeAC = -(float(c0.GetB() - c2.GetB()));
//	float redIncrementAC;
//	float greenIncrementAC;
//	float blueIncrementAC;
//
//	float sizeAC = (C - A).Len();
//	redIncrementAC = redChangeAC / sizeAC;
//	greenIncrementAC = greenChangeAC / sizeAC;
//	blueIncrementAC = blueChangeAC / sizeAC;
//
//	//-----------------------------------------------------
//
//	int yStart = (int)A.y;
//	int yEnd;
//
//	if (B.y <= C.y) { yEnd = (int)B.y; }
//	else { yEnd = (int)C.y; }
//
//	for (int y = yStart; y < yEnd; y++)
//	{
//		int xStart;
//		int xEnd;
//
//		if (B.x > A.x) { xStart = int(A.x + ((y - yStart) * slopeAB) + 0.5f); }
//		else { xStart = int(A.x - ((y - yStart) * slopeAB) + 0.5f); }
//
//		if (C.x > A.x) { xEnd = int(A.x + ((y - yStart) * slopeAC) + 0.5f); }
//		else { xEnd = int(A.x - ((y - yStart) * slopeAC) + 0.5f); }
//
//		// color stuff ------------------------------------------------
//
//		float lengthBC = float(xEnd - xStart);
//		float lengthAB = sqrt(sq(A.x - xStart) + sq(y - A.y));
//		float lengthAC = sqrt(sq(A.x - xEnd) + sq(y - A.y));
//
//		//float redStart = 
//		//float redEnd   = 
//		float redChange = -((c0.GetR() + (lengthAB * redIncrementAB)) - (c0.GetR() + (lengthAC * redIncrementAC)));
//		float greenChange = -((c0.GetG() + (lengthAB * greenIncrementAB)) - (c0.GetG() + (lengthAC * greenIncrementAC)));
//		float blueChange = -((c0.GetB() + (lengthAB * blueIncrementAB)) - (c0.GetB() + (lengthAC * blueIncrementAC)));
//
//		float redIncrement = redChange / lengthBC;
//		float greenIncrement = greenChange / lengthBC;
//		float blueIncrement = blueChange / lengthBC;
//
//		// -----------------------------------------------
//
//		for (int x = xStart; x < xEnd; x++)
//		{
//			// color stuff -----------------------------------------			
//
//			unsigned char redStart = c0.GetR() + unsigned char(lengthAB * redIncrementAB);
//			unsigned char greenStart = c0.GetG() + unsigned char(lengthAB * greenIncrementAB);
//			unsigned char blueStart = c0.GetB() + unsigned char(lengthAB * blueIncrementAB);
//			unsigned char red = redStart + unsigned char((x - xStart) * redIncrement);
//			unsigned char green = greenStart + unsigned char((x - xStart) * greenIncrement);
//			unsigned char blue = blueStart + unsigned char((x - xStart) * blueIncrement);
//
//			Color c = Color(red, green, blue);
//
//			// -----------------------------------
//
//			gfx.PutPixel(x, y, c);
//		}
//	}
//}
