#pragma once
#include <SFML\Graphics.hpp>
class npc
{
public:
	npc();
	~npc();
	void draw(sf::RenderWindow &window);
	void reset();
	bool collide(sf::Vector2f pt);
	bool getActive();
	void setActive(bool setVar);
	void setVun(bool setVar);
private:
	sf::Vector2f pos;
	sf::Texture imgText;
	sf::Sprite img;
	sf::Clock clk;
	bool active;
	bool vunrable;
	float timeAlive;
};

