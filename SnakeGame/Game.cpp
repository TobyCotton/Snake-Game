#include "Game.h"
#include "Snake.h"
#include "DeathScreen.h"
#include "Collectable.h"
#include <sstream>

void Game::Run()
{
	int timer = 0;
	int Stimer = 90;
	int amount{ 0 };
    sf::RenderWindow window(sf::VideoMode(m_ScreenHeight, m_ScreenWidth), "C++ Snake ICA Game : A0031189");
    m_snakes.push_back(new Snake(sf::Vector2f(200, 400), sf::Color::Red));//Player 1
	m_snakes.push_back(new Snake(sf::Vector2f(600, 400), sf::Color::White));//Player 2
    sf::Event event;
	int alive{ 0 };

    for (int i = 0; i < 5; i++)//creating the 5 collectables
    {
        m_collectableVector.push_back(new Collectable());
    }

    sf::Clock clock;

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
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_snakes[0]->ChangeDirection(EMovement::eNorth);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_snakes[0]->ChangeDirection(EMovement::eWest);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_snakes[0]->ChangeDirection(EMovement::eSouth);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_snakes[0]->ChangeDirection(EMovement::eEast);
        }//controls for player 1^^
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_snakes[1]->ChangeDirection(EMovement::eNorth);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_snakes[1]->ChangeDirection(EMovement::eWest);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_snakes[1]->ChangeDirection(EMovement::eSouth);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_snakes[1]->ChangeDirection(EMovement::eEast);
		}//controls for player 2^^

        for (Snake* snake : m_snakes)//snake moving if they are alive
        {
			if (snake->IsAlive())
			{
				snake->Update();
			}
        }

        window.clear(sf::Color(180, 207, 236));
  
        if (rand() % 50 == 0)//collectable random spawning
        {
            for (Collectable* collectable : m_collectableVector)
            {
				bool foundDead{ false };//flag
                if (!collectable->IsAlive())
                {
					foundDead = true;
					bool FoundPosition{ true };
					do
					{
						sf::Vector2f pos = collectable->getRandomPosition();
						for (Collectable* collectableTwo : m_collectableVector)//checking for valid position colliding with collectables
						{
							if (collectableTwo->IsAlive())
							{
								if (collectableTwo->GetPosition() == collectable->GetPosition())
								{
									FoundPosition = false;
									break;
								}
							}
						}
						for (Snake* snake : m_snakes)//checking for valid position colliding with snakes
						{
							if (snake->IsAlive())
							{
								if (snake->GetPosition() == collectable->GetPosition())
								{
									FoundPosition = false;
									break;
								}
							}
						}
					} while (FoundPosition==false);
                    collectable->Spawn(window);
                }
				if (foundDead == true)
				{
					foundDead = false;
					break;
				}

            }
        }
		Collision();
		Dead();

		for (Snake* snake : m_snakes)//snake rendering if they are alive
		{
			if (snake->IsAlive())
			{
				snake->Render(window);//
			}
		}

		for (Collectable* collectable : m_collectableVector)//rendering collectables
		{
			if (collectable->IsAlive())
			{
				collectable->Render(window);
			}
		}

		for (Snake* snake : m_snakes)//Putting players scores to the screen
		{
			sf::Font arcade;
			sf::Text Score;
			arcade.loadFromFile("PressStart2p-vaV7.ttf");
			Score.setFont(arcade);
			Score.setString("Player ");
			Score.setCharacterSize(20);
			Score.setPosition(20, 25+(amount*20));
			Score.setFillColor(sf::Color::White);
			window.draw(Score);
			std::ostringstream oss;
			Score.setPosition(180, 25 + (amount * 20));
			amount++;
			oss << amount;
			Score.setString(oss.str());
			window.draw(Score);
			Score.setString(":");
			Score.setPosition(220, 25 + ((amount - 1) * 20));
			window.draw(Score);
			std::ostringstream Toss;
			Toss << snake->GetScore();
			Score.setString(Toss.str());
			Score.setPosition(240, 25 + ((amount - 1) * 20));
			window.draw(Score);
		}
		if (timer == 10)
		{
			timer = 0;
			Stimer--;
		}
		sf::Font arcade;
		sf::Text timeCount;
		arcade.loadFromFile("PressStart2p-vaV7.ttf");
		timeCount.setFont(arcade);
		std::ostringstream oss;
		oss << Stimer;
		timeCount.setString(oss.str());
		timeCount.setCharacterSize(30);
		timeCount.setFillColor(sf::Color::White);
		timeCount.setPosition(650, 25);
		window.draw(timeCount);
		amount = 0;
		int Best{ 0 };
        window.display();
		for (Snake* snake : m_snakes)//checking for alive snakes
		{
			if (snake->IsAlive())
			{
				alive++;
			}
		}
		if (alive == 1)//if only one snake wins that snake is the winner
		{
			for (Snake* snake : m_snakes)
			{
				if (snake->IsAlive())
				{
					if (Best < snake->GetScore())
					{
						Best = snake->GetScore();
					}
				}
				DeathScreen End;
				window.close();
				End.Run(Best);
			}
		}
		else if (alive == 0)//if theres a head on collision
		{
			for (Snake* snake : m_snakes)
			{
				if (Best <= snake->GetScore())
				{
					Best = snake->GetScore();
					std::cout << Best << "1\n";
				}
			}
			std::cout << Best << "2\n";
			DeathScreen End;
			window.close();
			End.Run(Best);
		}
		else if (Stimer == 0)
		{
			for (Snake* snake : m_snakes)
			{
				if (Best <= snake->GetScore())
				{
					Best = snake->GetScore();
				}
			}
			DeathScreen End;
			window.close();
			End.Run(Best);
		}
		else//resets counter if both alive
		{
			alive = 0;
		}


        while (clock.getElapsedTime().asMilliseconds() < 100);
		timer++;
        clock.restart();

    }
    for (Snake* snake : m_snakes)
    {
        delete snake;
    }
}

void Game::Collision()
{
	for (Collectable* collectable : m_collectableVector)
	{
		for (Snake* snake : m_snakes)
		{
			if (snake->IsAlive())
			{
				if (snake->GetPosition() == collectable->GetPosition())//checking if it collides with a collectable
				{
					if (collectable->GetElectric())// is it an electric one
					{
						snake->Electrify();
					}
					collectable->Dead();
					snake->SetScore(collectable->GetGrow());
				}
			}
			snake->Cannibal(m_snakes);// has a snake collided with it self or another snake
		}
	}
}

void Game::Dead()// checks if a snake has gone of the screen
{
	for (Snake* snake : m_snakes)
	{
		if (snake->IsAlive())
		{
			sf::Vector2f Tpos;
			Tpos = snake->GetPosition();
			if (Tpos.x < 0 || Tpos.y < 0 || Tpos.x > m_ScreenWidth-20 || Tpos.y > m_ScreenHeight-20)
			{
				snake->Dead();
			}
		}
	}
}
