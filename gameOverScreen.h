#pragma once
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class gameOverScreen : public cScreen
{
public:
	gameOverScreen();
	~gameOverScreen();
	virtual int gameOverScreen::Run(sf::RenderWindow &App);
private:
	sf::SoundBuffer bufferF;
	sf::Sound sound;
	sf::SoundBuffer bufferH;
	sf::Sound selectS;
	sf::SoundBuffer bufferE;
	sf::Sound enterS;
};

