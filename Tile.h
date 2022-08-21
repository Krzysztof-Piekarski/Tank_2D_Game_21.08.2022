#pragma once
#include "Player.h"

class Tile
{
public:
	Tile();
	float tileSize = 100;
	void setTile();
	void update(short&, short&, short&);
	void animateWater(short&, short&);
	~Tile() = default;
	sf::Sprite sprite;
	sf::IntRect rectSprite;

private:
	sf::Texture texture;
	sf::Clock clock;
};