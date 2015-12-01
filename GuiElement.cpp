#include "GuiElement.h"


GuiElement::GuiElement(sf::Vector2f pos, sf::Vector2f size, sf::Color backC)
{
	clicked = false;
	enabled = true;
	shape.setPosition(pos);
	shape.setSize(size);
	shape.setFillColor(backC);
}


GuiElement::~GuiElement(void)
{
}

void GuiElement::draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

bool GuiElement::onMousePressed(sf::Vector2i pos)
{
	if(shape.getGlobalBounds().contains(pos.x, pos.y))
		return true;
	else
		return false;
}

bool GuiElement::onMouseReleased(sf::RenderWindow &window)
{
	return false;
}

bool GuiElement::textEntered(sf::Event &event)
{
	return false;
}