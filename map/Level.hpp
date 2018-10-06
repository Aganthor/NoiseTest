#pragma once

#include <vector>
#include <memory>

#include "BaseMapGenerator.hpp"
#include "Tileinfo.hpp"

namespace map
{
	//
	// Level class will represent the actual level to be used for logic
	// and rendering. 
	//
	class Level
	{
	public:
		Level();
		~Level();

		void generateLevel();
		void renderLevel();
		//void saveLevel();
		//void loadLevel();

		TileInfo& getTileInfo(int x, int y);
		

	private:
		std::unique_ptr<BaseMapGenerator> m_mapGenerator;
		std::vector<std::vector<TileInfo>> m_levelData;
	};
}
