#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Game.h"

int main()
{
	Settings set;
	sf::RenderWindow window(sf::VideoMode((unsigned)set.width(), (unsigned)set.height()), "Tank 2D");
	window.setFramerateLimit(60);
	sf::Event event;

	Game game(set, window, event);
}
