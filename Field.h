#pragma once
#include <SFML/Graphics.hpp>

class Field
{
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color textColor;
	sf::Color backColor;
	sf::Color outlineColor;
	int outlineThickness;
	int charecterSize;
public:
	Field(sf::Vector2f position, sf::Vector2f size, std::string str, sf::Color colorBgr, sf::Color colorText, int sizeText);
	void setText(std::string text);
	void draw(sf::RenderWindow& window);
	sf::Text& getText();
	sf::RectangleShape& getRectangle();
	void setPosition(sf::Vector2f pos);
	bool intersects(sf::Vector2f mouse);
	void setColor(sf::Color color);
	std::string getString();
};


