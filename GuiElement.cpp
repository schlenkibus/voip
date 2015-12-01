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

<<<<<<< HEAD
bool GuiElement::isClicked(sf::RenderWindow &window)
{
	if(shape.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left) && enabled == true)
	{
		clicked = false;
		return true;
	}
	else
	{
		clicked = true;
		return false;
	}
}

=======
>>>>>>> 757e79f92fbe5f7a0aa0f3e1273ff7618603b18b
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