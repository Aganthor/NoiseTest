// NoiseTest.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <sfml/Graphics/Image.hpp>
#include <memory>

#include "map/WorldMapGenerator.hpp"

int main()
{
	const int MAPWIDTH = 512;
	const int MAPHEIGHT = 512;
	sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "SFML Demo");
	sf::Event event;

	
	//map::WorldMapGenerator map(MAPWIDTH, MAPHEIGHT);
	//std::unique_ptr<sf::Uint8[]> pixels(new sf::Uint8[MAPWIDTH * MAPHEIGHT * 4]);
	//sf::Image heightMap;
	//sf::Texture texture;
	//float mapValue;
	//sf::Sprite sprite;

	//texture.create(MAPWIDTH, MAPHEIGHT);

	//map.setScale(1.0f);
	//map.setOffset(sf::Vector2f(5, 5));
	//map.generateMap();

	//int pixelOffset = 0;
	//for (auto x = 0; x < map.getMapWidth(); ++x)
	//{
	//	for (auto y = 0; y < map.getMapHeight(); ++y, pixelOffset +=3)
	//	{
	//		mapValue = map.getValueAt(x, y);
	//		if ((mapValue >= -1.0) && (mapValue < -0.25))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset - 3)] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset - 2)] = 128;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset - 1)] = 255;
	//		}
	//		else if ((mapValue >= -0.25) && (mapValue < 0.0))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 255;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//		else if ((mapValue >= 0.0) && (mapValue < 0.0625))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 128;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 255;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//		else if ((mapValue >= 0.0625) && (mapValue < 0.1250))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 240;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 240;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 64;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//		else if ((mapValue >= 0.1250) && (mapValue < 0.3750))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 32;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 160;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//		else if ((mapValue >= 0.3750) && (mapValue < 0.75))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 224;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 224;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 0;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//		else if ((mapValue >= 0.75) && (mapValue < 1.0))
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 128;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 128;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 128;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//		else
	//		{
	//			pixels[x *  map.getMapWidth() + y + pixelOffset] = 255;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 1)] = 255;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 2)] = 255;
	//			pixels[(x *  map.getMapWidth() + y) + (pixelOffset + 3)] = 255;
	//		}
	//	}
	//}

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

	//texture.update(pixels.get());
	//sprite.setTexture(texture);

	while (renderWindow.isOpen()) {
		// Check for all the events that occured since the last frame.
		while (renderWindow.pollEvent(event)) {
			//Handle events here
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}

		renderWindow.clear();
		//renderWindow.draw(sprite);
		renderWindow.display();
	}
}