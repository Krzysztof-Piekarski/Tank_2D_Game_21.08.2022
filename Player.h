#pragma once
#include "Settings.h"

class Player
{
public:
	Player(Settings&, sf::RenderWindow&);
	void update();
	sf::Sprite base;
	sf::Sprite top;
	float velocity = 4;

private:
	Settings& set;
	sf::RenderWindow& window;
	sf::Texture baseTexture;
	sf::Texture topTexture;
	sf::Vector2f mousePos;
	short rotationSpeed = 2;
	float topAngle = 0;
	float baseAngle = 0;
	void control();
	void topAngleSet();
};