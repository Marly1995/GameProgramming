#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_rect.h>

using namespace std;

class Level
{
public:
	float xStartPos = 32;
	float yStartPos = 576;

	string floor;
	string ladder;
	string background;

	int currentLevel = 0;

	int world[20][20] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,2,1,1,0,1,1,1,1,1,1,0,1,1 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,1,1,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,1,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,1,2,1,1,1,2,1,0,0,0,1,1,1,1,1,1,1,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,2,1,1,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	};
	int world2[20][20] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,2,1,1,0,1,1,1,1,1,1,0,1,1 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,1,1,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,1,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,1,2,1,1,1,2,1,0,0,0,1,1,1,1,1,1,1,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,1,1,1,2,1,1,1,1,2,1,1,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	};
	int world3[20][20] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,2,1,1,0,1,1,1,1,1,1,0,1,1 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,0,0,1,1,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,1,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,1,2,1,1,1,2,1,0,0,0,1,1,1,1,1,1,1,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,1,1,1,1,1,1,2,1,1,1,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,2,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	};

	Level(string floorName, string ladderName, string backgroundName);
};

Level::Level(string floorName, string ladderName, string backgroundName)
{
	floor = floorName;
	ladder = ladderName;
	background = backgroundName;

}