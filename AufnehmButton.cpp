#include "AufnehmButton.h"
#include "App.h"

AufnehmButton::AufnehmButton(App &app, sf::Vector2f pos, sf::Vector2f size) : Button(pos, "Aufnehmen", size, sf::Color::Black, sf::Color::White), m_app(app)
{
}


AufnehmButton::~AufnehmButton(void)
{
}

bool AufnehmButton::onMousePressed(sf::Vector2i pos)
{
	if(GuiElement::onMousePressed(pos))
	{
		m_app.toggleAufnahme();
		return true;
	}
}
