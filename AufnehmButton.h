#pragma once
#include "Button.h"

class App;

class AufnehmButton :
	public Button
{
private:
	App &m_app;
public:
	AufnehmButton(App &app, sf::Vector2f pos, sf::Vector2f size);
	~AufnehmButton(void);
	bool onMousePressed(sf::Vector2i pos) override;
};

