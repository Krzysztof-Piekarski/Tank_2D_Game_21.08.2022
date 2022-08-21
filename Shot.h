#pragma once
#include "Player.h"

class Shot
{
public:
	Shot(Player&, sf::RenderWindow&);
	~Shot() = default;
	sf::CircleShape shape;
	void update();

private:
	Player& player;
	sf::RenderWindow& window;
	float maxVelocity = 10;
	sf::Vector2f velocity;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePos;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
};