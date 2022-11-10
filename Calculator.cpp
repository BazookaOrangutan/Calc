

#include "Calculator.h"
#include "SetProject.h"
#include <iostream>


Calculator::Calculator() : window(sf::VideoMode(WIDTH_W, HIGHT_W), "Calculator")
{
	createKeyboard();
	createField();
}

void Calculator::run()
{
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Calculator::processEvents()
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					if (keyboard[i][j]->intersects(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
						keyboard[i][j]->setColor(sf::Color(125, 125, 125, 230));
						lastBtn = keyboard[i][j];
					}
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
			lastBtn->setColor(buttonBack);
			if (lastBtn->intersects(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
				std::string text = lastBtn->getText().getString();
				std::cout << text;
				if (lastBtn->getText().getString() == "C") {
					field->setText("");
				}
				else {
					field->setText(field->getString() + lastBtn->getText().getString());
				}
			}
		}
	}

}

void Calculator::update()
{
}

void Calculator::render()
{
	window.clear();
	for (int i = 0;i < row;i++) {
		for (int j = 0; j < column;j++) {
			keyboard[i][j]->draw(window);
		}
	}
	field -> draw(window);
	window.display();
}

void Calculator::createKeyboard()
{
	int btnH = (HIGHT_W - fieldSize) / row;
	int btnW = WIDTH_W / column;
	keyboard = new Button * *[row];
	for (int i = 0; i < row;i++) {
		keyboard[i] = new Button * [column];
		for (int j = 0; j < column; j++) {
			keyboard[i][j] = new Button(btnW, btnH, keySymbol[i][j], buttonBack,colorOutline, colorText, 20);
			keyboard[i][j]->setPosition(btnW * j, btnH * i + fieldSize);

		}
	}

}

void Calculator::createField()
{
	field = new Field(sf::Vector2f(0, 0), sf::Vector2f(400, 100), "", buttonBack, colorText, 50);
}

