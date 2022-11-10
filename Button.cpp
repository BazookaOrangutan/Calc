#include "Button.h"

Button::Button(float width, float height, std::string str, sf::Color colorBgr,sf::Color colorOutline, sf::Color colorText, int sizeText) :
	rectangle(sf::Vector2f(width, height))
{
	font.loadFromFile("src\\fonts\\arial.ttf");
	rectangle.setFillColor(colorBgr);
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(colorOutline);
	text.setFont(font);
	text.setString(str);
	text.setFillColor(colorText);
	text.setCharacterSize(sizeText);
}

sf::Text& Button::getText()
{
	return text;
}

sf::RectangleShape& Button::getRectangle()
{
	return rectangle;
}

void Button::setPosition(int x, int y)
{
	int bh = rectangle.getSize().y;
	int bw = rectangle.getSize().x;
	rectangle.setPosition(x, y);
	int s = text.getString().getSize(); // symbol count
	int f = text.getCharacterSize(); // font size
	text.setPosition(x + bw / 2 - (s * f / 5), y + (bh - f) / 2);
}

bool Button::intersects(sf::Vector2f mouse)
{
	float rX = rectangle.getPosition().x;
	float rY = rectangle.getPosition().y;
	float mX = mouse.x;
	float mY = mouse.y;
	float sX = rectangle.getSize().x; 
	float sY = rectangle.getSize().y;
	return ((rX < mX && mX < (rX + sX)) && ((rY < mY && mY < (rY + sY))));
}

void Button::setColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(text);
}



