#include "Player.h"
#include <cmath>

Player::Player(Settings& tempSet, sf::RenderWindow& tempWindow) : set(tempSet), window(tempWindow)
{
	baseTexture.loadFromFile("Textures/tankBase.png");
	base.setTexture(baseTexture);
	base.setOrigin(50, 75);
	base.setPosition(set.width()/2, set.height()/2);

	topTexture.loadFromFile("Textures/tankTop.png");
	top.setTexture(topTexture);
	top.setOrigin(50, 75);
	top.setPosition(set.width() / 2, set.height() / 2);
}

void Player::update()
{
	mousePos = window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition(window)));
	control();
	top.setPosition(base.getPosition());
	topAngleSet();
	top.setRotation(topAngle);
}

void Player::control()
{
	baseAngle = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		baseAngle -= rotationSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		baseAngle += rotationSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if ((base.getRotation() > 270 || base.getRotation() < 90) && base.getPosition().y < 30)
		{
			base.move({ cos(float((base.getRotation() - 90) * 0.01745329252)) * velocity , 0 });
		}
		else if (base.getRotation() > 90 && base.getRotation() < 270 && base.getPosition().y > set.mapYsize * set.tileSize - 30)
		{
			base.move({ cos(float((base.getRotation() - 90) * 0.01745329252)) * velocity , 0 });
		}
		else if (base.getRotation() > 180 && base.getPosition().x < 30)
		{
			base.move({ 0 , sin(float((base.getRotation() - 90) * 0.01745329252)) * velocity });
		}
		else if (base.getRotation() < 180 && base.getPosition().x > set.mapXsize * set.tileSize - 30)
		{
			base.move({ 0 , sin(float((base.getRotation() - 90) * 0.01745329252)) * velocity });
		}
		else
			base.move({ cos(float((base.getRotation() - 90) * 0.01745329252)) * velocity , sin(float((base.getRotation() - 90) * 0.01745329252)) * velocity });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (base.getRotation() < 270 && base.getRotation() > 90 && base.getPosition().y < 30)
		{
			base.move({ cos(float((base.getRotation() + 90) * 0.01745329252)) * velocity , 0 });
		}
		else if ((base.getRotation() < 90 || base.getRotation() > 270) && base.getPosition().y > set.mapYsize * set.tileSize - 30)
		{
			base.move({ cos(float((base.getRotation() + 90) * 0.01745329252)) * velocity , 0 });
		}
		else if (base.getRotation() < 180 && base.getPosition().x < 30)
		{
			base.move({ 0 , sin(float((base.getRotation() + 90) * 0.01745329252)) * velocity });
		}
		else if (base.getRotation() > 180 && base.getPosition().x > set.mapXsize * set.tileSize - 30)
		{
			base.move({ 0 , sin(float((base.getRotation() + 90) * 0.01745329252)) * velocity });
		}
		else
			base.move({ cos(float((base.getRotation() + 90) * 0.01745329252)) * velocity , sin(float((base.getRotation() + 90) * 0.01745329252)) * velocity });
	}

	base.rotate(baseAngle);
}

void Player::topAngleSet()
{
	if (mousePos.y - base.getPosition().y < 0)
		topAngle = (float)(360 - atan((mousePos.x - top.getPosition().x) / (mousePos.y - top.getPosition().y)) * 180 / 3.14159265359);
	else
		topAngle = (float)(180 - atan((mousePos.x - top.getPosition().x) / (mousePos.y - top.getPosition().y)) * 180 / 3.14159265359);
}