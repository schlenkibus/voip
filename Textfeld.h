#pragma once
#include "SFML\Graphics.hpp"
#include "Label.h"

class App;

class Textfeld : public Label 
{
private: 
	App &m_app;
public:
	Textfeld(App &app, sf::Vector2f pos, sf::Vector2f size, sf::Color backColor, sf::Color textColor);
	~Textfeld(void);
	bool textEntered(sf::Event &event);
	void updateString(std::string &string);
};

