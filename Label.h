#pragma once
#include <SFML/Graphics.hpp>
#include "GuiElement.h"

class Label : public GuiElement
{
private:
	sf::Text text;
	sf::Font font;
public:
	Label(sf::Vector2f pos, sf::Vector2f size, std::string string, sf::Color backC, sf::Color textC);
	~Label(void);
	void draw(sf::RenderWindow &window) override;
	void setString(std::string string);
	sf::String getString();
};

