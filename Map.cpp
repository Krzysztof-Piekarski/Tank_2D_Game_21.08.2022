#include "Map.h"

Map::Map(Settings& tempSet, sf::RenderWindow& tempWindow, Player& tempPlayer) : set(tempSet), window(tempWindow), player(tempPlayer)
{
	fromX = 0;
	toX = set.mapXsize;
	fromY = 0;
	toY = set.mapYsize;
}

void Map::setPlayerVelocity()
{
	switch (mapArray[(short)(player.base.getPosition().y / 100)][(short)(player.base.getPosition().x / 100)])
	{
	case 1:
		player.velocity = 4; break;
	case 2:
		player.velocity = 1; break;
	case 3:
		player.velocity = 2; break;
	default:
		player.velocity = 6; break;
	}
}

void Map::draw()
{
	setTilesToDraw();

	for (short y = fromY; y < toY; ++y)
	{
		for (short x = fromX; x < toX; ++x)
		{
			tile.sprite.setPosition({ x * set.tileSize, y * set.tileSize });
			tile.update(mapArray[y][x], x, y);
			window.draw(tile.sprite);
		}
	}
}

void Map::setTilesToDraw()
{
	if (((window.getView().getCenter().x - (window.getView().getSize().x / 2)) / set.tileSize) <= 0)
		fromX = 0;
	else
		fromX = (short)((window.getView().getCenter().x - (window.getView().getSize().x / 2)) / set.tileSize);

	if (fromX + (window.getView().getSize().x / set.tileSize) + 2 >= set.mapXsize)
		toX = set.mapXsize;
	else
		toX = (short)(fromX + (window.getView().getSize().x / set.tileSize) + 2);


	if (((window.getView().getCenter().y - (window.getView().getSize().y / 2)) / set.tileSize) <= 0)
		fromY = 0;
	else
		fromY = (short)((window.getView().getCenter().y - (window.getView().getSize().y / 2)) / set.tileSize);

	if (fromY + (window.getView().getSize().y / set.tileSize) + 2 >= set.mapYsize)
		toY = set.mapYsize;
	else
		toY = (short)(fromY + (window.getView().getSize().y / set.tileSize) + 2);
}