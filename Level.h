#ifndef LEVEL_H__
#define LEVEL_H__
#include <vector>
#include "BackgroundLayer.h"
class Level
{
	
	std::vector<BackgroundLayer> bgLayers;

	int numScreensProgressed{ 0 };



public:
	Level();
	~Level();
	Level(const Level&) = delete;
	Level& operator=(const Level&) = delete;
	Level(Level&&) = default;
	Level& operator=(Level&&) = default;



};

#endif