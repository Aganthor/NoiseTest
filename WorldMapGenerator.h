#pragma once

#include "BaseMapGenerator.h"

namespace mapgenerator
{
	//
	// Will be used to generate our world map. 
	//
	class WorldMapGenerator : public BaseMapGenerator
	{
	public:
		WorldMapGenerator(int width, int height);
		~WorldMapGenerator() override;

		void generateMap() override;
	};
}
