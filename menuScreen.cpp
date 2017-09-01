#include "stdafx.h"
#include "menuScreen.h"


menuScreen::menuScreen()
{
}


menuScreen::~menuScreen()
{
}

int menuScreen::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	sf::Font myFont;
	myFont.loadFromFile("segoepr.ttf");
	sf::Text text;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	sf::Clock clock;
	bool TitlePlay = true;
	int menu = 0;
	bool Running = true;

	texture.loadFromFile("TitleScreen.png");
	rectSourceSprite = sf::IntRect(2, 2, 135, 135);
	sprite = sf::Sprite(texture, rectSourceSprite);
	sprite.scale(5, 5);
	sprite.setPosition(515, 115);

	sf::Music menuMusic;
	menuMusic.openFromFile("menu_music.wav");
	menuMusic.play();

	Menu1.setFont(myFont);
	Menu1.setCharacterSize(40);
	Menu1.setString("Play");
	Menu1.setPosition({ 280.f, 260.f });
	Menu1.setRotation(-5);

	Menu2.setFont(myFont);
	Menu2.setCharacterSize(40);
	Menu2.setString("Options");
	Menu2.setPosition({ 280.f, 320.f });
	Menu2.setRotation(-5);

	Menu3.setFont(myFont);
	Menu3.setCharacterSize(40);
	Menu3.setString("Exit");
	Menu3.setPosition({ 280.f, 380.f });
	Menu3.setRotation(-5);

	bufferH.loadFromFile("Select.wav");
	selectS.setBuffer(bufferH);

	bufferE.loadFromFile("Enter.wav");
	enterS.setBuffer(bufferE);

	while (Running)
	{
		while (App.pollEvent(Event))
		{
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
			{
				menuMusic.stop();
				App.close();//closes app
			}


			//shortcuts to different scenes for debugging
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Num2))
				return(1); //number 2 brings you to the second of the scenes (which is 1 since we count from 0)

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Num3))
				return(2); //number 3 brings you to the third of the scenes (which is 2 since we count from 0)


			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::W) && !TitlePlay)
			{
				if (menu > 0)

				{
					menu--;
					selectS.play();
				}
			}
			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::S) && !TitlePlay)
			{
				if (menu < 2)
				{
					menu++;
					selectS.play();
				}
			}
			if ((Event.type == sf::Event::KeyReleased) && (Event.key.code == sf::Keyboard::Return))
			{
				enterS.play();
				if (TitlePlay)
				{
					TitlePlay = false;
				}
				else
				{
					if (menu == 0)
					{
						menuMusic.stop();
						return(1);
					}
					else if (menu == 1)
					{
						//menuMusic.stop();
					}
					else if (menu == 2)
					{
						menuMusic.stop();
						App.close();
					}
				}
			}

			break;
		}

		if (TitlePlay)
		{
			App.clear();
			App.draw(sprite);
			/*if (clock.getElapsedTime().asSeconds() > .5f) {
				if (rectSourceSprite.left == 64) {
					rectSourceSprite.left = 0;
				}
				else {
					rectSourceSprite.left += 32;
				}
				sprite.setTextureRect(rectSourceSprite);
				clock.restart();
				score++;
			}*/
			if (clock.getElapsedTime().asSeconds() > .2f) {
				if (rectSourceSprite.left >= 822) {
					rectSourceSprite.left = 2;
					rectSourceSprite.top += 137;
				}
				else {
					rectSourceSprite.left += 137;
				}
				sprite.setTextureRect(rectSourceSprite);
				clock.restart();
				if (rectSourceSprite.left >= 274 && rectSourceSprite.top >= 822)
				{
					TitlePlay = false;
				}
			}

		}
		else
		{
			Menu1.setFillColor(sf::Color::White);
			Menu1.setStyle(sf::Text::Regular);
			Menu2.setFillColor(sf::Color::White);
			Menu2.setStyle(sf::Text::Regular);
			Menu3.setFillColor(sf::Color::White);
			Menu3.setStyle(sf::Text::Regular);

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
			else if (menu == 2)
			{
				Menu3.setFillColor(sf::Color::Red);
				Menu3.setStyle(sf::Text::Bold | sf::Text::Underlined);
			}

			App.clear();
			text.setFont(myFont); // font is a sf::Font

								  // set the string to display
			text.setString("Main Menu");

			// set the character size
			text.setCharacterSize(104); // in pixels, not points!

										// set the color
			text.setFillColor(sf::Color::Blue);

			// set the text style
			text.setStyle(sf::Text::Bold);

			text.setRotation(-5);
			text.setPosition(50, 100);

			App.draw(text);
			App.draw(Menu1);
			App.draw(Menu2);
			App.draw(Menu3);
		}
		App.display();
	}

	return (-1);
}
