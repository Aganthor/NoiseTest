#pragma once

#include <vector>
#include "FastNoise/FastNoise.h"

namespace map
{
	//
	// Will be used to generate our world map. 
	//
	class WorldMapGenerator
	{
	public:
		WorldMapGenerator();
		WorldMapGenerator(int width, int height);
		WorldMapGenerator(int width, int height, int seed, float scale, int octaves,
			float persistance, float lacunarity);
		~WorldMapGenerator();

		void generateMap(int seed, float scale, int octaves, float persistance, float lacunarity);
		void generateMap();

		inline float getValueAt(int x, int y)
		{
			return m_mapData[y * m_mapWidth + x];
		}

		const int getMapWidth() { return m_mapWidth; }
		const int getMapHeight() { return m_mapHeight; }

	private:
		std::vector<float> m_mapData;
		FastNoise m_myNoise;
		int m_mapWidth;
		int m_mapHeight;
		int m_seed;
		float m_scale;
		int m_octaves;
		float m_persistance;
		float m_lacunarity;
	};
}