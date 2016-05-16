#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Textfeld.h"
#include "Label.h"
#include <list>
#include <memory>
#include "AufnehmButton.h"
#include "App.h"


typedef std::shared_ptr<GuiElement> t_UiElement;
typedef std::list<t_UiElement> t_List;

int main()
{
	sf::RenderWindow window(sf::VideoMode(230, 130), "VOIP", sf::Style::Close);
	sf::Event event;
	window.setFramerateLimit(60);

	App app;

	AufnehmButton * aButton = new AufnehmButton(app, sf::Vector2f(10, 70), sf::Vector2f(100, 50));

	t_List UiElements;
	UiElements.emplace_back(aButton);
	UiElements.emplace_back(new Textfeld(app, sf::Vector2f(10, 10), sf::Vector2f(210, 50), sf::Color::White, sf::Color::Black));

	sf::Thread connector(&App::ConnectorW8, &app);
	connector.launch();
	
	app.setButton(aButton);

	//Main Loop
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i Pos = sf::Mouse::getPosition(window);
				for(auto u: UiElements)
				{
					if(u->onMousePressed(Pos) == true)
						break;
				}
			}
			if(event.type == sf::Event::Closed)
			{
				connector.terminate();
				window.close();
				exit(1);
			}
			if(event.type == sf::Event::TextEntered)
			{
				for(auto u: UiElements)
				{
					u->textEntered(event);
				}
			}
		}
		
		window.clear(sf::Color(175, 175, 175));
		
		for(auto u: UiElements)
		{
			u->draw(window);
		}

		window.display();
	}
}