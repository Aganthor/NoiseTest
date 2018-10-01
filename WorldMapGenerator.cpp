#include "WorldMapGenerator.h"

namespace map
{
	WorldMapGenerator::WorldMapGenerator() : m_mapWidth{ 0 }, m_mapHeight{ 0 }, m_seed{ 0 },
		m_scale{ 0.0f }, m_octaves{ 0 }, m_persistance{ 0.0f }, m_lacunarity{0.0f}
	{

	}
	
	WorldMapGenerator::WorldMapGenerator(int width, int height, int seed, 
		float scale, int octaves,
		float persistance, float lacunarity) : 
		m_mapWidth{ width }, m_mapHeight{ height }, 
		m_seed{ seed }, m_scale{ scale }, 
		m_octaves{ octaves }, m_persistance{ persistance }, 
		m_lacunarity{ lacunarity }
	{

	}
	WorldMapGenerator::WorldMapGenerator(int width, int height) : m_mapWidth{ width }, m_mapHeight{ height }
	{
		m_mapData.resize(m_mapWidth * m_mapHeight);
	}

	WorldMapGenerator::~WorldMapGenerator()
	{

	}

	void WorldMapGenerator::generateMap(int seed, float scale, int octaves, float persistance, float lacunarity)
	{
		//Use simplex noise to generate our map.
		m_myNoise.SetNoiseType(FastNoise::Simplex);

		//m_myNoise.SetFrequency(0.005);

		for (auto x = 0; x < m_mapWidth; ++x)
		{
			for (auto y = 0; y < m_mapHeight; ++y)
			{
				m_mapData[y * m_mapWidth + x] = m_myNoise.GetNoise(x, y);
			}
		}
	}
}