#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
class Player
{
public:
	Player();	
	Player(std::string imgDirectory, sf::Clock clk);
	void drawPlayer(sf::RenderWindow &window);
	void changeColour();
	void resetColour();
	void movePlayer(char direction, float moveSpeed);
	sf::Vector2f getPlayerPosition();
	void setPlayerPosition(sf::Vector2f nPos);
	bool collide(sf::Vector2f pt);

private:
	sf::Clock pClock;
	sf::Texture pTexture;
	sf::Sprite pSprite;
	sf::IntRect pRectSourceSprite;
};

