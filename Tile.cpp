#include "Tile.h"

Tile::Tile()
{
	setTile();
}

void Tile::setTile()
{
	texture.loadFromFile("Textures/mapTiles.png");
	rectSprite.height = tileSize;
	rectSprite.width = tileSize;
	rectSprite.top = 0;
	rectSprite.left = rectSprite.left = 0;
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSprite);
}

void Tile::update(short& i, short& x, short& y)
{
	if(i == 1)
	{
		rectSprite.top = 0;
		rectSprite.left = 0;
	}
	else if (i == 2)
	{
		rectSprite.top = 0;
		rectSprite.left = 300;
	}
	else if (i == 3)
	{
		animateWater(x, y);
	}
	else if (i == 4)
	{
		rectSprite.top = 100;
		rectSprite.left = 0;
	}
	else if (i == 5)
	{
		rectSprite.top = 100;
		rectSprite.left = 300;
	}
	else if (i == 6)
	{
		rectSprite.top = 0;
		rectSprite.left = 100;
	}
	else if (i == 7)
	{
		rectSprite.top = 0;
		rectSprite.left = 200;
	}
	else if (i == 8)
	{
		rectSprite.top = 100;
		rectSprite.left = 100;
	}
	else if (i == 9)
	{
		rectSprite.top = 100;
		rectSprite.left = 200;
	}

	sprite.setTextureRect(rectSprite);
}

void Tile::animateWater(short& x, short& y)
{
	rectSprite.left = (int)(clock.getElapsedTime().asSeconds() +x +y) % 4 * 100;
	rectSprite.top = 200;
}