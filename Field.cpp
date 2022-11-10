#include "Field.h"

Field::Field(sf::Vector2f position, sf::Vector2f size, std::string str, sf::Color colorBgr, sf::Color colorText, int sizeText)
{
	font.loadFromFile("src\\fonts\\arial.ttf");

	this->charecterSize = sizeText;
	this->size = size;
	rectangle.setSize(this->size);
	rectangle.setFillColor(colorBgr);
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
	text.setFont(font);
	text.setString(str);
	text.setFillColor(colorText);
	text.setCharacterSize(sizeText);
	setPosition(position);
}

void Field::setText(std::string text)
{
	this->text.setString(text);
	float x = this->position.x;
	float y = this->position.y;
	this->text.setPosition(x - this->charecterSize * this->text.getString().getSize() / 1.8 - 25 + size.x, y + (size.y - this->charecterSize) / 2.4);

}

sf::Text& Field::getText()
{
	return text;
}

sf::RectangleShape& Field::getRectangle()
{
	return rectangle;
}

void Field::setPosition(sf::Vector2f pos)
{
	this->position = pos;
	float x = pos.x;
	float y = pos.y;
	rectangle.setPosition(pos);
	text.setPosition(x - this->charecterSize * text.getString().getSize() / 1.8 - 15 + size.x, y + (size.y - this->charecterSize) / 2.4);
}

bool Field::intersects(sf::Vector2f mouse)
{
	float rX = rectangle.getPosition().x;
	float rY = rectangle.getPosition().y;
	float mX = mouse.x;
	float mY = mouse.y;
	float sX = rectangle.getSize().x;
	float sY = rectangle.getSize().y;
	return ((rX < mX&& mX < (rX + sX)) && ((rY < mY&& mY < (rY + sY))));
}

void Field::setColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

std::string Field::getString()
{
	return text.getString();
}

void Field::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(text);
}
