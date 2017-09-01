#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
class Enemy
{
public:
	Enemy(sf::Vector2f player, sf::Sprite tex);
	~Enemy();
	void drawEnemy(sf::RenderWindow &window);
	bool collide(sf::Vector2f pt);
	bool active = true;
	sf::Vector2f getEnemyPosition();
	void move(float x, float y);
	float speed;
	sf::Vector2f getEnemyCentre();
private:
	sf::Vector2f pos;
	//sf::RectangleShape enemyImg;
	//sf::Texture eTexture;
	sf::Sprite eSpr;
};

