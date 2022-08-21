#pragma once
#include <SFML\Graphics.hpp>
#include "Settings.h"
#include "Player.h"
#include "Shooting.h"
#include "Map.h"

class Game
{
public:
	Game(Settings&, sf::RenderWindow&, sf::Event&);
	void round();

private:
	Settings& set;
	sf::RenderWindow& window;
	sf::Event& event;
	void setView(sf::View&, Player&);
};