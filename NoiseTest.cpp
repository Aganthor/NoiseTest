// NoiseTest.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <sfml/Graphics/Image.hpp>
#include <memory>

#include "WorldMapGenerator.h"

int main()
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "SFML Demo");
	sf::Event event;
	mapgenerator::WorldMapGenerator map(256, 256);
	//std::vector<sf::Uint8> pixels(256 * 256 * 4);
	std::unique_ptr<sf::Uint8[]> pixels(new sf::Uint8[256 * 256 * 4]);
	sf::Image heightMap;
	sf::Texture texture;
	float mapValue;
	sf::Sprite sprite(texture);

	texture.create(256, 256);

	map.generateMap();

	for (auto w = 0; w < map.getMapWidth(); ++w)
	{
		for (auto h = 0; h < map.getMapHeight(); ++h)
		{
			mapValue = map.getValueAt(h, w);
			if ((mapValue >= -1.0) && (mapValue < -0.25))
			{
				pixels[w * map.getMapWidth() + h] = 0;
				pixels[(w * map.getMapWidth() + h) + 1] = 0;
				pixels[(w * map.getMapWidth() + h) + 2] = 128;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else if ((mapValue >= -0.25) && (mapValue < 0.0))
			{
				pixels[w * map.getMapWidth() + h] = 0;
				pixels[(w * map.getMapWidth() + h) + 1] = 0;
				pixels[(w * map.getMapWidth() + h) + 2] = 255;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else if ((mapValue >= 0.0) && (mapValue < 0.0625))
			{
				pixels[w * map.getMapWidth() + h] = 0;
				pixels[(w * map.getMapWidth() + h) + 1] = 128;
				pixels[(w * map.getMapWidth() + h) + 2] = 255;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else if ((mapValue >= 0.0625) && (mapValue < 0.1250))
			{
				pixels[w * map.getMapWidth() + h] = 240;
				pixels[(w * map.getMapWidth() + h) + 1] = 240;
				pixels[(w * map.getMapWidth() + h) + 2] = 64;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else if ((mapValue >= 0.1250) && (mapValue < 0.3750))
			{
				pixels[w * map.getMapWidth() + h] = 32;
				pixels[(w * map.getMapWidth() + h) + 1] = 160;
				pixels[(w * map.getMapWidth() + h) + 2] = 0;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else if ((mapValue >= 0.3750) && (mapValue < 0.75))
			{
				pixels[w * map.getMapWidth() + h] = 224;
				pixels[(w * map.getMapWidth() + h) + 1] = 224;
				pixels[(w * map.getMapWidth() + h) + 2] = 0;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else if ((mapValue >= 0.75) && (mapValue < 1.0))
			{
				pixels[w * map.getMapWidth() + h] = 128;
				pixels[(w * map.getMapWidth() + h) + 1] = 128;
				pixels[(w * map.getMapWidth() + h) + 2] = 128;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
			else
			{
				pixels[w * map.getMapWidth() + h] = 255;
				pixels[(w * map.getMapWidth() + h) + 1] = 255;
				pixels[(w * map.getMapWidth() + h) + 2] = 255;
				pixels[(w * map.getMapWidth() + h) + 3] = 255;
			}
		}
	}

	/*
  renderer.AddGradientPoint (-1.0000, utils::Color (  0,   0, 128, 255)); // deeps
  renderer.AddGradientPoint (-0.2500, utils::Color (  0,   0, 255, 255)); // shallow
  renderer.AddGradientPoint ( 0.0000, utils::Color (  0, 128, 255, 255)); // shore
  renderer.AddGradientPoint ( 0.0625, utils::Color (240, 240,  64, 255)); // sand
  renderer.AddGradientPoint ( 0.1250, utils::Color ( 32, 160,   0, 255)); // grass
  renderer.AddGradientPoint ( 0.3750, utils::Color (224, 224,   0, 255)); // dirt
  renderer.AddGradientPoint ( 0.7500, utils::Color (128, 128, 128, 255)); // rock
  renderer.AddGradientPoint ( 1.0000, utils::Color (255, 255, 255, 255)); // snow
	*/

	texture.update(pixels.get());

	while (renderWindow.isOpen()) {
		// Check for all the events that occured since the last frame.
		while (renderWindow.pollEvent(event)) {
			//Handle events here
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		renderWindow.clear();
		renderWindow.draw(sprite);
		renderWindow.display();
	}
}