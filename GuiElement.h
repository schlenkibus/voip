#pragma once
#include "SFML\Graphics.hpp"

class GuiElement
{
private:
	sf::RectangleShape shape;
	bool clicked, enabled;
public:
	GuiElement(sf::Vector2f pos, sf::Vector2f size, sf::Color backC);
	~GuiElement(void);
	virtual void draw(sf::RenderWindow &window);
	virtual bool onMousePressed(sf::Vector2i pos);
	virtual bool onMouseReleased(sf::RenderWindow &window);
	virtual bool textEntered(sf::Event &event);
};