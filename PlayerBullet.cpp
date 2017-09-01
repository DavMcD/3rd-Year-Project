#include "stdafx.h"
#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(sf::Vector2f p, sf::Vector2f d) : pos(p), direction(d)
{
	bulletImg.setPosition(pos);
	bulletImg.setRadius(5);
	bulletImg.setFillColor(sf::Color::White);
}


PlayerBullet::~PlayerBullet()
{
}

PlayerBullet::PlayerBullet()
{
}

void PlayerBullet::drawBullet(sf::RenderWindow &window)
{
	pos = bulletImg.getPosition();
	bulletImg.move(direction);
	window.draw(bulletImg);
}

bool PlayerBullet::inBounds()
{
	if (bulletImg.getPosition().x < 0 || bulletImg.getPosition().y < 0 || bulletImg.getPosition().x > 1200 || bulletImg.getPosition().y > 800)
	{
		return false;
	}
	return true;
}
