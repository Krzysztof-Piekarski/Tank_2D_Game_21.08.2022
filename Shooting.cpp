#include "Shooting.h"

Shooting::Shooting(Player& tempPlayer, sf::RenderWindow& tempWindow) : player(tempPlayer), window(tempWindow)
{

}

void Shooting::shooting()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (clock.getElapsedTime().asMilliseconds() > 150)
		{
			shots.push_back(new Shot(player, window));
			clock.restart();
		}
	}

	for (size_t i = 0; i < shots.size(); ++i)
	{
		shots[i]->update();
		window.draw(shots[i]->shape);
		
		if (shots[i]->shape.getPosition().x < 0 + window.getView().getCenter().x - window.getSize().x / 2 ||
			shots[i]->shape.getPosition().x > window.getView().getCenter().x + window.getSize().x / 2 ||
			shots[i]->shape.getPosition().y < 0 + window.getView().getCenter().y - window.getSize().y / 2 ||
			shots[i]->shape.getPosition().y > window.getView().getCenter().y + window.getSize().y / 2)
		{
			delete shots[i];
			shots.erase(shots.begin() + i);
		}
	}

}
