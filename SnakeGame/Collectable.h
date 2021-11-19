#pragma once
#include <SFML/Graphics.hpp>
class Collectable
{
private:
	bool m_alive{ false };
	int m_grow{rand() % 2 };
	bool m_electric{false};
	sf::Vector2f m_pos{};
public:
	bool IsAlive() const { return m_alive; }
	bool GetElectric() const { return m_electric; }
	int GetGrow() const { return m_grow; }
	void Dead();
	sf::Vector2f getRandomPosition();
	void Spawn(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
	sf::Vector2f GetPosition() const { return m_pos; };
};

