#include "stdafx.h"
#include "Player.h"


Player::Player(std::string imgDirectory, sf::Clock clk) {

	pTexture.loadFromFile(imgDirectory);
	if (!pTexture.loadFromFile(imgDirectory)) {
		std::cerr << "Error\n";
	}

	pClock = clk;

	pRectSourceSprite.left = 0;
	pRectSourceSprite.top = 0;
	pRectSourceSprite.width = 32;
	pRectSourceSprite.height = 32;

	pSprite.setTexture(pTexture);
	pSprite.setTextureRect(pRectSourceSprite);
	pSprite.setPosition(500, 400);
	pSprite.setOrigin(16, 16);//make the origin the centre for rotations
}

void Player::drawPlayer(sf::RenderWindow &window) {


	//animation code for swapping between frames
	if (pClock.getElapsedTime().asSeconds() > .5f) {
		if (pRectSourceSprite.left == 64) {
			pRectSourceSprite.left = 0;
		}
		else {
			pRectSourceSprite.left += 32;
		}
		pSprite.setTextureRect(pRectSourceSprite);
		pClock.restart();
	}


	sf::Vector2f curPos = pSprite.getPosition();
	sf::Vector2i position = sf::Mouse::getPosition(window);

	float dx = curPos.x - position.x;
	float dy = curPos.y - position.y;

	float rotation = (atan2(dy, dx)) * 180 / 3.14159;
	rotation += 90;

	pSprite.setRotation(rotation);


	window.draw(pSprite);
}

void Player::changeColour()
{
	pSprite.setColor(sf::Color::Red);
}

void Player::resetColour()
{
	pSprite.setColor(sf::Color::White);
}

void Player::movePlayer(char direction, float moveSpeed) {
	if (direction == 'u') {
		pSprite.move(0, -moveSpeed);
	}
	else if (direction == 'd') {
		pSprite.move(0, moveSpeed);
	}
	else if (direction == 'l') {
		pSprite.move(-moveSpeed, 0);
	}
	else if (direction == 'r') {
		pSprite.move(moveSpeed, 0);
	}
}

sf::Vector2f Player::getPlayerPosition()
{
	return (pSprite.getPosition());
}

void Player::setPlayerPosition(sf::Vector2f nPos)
{
	pSprite.setPosition(nPos);
}

bool Player::collide(sf::Vector2f pt)
{
	if (pt.x > pSprite.getPosition().x && pt.x < pSprite.getPosition().x + 32 && pt.y > pSprite.getPosition().y  && pt.y < pSprite.getPosition().y + 32)
	{
		return true;
	}
	else
	{
		return false;
	}
}