#pragma once
#include <SFML/Graphics.hpp>

class Button
{
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
public:
	Button(float width, float height, std::string str, sf::Color colorBgr,sf::Color colorOutline, sf::Color colorText, int sizeText);
	void draw(sf::RenderWindow& window);
	sf::Text& getText();
	sf::RectangleShape& getRectangle();
	void setPosition(int x, int y);
	bool intersects(sf::Vector2f mouse);
	void setColor(sf::Color color);
};

