#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Snake;
class Collectable;

class Game
{
private:
	int m_ScreenWidth{ 800 };
	int m_ScreenHeight{ 800 };
    std::vector<Snake*>m_snakes;
	std::vector<Collectable*> m_collectableVector;
public:
	void Run();
	void Collision();
	void Dead();
};
