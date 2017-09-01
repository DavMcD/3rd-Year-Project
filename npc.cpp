#include "stdafx.h"
#include "npc.h"


npc::npc()
{

	pos = sf::Vector2f(rand() % 835, rand() % 670);
	pos = pos + sf::Vector2f(290, 60);

	imgText = sf::Texture();
	imgText.loadFromFile("oldman.png");
	img = sf::Sprite(imgText);
	img.setScale(0.8, 0.8);
	img.setPosition(pos);
	active = false;
	vunrable = false;
	//timeAlive = 3.5f;
}


npc::~npc()
{
}

void npc::draw(sf::RenderWindow &window)
{
	if (active)
		window.draw(img);
}

void npc::reset()
{
	pos = sf::Vector2f(rand() % 835, rand() % 670);
	pos = pos + sf::Vector2f(290, 60);
	img.setPosition(pos);
	active = false;
	vunrable = false;
}

bool npc::collide(sf::Vector2f pt)
{
	if (pt.x > img.getPosition().x && pt.x < img.getPosition().x + 48 && pt.y > img.getPosition().y && pt.y < img.getPosition().y + 84 && vunrable)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool npc::getActive()
{
	return active;
}

void npc::setActive(bool setVar)
{
	active = setVar;
}

void npc::setVun(bool setVar)
{
	vunrable = setVar;
}
