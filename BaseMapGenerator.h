#pragma once

#include <vector>
#include "FastNoise/FastNoise.h"

namespace mapgenerator
{
	//
	// Pure virtual class. Will be specialized according to our map need.
	//
	class BaseMapGenerator
	{
	public:
		BaseMapGenerator(int w, int h) : m_mapWidth{ w }, m_mapHeight{ h } {};
		virtual ~BaseMapGenerator() {};

		virtual void generateMap() = 0;

		inline float getValueAt(int h, int w)
		{
			return m_mapData[h * m_mapHeight + w];
		}

		const int getMapWidth() { return m_mapWidth; }
		const int getMapHeight() { return m_mapHeight; }

	protected:
		std::vector<float> m_mapData;
		FastNoise m_myNoise;
		int m_mapWidth;
		int m_mapHeight;
	};
}
