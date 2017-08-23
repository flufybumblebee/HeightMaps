/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.h																				  *
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
#pragma once

#include "Graphics.h"
#include "Colors.h"

#include "CameraTransform.h"

#include "Vec2.h"

#include <algorithm>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

	void DrawTriangleInterpolated(Vec2 p0, Vec2 p1, Vec2 p2, Color c0, Color c1, Color c2);
private:
	MainWindow&	wnd;
	Graphics	gfx;

	CameraTransform cam;

	const float side = 320.0f;
	const float sideHalf = side / 2.0f;
	const float sideSq = sq(side);
	const float sideHalfSq = sq(sideHalf);
	const float littleY = sideHalf * tan(PI / 6);
	const float bigY = sqrt(sideSq - sideHalfSq) - littleY;

	const Vec2 p0 = { -sideHalf, littleY };
	const Vec2 p1 = { 0.0f, -bigY };
	const Vec2 p2 = { sideHalf, littleY };

	float angle = 0.0f;
	float scale = 1.0f;
	const Vec2 position = { Graphics::ScreenWidth/2, Graphics::ScreenHeight/2 };

	int red0 = 0;
	int green0 = 0;
	int blue0 = 0;

	int red1 = 0;
	int green1 = 0;
	int blue1 = 0;

	float size = 100.0f;
	const Vec2 n0 = { -size, -size };
	const Vec2 n1 = {  size, -size };
	const Vec2 n2 = {  size,  size };
	const Vec2 n3 = { -size,  size };
};