#pragma once

#include <vector>
#include <memory>

#include "BaseMapGenerator.hpp"
#include "Tileinfo.hpp"
#include "../utility/TextureManager.hpp"

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

		void setGenerator(BaseMapGenerator* generator);
		void generateLevel();
		void renderLevel();
		//void saveLevel();
		//void loadLevel();

		TileInfo& getTileInfo(int x, int y);

	private:
		void loadTextureFiles();

		void createLevelData();
		

	private:
		BaseMapGenerator* m_mapGenerator;
		std::vector<std::vector<TileInfo>> m_levelData;
		TextureManager m_textureManager;
	};
}
