#pragma once
#include "SFML\Graphics.hpp"
#include "Label.h"

class Button : public Label
{
public:
	Button(sf::Vector2f pos, sf::String textS, sf::Vector2f size, sf::Color textC, sf::Color buttonC);
	~Button(void);
	/*bool isClicked(sf::RenderWindow &window);
	void isHover(sf::RenderWindow &window);
	void setText(std::string s);
	bool isEnabled();
	void setEnabled(bool x);
	*/
};

