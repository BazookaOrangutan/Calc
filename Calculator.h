#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Field.h"


class Calculator
{
	sf::RenderWindow window;
	sf::Event event;
	Button* btn = nullptr;
	Button*** keyboard = nullptr;
	Field* field;
	sf::Color buttonBack = sf::Color(100, 100, 100, 255);
	sf::Color colorOutline = sf::Color(0, 0, 0, 255);
	sf::Color colorText = sf::Color(255, 255, 255, 255);
	int fieldSize = 100;
	int row = 5;
	Button* lastBtn;
	int column = 4;
	std::string keySymbol[5][4] = {{"X^n", "+/-", "sqrt(n)", "="},
								   {"7", "8", "9", "+"},
								   {"4", "5", "6", "-"},
								   {"1", "2", "3", "*"},
								   {"C", "0", ".", "/"}};
public:
	Calculator();
	void run();
	void processEvents();
	void update();
	void render();
private:
	void createKeyboard();
	void createField();
};

