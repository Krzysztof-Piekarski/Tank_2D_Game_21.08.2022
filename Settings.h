#pragma once
#include <SFML/Graphics.hpp>

class Settings
{
public:
	Settings() = default;

	float width();
	float height();
	float tileSize = 100;
	short mapXsize = 30;
	short mapYsize = 30;

private:
	sf::Vector2f windowSize{ 1920, 1080 };
};

