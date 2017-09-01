#pragma once
#include <SFML\Graphics.hpp>
class PlayerBullet
{
public:
	PlayerBullet(sf::Vector2f p, sf::Vector2f d);
	~PlayerBullet();
	
	PlayerBullet();
	sf::Vector2f pos;
	sf::Vector2f direction;
	const float speed = 2.0f;
	void drawBullet(sf::RenderWindow &window);
	bool inBounds();
	sf::CircleShape bulletImg;
	bool active = true;
private:
	bool privateB = true;
};

