#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class DeathScreen
{
private:
	int m_ScreenWidth{ 800 };
	int m_ScreenHeight{ 800 };
public:
	void Run(int Score);
};

