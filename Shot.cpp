#include "Shot.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

Shot::Shot(Player& tempPlayer, sf::RenderWindow& tempWindow) : player(tempPlayer), window(tempWindow)
{
	shape.setFillColor({0,0,0,255});
	shape.setRadius(3);
	shape.setOrigin({ shape.getRadius(), shape.getRadius()});

	aimDir = sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))) - (player.base.getPosition());
	aimDirNorm.x = (float)(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
	aimDirNorm.y = (float)(aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

	shape.setPosition(player.base.getPosition().x + aimDirNorm.x * 55, player.base.getPosition().y + aimDirNorm.y * 55);
	velocity = aimDirNorm * maxVelocity;
}

void Shot::update()
{
	shape.move(velocity);
}
