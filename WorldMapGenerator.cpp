#include "WorldMapGenerator.h"

namespace mapgenerator
{
	WorldMapGenerator::WorldMapGenerator(int width, int height) : BaseMapGenerator(width, height)
	{
		m_mapData.resize(m_mapWidth * m_mapHeight);
	}

	WorldMapGenerator::~WorldMapGenerator()
	{

	}

	void WorldMapGenerator::generateMap()
	{
		//Use simplex noise to generate our map.
		m_myNoise.SetNoiseType(FastNoise::Simplex);

		for (auto w = 0; w < m_mapWidth; ++w)
		{
			for (auto h = 0; h < m_mapHeight; ++h)
			{
				m_mapData[h * m_mapHeight + w] = m_myNoise.GetNoise(w, h);
			}
		}
	}
}