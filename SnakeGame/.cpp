#include "Button.h"

Button::Button(sf::Font font, std::string message, int size, sf::Vector2f position, sf::Color colour)
{
	sf::Text Title;
	font.loadFromFile("PressStart2p-vaV7.ttf");
	Title.setFont(font);
	Title.setString(message);
	Title.setCharacterSize(size);
	Title.setPosition(position);
	Title.setFillColor(colour);
}
