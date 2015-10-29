#include "ServerButton.h"


ServerButton::ServerButton(sf::Vector2f pos, sf::Vector2f size) : Button(pos, "Server starten", size, sf::Color::Black, sf::Color::White)
{
}


ServerButton::~ServerButton(void)
{
}

bool ServerButton::onMousePressed(sf::Vector2i pos)
{
	if(GuiElement::onMousePressed(pos))
	{

		return true;
	}
}
