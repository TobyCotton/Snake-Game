#pragma once
#include <SFML/Graphics.hpp>
#include <list>
enum class EMovement
{
	eNorth,
	eEast,
	eSouth,
	eWest
};
class Snake
{
private:
	int m_score{ 0 };
	sf::Color m_colour{};
	bool m_alive{true};
	int m_grow{ 0 };
	bool m_electric{ false };
	int m_counter{ 40 };
	EMovement m_movement{ EMovement::eNorth };
	std::list<sf::Vector2f> m_segments;
public:
	Snake(sf::Vector2f pos,sf::Color colour);
	sf::Vector2f GetPosition();
	void Cannibal(std::vector<Snake*> snakes );
	int GetScore() const { return m_score; }
	bool IsAlive() const { return m_alive; }
	void Dead();
	void Electrify();
	void SetScore(int grow);
	void Update();
	void ChangeDirection(EMovement movement);
	void Render(sf::RenderWindow& window);
};

