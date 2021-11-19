#include "Collectable.h"
#include <iostream>

extern sf::Vector2f dimensions;

void Collectable::Dead()//resets collectable
{
	m_alive = false;
	m_electric = false;
}

sf::Vector2f Collectable::getRandomPosition()//gets a random vector 2f withing screen range
{
	m_pos.x = (rand()% 40)*20;
	m_pos.y = (rand()% 40)*20;
	return m_pos;
}

void Collectable::Spawn(sf::RenderWindow& window)
{
	m_alive = true;
	sf::RectangleShape rectangle(dimensions);
	if (rand() % 4 == 1)// randomly sees if the collectable should be electric
	{
		m_electric = true;
		rectangle.setFillColor(sf::Color::Magenta);
	}
	else//else spawn a normal collectable
	{
		if (m_grow == 0)
		{
			m_grow++;
			rectangle.setFillColor(sf::Color::Green);
		}
		else if (m_grow == 1)
		{
			m_grow++;
			rectangle.setFillColor(sf::Color::Yellow);
		}
		else if (m_grow == 2)
		{
			m_grow++;
			rectangle.setFillColor(sf::Color::Black);
		}
	}
	rectangle.setPosition(m_pos);
	window.draw(rectangle);
}

void Collectable::Render(sf::RenderWindow& window)//renders each collectable depending on there growth or if there electric
{
	sf::RectangleShape rectangle(dimensions);
	if (m_electric == true)
	{
		rectangle.setFillColor(sf::Color::Magenta);
	}
	else
	{
		if (m_grow == 1)
		{
			rectangle.setFillColor(sf::Color::Green);
		}
		if (m_grow == 2)
		{
			rectangle.setFillColor(sf::Color::Yellow);
		}
		if (m_grow == 3)
		{
			rectangle.setFillColor(sf::Color::Black);
		}
	}
	rectangle.setPosition(m_pos);
	window.draw(rectangle);
}


