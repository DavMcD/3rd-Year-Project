#pragma once
#include <SFML\Graphics.hpp>

class StrongBullet {
public:
	sf::Vector2f pos;
	sf::Vector2f direction;
	sf::CircleShape bulletImg;
	bool active = true;
	
	StrongBullet(sf::Vector2f p, sf::Vector2f d) {
		pos = p;
		direction = d;

		bulletImg.setPosition(pos);
		bulletImg.setFillColor(sf::Color::White);
		bulletImg.setRadius(5);
	}
	~StrongBullet(){}

	bool onScreen() {
		if (pos.x < 0 || pos.y < 0 || pos.x > 1200 || pos.y > 800)
			return false;
		return true;
	}
	bool collide(sf::Vector2f pt) {

	}
	void draw(sf::RenderWindow &window) {
		pos = bulletImg.getPosition();
		bulletImg.move(direction);
		window.draw(bulletImg);
	}


};