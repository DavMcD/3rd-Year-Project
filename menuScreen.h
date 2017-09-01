#pragma once
#include "cScreen.h"
#include "SFML/OpenGL.hpp" 
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
class menuScreen : public cScreen
{
public:
	menuScreen();
	~menuScreen();
	virtual int menuScreen::Run(sf::RenderWindow &App);
private:
	sf::SoundBuffer bufferH;
	sf::Sound selectS;
	sf::SoundBuffer bufferE;
	sf::Sound enterS;
	sf::IntRect rectSourceSprite;
	sf::Texture texture;
	sf::Sprite sprite;
};

