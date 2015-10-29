#pragma once
#include "button.h"
#include "App.h"
class ServerButton :
	public Button
{
private:
	App m_app;
public:
	ServerButton(sf::Vector2f pos, sf::Vector2f size);
	~ServerButton(void);
	bool onMousePressed(sf::Vector2i pos) override;
};

