#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player.h"
#include "Tile.h"

class Map
{
public:
	Map(Settings&, sf::RenderWindow&, Player&);
	void setPlayerVelocity();
	void draw();
	Tile tile;

private:
	Settings& set;
	Player& player;
	sf::RenderWindow& window;
	short fromX, toX, fromY, toY;
	void setTilesToDraw();

	short mapArray[30][30] =
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,4,4,4,4,4,4,4,4,4,4,4,7,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,5,1,1,1},
	{4,4,4,4,4,4,4,4,4,4,7,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,3,3,3,3,3,3,3,3,3,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,3,3,3,3,3,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,3,3,3,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,8,4,4,4},
	{1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,8,4,4,4,4,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
};
