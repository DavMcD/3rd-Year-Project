#include "stdafx.h"
#include "gameOverScreen.h"


gameOverScreen::gameOverScreen()
{
	bufferF.loadFromFile("loss.wav");
	sound.setBuffer(bufferF);
}


gameOverScreen::~gameOverScreen()
{
}

int gameOverScreen::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	sf::Font myFont;
	myFont.loadFromFile("segoepr.ttf");
	sf::Text text;
	sf::Text Menu1;
	sf::Text Menu2;


	text.rotate(-5);
	text.setPosition(50, 100);

	Menu1.setFont(myFont);
	Menu1.setCharacterSize(40);
	Menu1.setString("Main Menu");
	Menu1.setPosition({ 280.f, 260.f });
	Menu1.setRotation(-5);

	Menu2.setFont(myFont);
	Menu2.setCharacterSize(40);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280.f, 320.f });
	Menu2.setRotation(-5);
	int menu = 0;
	bool Running = true;

	bufferH.loadFromFile("Select.wav");
	selectS.setBuffer(bufferH);

	bufferE.loadFromFile("Enter.wav");
	enterS.setBuffer(bufferE);

	sound.play();
	while (Running)
	{
		while (App.pollEvent(Event))
		{
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				App.close();

			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::W))
			{
				if (menu > 0)

				{
					menu--;
					selectS.play();
				}
			}
			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::S))
			{
				if (menu < 1)
				{
					menu++;
					selectS.play();
				}
			}
			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::Return))
			{
				enterS.play();

				if (menu == 0)
				{
					return(0);
				}
				else if (menu == 1)
				{
					App.close();
				}
			}

			break;
		}


		Menu1.setFillColor(sf::Color::White);
		Menu1.setStyle(sf::Text::Regular);
		Menu2.setFillColor(sf::Color::White);
		Menu2.setStyle(sf::Text::Regular);

		if (menu == 0)
		{
			Menu1.setFillColor(sf::Color::Red);
			Menu1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		}
		else if (menu == 1)
		{
			Menu2.setFillColor(sf::Color::Red);
			Menu2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		}

		App.clear();
		text.setFont(myFont); // font is a sf::Font

							  // set the string to display
		text.setString("Game Over");

		// set the character size
		text.setCharacterSize(104); // in pixels, not points!

									// set the color
		text.setFillColor(sf::Color::White);

		// set the text style
		text.setStyle(sf::Text::Bold);

		App.draw(text);
		App.draw(Menu1);
		App.draw(Menu2);
		App.display();
	}

	return (-1);
}
