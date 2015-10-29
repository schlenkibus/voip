#include "Label.h"


Label::Label(sf::Vector2f pos, sf::Vector2f size, std::string string, sf::Color backC, sf::Color textC) : GuiElement(pos, size, backC)
{
	font.loadFromFile("libelsuit.ttf");
	text.setColor(textC);
	text.setPosition(pos);
	text.setString(string);
	text.setFont(font);
}

Label::~Label(void)
{
}

sf::String Label::getString()
{
	//return "127.0.0.1";
	return text.getString();
}

void Label::draw(sf::RenderWindow &window)
{
	GuiElement::draw(window);
	window.draw(text);
}

void Label::setString(std::string string)
{
	text.setString(string);
}