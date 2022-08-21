#pragma once
#include "Player.h"
#include "Shot.h"
#include <vector>

class Shooting
{
public:
	Shooting(Player&, sf::RenderWindow&);
	void shooting();

private:
	Player& player;
	std::vector<Shot*> shots;
	sf::RenderWindow& window;
	sf::Clock clock;
};