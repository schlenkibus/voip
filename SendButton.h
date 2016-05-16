#pragma once
#include "Button.h"
class SendButton :
	public Button
{
public:
	SendButton(sf::Vector2f pos, sf::Vector2f size);
	~SendButton(void);
};
