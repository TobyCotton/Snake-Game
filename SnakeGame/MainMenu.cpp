#include "MainMenu.h"
#include "Game.h"

void MainMenu::Run()
{
	sf::RenderWindow window(sf::VideoMode(m_ScreenHeight, m_ScreenWidth), "C++ Snake ICA Main Menu: A0031189");
	sf::Event event;
	sf::Font arcade;
	sf::Text Title;
	sf::Text Play;
	sf::Text Highscore;
	sf::Text Exit;
	int test{0};
	arcade.loadFromFile("PressStart2p-vaV7.ttf");
	Title.setFont(arcade);
	Title.setString("Snake Game");
	Title.setCharacterSize(50);
	Title.setPosition(160, 200);
	Title.setFillColor(sf::Color::White);
	Play.setFont(arcade);
	Play.setString("Play");
	Play.setCharacterSize(25);
	Play.setPosition(100, 600);
	Play.setFillColor(sf::Color::White);
	Exit.setFont(arcade);
	Exit.setString("Exit");
	Exit.setCharacterSize(25);
	Exit.setPosition(600, 600);
	Exit.setFillColor(sf::Color::White);
	// creating all the buttons and titles for the main menu^^
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//Play button
		{
			if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 198)
			{
				if (sf::Mouse::getPosition(window).y < 650 && sf::Mouse::getPosition(window).y > 600)
				{
					window.close();
					Game aGame;
					aGame.Run();
				}
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))// Exit Button
		{
			if (sf::Mouse::getPosition(window).x > 600 && sf::Mouse::getPosition(window).x < 700)
			{
				if (sf::Mouse::getPosition(window).y < 650 && sf::Mouse::getPosition(window).y > 600)
				{
					window.close();
				}
			}
		}
		window.clear(sf::Color::Black);
		window.draw(Title);
		window.draw(Play);
		window.draw(Exit);


		window.display();
	}
}
