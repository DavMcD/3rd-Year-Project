#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(sf::Vector2f player, sf::Sprite tex)
{
	pos = sf::Vector2f(rand() % 835, rand() % 670);
	pos = pos + sf::Vector2f(290, 60);
	sf::Vector2f temp = pos + sf::Vector2f(25, 100);
	temp = temp - player;
	while (sqrt(temp.x*temp.x + temp.y * temp.y) < 300)//code to make sure they dont spawn near the player
	{
		pos = sf::Vector2f(rand() % 835, rand() % 670);
		pos = pos + sf::Vector2f(290, 60);
		temp = pos + sf::Vector2f(25, 100);
		temp = temp - player;
	}
	//sf::Texture texsd = sf::Texture()
	//eTexture = tex;

	eSpr = tex;
	//enemyImg = sf::Sprite(tex);
	eSpr.setScale(0.25, 0.25);
	
	eSpr.setOrigin(100, 100);
	eSpr.setPosition(pos);
	//enemyImg.setFillColor(sf::Color::Red);
	//enemyImg.setSize(sf::Vector2f(40, 100));

	speed = 1 + (((rand() % 9) - 5) / 10.0f);//random number between 0.8 and 1.2
}

void Enemy::move(float x, float y)
{
	pos.x = x * speed;
	pos.y = y * speed;

	float rotation = (atan2(pos.y, pos.x)) * 180 / 3.14159;
	//rotation += 180;

	eSpr.setRotation(rotation);

	eSpr.move(pos);
}

sf::Vector2f Enemy::getEnemyPosition()
{
	return (eSpr.getPosition());
}

sf::Vector2f Enemy::getEnemyCentre()
{
	return (sf::Vector2f(eSpr.getPosition().x, eSpr.getPosition().y));
}


void Enemy::drawEnemy(sf::RenderWindow &window)
{
	window.draw(eSpr);
}

bool Enemy::collide(sf::Vector2f pt)
{
	if (pt.x > eSpr.getPosition().x - 20 && pt.x < eSpr.getPosition().x + 20 && pt.y > eSpr.getPosition().y -20 && pt.y < eSpr.getPosition().y + 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Enemy::~Enemy()
{
}
