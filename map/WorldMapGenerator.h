#pragma once

#include <vector>
#include <sfml/System/Vector2.hpp>

#include "../FastNoise/FastNoise.h"

namespace map
{
	//
	// Will be used to generate our world map. 
	//
	class WorldMapGenerator
	{
	public:
		WorldMapGenerator() = delete;
		WorldMapGenerator(int width, int height);
		WorldMapGenerator(int width, int height, int seed, float scale, int octaves,
			float persistance, float lacunarity, sf::Vector2f offset);
		~WorldMapGenerator();

		void generateMap();

		inline float getValueAt(int x, int y)
		{
			return m_mapData[y * m_mapWidth + x];
		}

		//
		// Getters and setters.
		//
		const int getMapWidth() { return m_mapWidth; }
		const int getMapHeight() { return m_mapHeight; }
		const int getSeed() { return m_seed; }
		const float getScale() { return m_scale; }
		const int getOctaves() { return m_octaves; }
		const float getPersistance() { return m_persistance; }
		const float getLacunarity() { return m_lacunarity; }
		const sf::Vector2f getOffset() { return m_offset; }

		void setMapWidth(int w) { m_mapWidth = w; }
		void setMapHeight(int h) { m_mapHeight = h; }
		void setSeed(int seed) { m_seed = seed; }
		void setScale(float scale) { m_scale = scale; }
		void setOctaves(int octaves) { m_octaves = octaves; }
		void setPersistance(float persistance) { m_persistance = persistance; }
		void setLacunarity(float lacunarity) { m_lacunarity = lacunarity; }
		void setOffset(sf::Vector2f offset) { m_offset = offset; }

	private:
		inline float inverseLerp(float x, float y, float value)
		{
			return (value - x) / (y - x);
		}

	private:
		std::vector<float> m_mapData;
		FastNoise m_myNoise;
		int m_mapWidth;
		int m_mapHeight;
		int m_seed = 21;
		float m_scale = 1.0f;
		int m_octaves = 4;
		float m_persistance = 0.5f;
		float m_lacunarity = 1.5f;
		sf::Vector2f m_offset;
	};
} // end of namespace map