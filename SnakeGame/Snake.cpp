#include "Snake.h"
#include <iostream>

sf::Vector2f dimensions(20, 20);
sf::Vector2f dimensionsTwo(60, 60);

Snake::Snake(sf::Vector2f pos,sf::Color colour)
{
	m_colour = colour;
	m_segments.push_back(pos);
}

sf::Vector2f Snake::GetPosition()
{
	sf::Vector2f pos;
	pos = m_segments.front();
	return pos;
}

void Snake::Cannibal(std::vector<Snake*> snakes)
{
	int i = 1;
	for (Snake* snake : snakes)
	{
		if (snake->IsAlive() && snake!= this)
		{
			for (sf::Vector2f segments : m_segments)
			{
				if (m_segments.front() == segments) // making sure that the head doesnt register itself as being collided with
				{
					if (i == 1)
					{
						i = 0;
					}
					else
					{
						m_alive = false;
					}
				}
			}
			for (sf::Vector2f Tsegments : snake->m_segments)//Tsegments = Temporary segments
			{
				if (!m_electric)//checking for collisions with other snakes
				{
					if (m_segments.front() == Tsegments)
					{
						m_alive = false;
					}
				}
				else
				{//checking for collisions with snakes that are electrified
					sf::Vector2f tempPos= m_segments.front();
					if (tempPos== Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.x -= 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.y -= 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos = m_segments.front();
					tempPos.x += 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.y += 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.y -= 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.x -= 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.y += 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
					tempPos.x += 20;
					if (tempPos == Tsegments)
					{
						std::cout << "electric";
						m_alive = false;
					}
				}
			}
		}
	}
}

void Snake::Dead()
{
	m_alive = false;
}

void Snake::Electrify()
{
	m_electric = true;
}

void Snake::SetScore(int grow)
{
	m_score = m_score + grow;//increasing score
	m_grow += grow; // increases the amount in which the snake must grow in next update
}

void Snake::Update()
{
	sf::Vector2f position = m_segments.front();
	switch (m_movement)
	{
	case EMovement::eNorth:
		position.y -= 20;
		break;
	case EMovement::eWest:
		position.x -= 20;
		break;
	case EMovement::eSouth:
		position.y += 20;
		break;
	case EMovement::eEast:
		position.x += 20;
		break;
	default:
		break;
	}
	if (m_electric == true)
	{
		m_counter--;
	}

	m_segments.push_front(position);

	if (m_grow > 0)
	{
		m_grow--;// if it does need to grow it keeps that segment
	}
	else//if it doesnt need to grow snake pops the back segment to move
	{
		m_segments.pop_back();
	}
}

void Snake::ChangeDirection(EMovement movement)
{
	m_movement = movement;
}


void Snake::Render(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle(dimensions);
	sf::RectangleShape Trectangle(dimensionsTwo);// Trectangle = Temporary rectangle
	if (m_electric == true)
	{
		if (m_counter == 0)
		{
			m_electric = false;
			m_counter = 40;//resetting electric counter for next pickup
		}
		for (sf::Vector2f pos : m_segments)//sets electric aura first
		{
			sf::Vector2f Tpos = pos;
			Trectangle.setFillColor(sf::Color::Blue);
			Tpos.x -= 20;
			Tpos.y -= 20;
			Trectangle.setPosition(Tpos);
			window.draw(Trectangle);
		}
		for (sf::Vector2f pos : m_segments)//snake then ovverides relevant squares
		{
			rectangle.setFillColor(m_colour);
			rectangle.setPosition(pos);
			window.draw(rectangle);
		}
	}
	else
	{
		for (sf::Vector2f pos : m_segments)// render snake
		{
			rectangle.setFillColor(m_colour);
			rectangle.setPosition(pos);
			window.draw(rectangle);
		}
	}
}