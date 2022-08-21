#include "Game.h"

Game::Game(Settings& tempSet, sf::RenderWindow& tempWindow, sf::Event& tempEvent) : set(tempSet), window(tempWindow), event(tempEvent)
{
	round();
}

void Game::round()
{
	sf::View view;
	view.setSize(set.width(), set.height());
	view.setCenter(set.width() / 2, set.height() / 2);


	Player player(set, window);
	Shooting shooting(player, window);
	Map map(set, window, player);

	while (1)
	{
		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}

		player.update();
		map.setPlayerVelocity();

		setView(view, player);
		window.clear({ 0, 0, 0, 255 });

		map.draw();
		window.draw(player.base);
		shooting.shooting();
		window.draw(player.top);
		window.display();
	}
}

void Game::setView(sf::View& view, Player& player)
{
	if (player.base.getPosition().x > 0 + set.width() / 2 && player.base.getPosition().x < set.mapXsize * set.tileSize - set.width() / 2)
	{
		view.setCenter(player.base.getPosition().x, view.getCenter().y);
	}

	if (player.base.getPosition().y > 0 + set.height() / 2 && player.base.getPosition().y < set.mapYsize * set.tileSize - set.height() / 2)
	{
		view.setCenter(view.getCenter().x, player.base.getPosition().y);
	}

	window.setView(view);
}
