#include "DeathScreen.h"
#include "Game.h"
#include <sstream>

void DeathScreen::Run(int TopScore)
{
	sf::RenderWindow window(sf::VideoMode(m_ScreenHeight, m_ScreenWidth), "C++ Snake ICA Main Menu: A0031189");
	sf::Event event;
	sf::Font arcade;
	sf::Text Title;
	sf::Text TopScoreTitle;
	sf::Text TopScoreNumber;
	sf::Text Play;
	sf::Text Highscore;
	sf::Text Exit;
	int test{ 0 };
	arcade.loadFromFile("PressStart2p-vaV7.ttf");
	Title.setFont(arcade);
	Title.setString("Game Over");
	Title.setCharacterSize(50);
	Title.setPosition(160, 200);
	Title.setFillColor(sf::Color::White);
	TopScoreTitle.setFont(arcade);
	TopScoreTitle.setString("Score:");
	TopScoreTitle.setCharacterSize(25);
	TopScoreTitle.setPosition(300, 400);
	TopScoreTitle.setFillColor(sf::Color::White);
	std::ostringstream oss;
	oss << TopScore;
	TopScoreNumber.setFont(arcade);
	TopScoreNumber.setString(oss.str());
	TopScoreNumber.setCharacterSize(25);
	TopScoreNumber.setPosition(450, 400);
	TopScoreNumber.setFillColor(sf::Color::White);
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
	//rendering all the buttons and titles^^
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

	
		window.clear(sf::Color::Black);
		window.draw(Title);
		window.draw(TopScoreTitle);
		window.draw(TopScoreNumber);
		window.draw(Play);
		window.draw(Exit);

		window.display();
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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//Exit button
		{
			if (sf::Mouse::getPosition(window).x > 600 && sf::Mouse::getPosition(window).x < 700)
			{
				if (sf::Mouse::getPosition(window).y < 650 && sf::Mouse::getPosition(window).y > 600)
				{
					window.close();
				}
			}
		}
	}
}
