#include "Level.hpp"

#include <utility>


namespace map
{

	Level::Level()
	{
		loadTextureFiles();
	}

	Level::~Level()
	{
	}

	//void Level::setGenerator(BaseMapGenerator* generator)
	//{
//		m_mapGenerator = generator;
	//}

	void Level::generateLevel()
	{
	}

	void Level::renderLevel()
	{
	}

	void Level::loadTextureFiles()
	{
		m_textureManager.addTexture("deep_water");
		m_textureManager.addTexture("shallow_water");
		m_textureManager.addTexture("dirt");
		m_textureManager.addTexture("grass");
		m_textureManager.addTexture("rock");
		m_textureManager.addTexture("sand");
		m_textureManager.addTexture("shore");
		m_textureManager.addTexture("snow");
	}

	void Level::createLevelData()
	{
	}

	/*
	TileInfo & Level::getTileInfo(int x, int y)
	{
		// TODO: insert return statement here
	}
	*/

}