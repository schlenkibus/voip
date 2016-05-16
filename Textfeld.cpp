#include "Textfeld.h"
#include <SFML/Network.hpp>
#include "App.h"
#include <iostream>

Textfeld::Textfeld(App &app, sf::Vector2f pos, sf::Vector2f size, sf::Color backColor, sf::Color textColor) : Label(pos, size, "", backColor, textColor), m_app(app)
{

}


Textfeld::~Textfeld(void)
{
}

bool Textfeld::textEntered(sf::Event &event)
{
	if (event.type == sf::Event::TextEntered)
	{
		std::string string = getString();
		if(event.text.unicode == '\b')
		{
			if(!string.empty())
			{
				string.erase(string.size() - 1, 1);
				updateString(string);
			}
		}
		else if (event.text.unicode < 128)
		{
			string += static_cast<char>(event.text.unicode);
			updateString(string);	
		}
		return true;
		
	}
	return false;
}

void Textfeld::updateString(std::string &string)
{
	setString(string);
	m_app.setIP(string);
}