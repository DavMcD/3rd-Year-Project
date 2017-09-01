#pragma once
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 
#include "Player.h"
#include "PlayerBullet.h"
#include "SFML/Audio.hpp"
#include "Enemy.h"
#include "player_bullet.hpp"
#include "npc.h"

class gameScreen : public cScreen
{
public:
	gameScreen();
	~gameScreen();
	virtual int gameScreen::Run(sf::RenderWindow &App);
	void gameScreen::reset();

private:
	sf::Vector2f gameScreen::normVec2f(sf::Vector2f vec);
	sf::Clock clock;
	sf::Clock enemyTimer;
	sf::Clock hurtTimer;
	sf::Texture texture;
	sf::Texture bgTexture;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::Sprite bgSprite;
	Player myPlayer;
	npc oldMan;
	sf::IntRect rectSourceSprite;
	sf::Sprite sprite;
	std::vector<Enemy> enemies;
	std::vector<StrongBullet> sBullets;
	sf::Music gameMusic;
	sf::SoundBuffer bufferF;
	sf::Sound fireS;
	sf::SoundBuffer bufferH;
	sf::Sound hurtS;
	sf::SoundBuffer bufferPlayerH;
	sf::Sound hurtPlayer;
	sf::Event Event;
	sf::Font myFont;
	sf::Text scoreText;
	sf::Text livesText;
	sf::Text warningText;
	sf::Clock npcTimer;
	bool Running;
	bool mouseClicked;
	float enemySpawnRate;
	int score;
	int lives;
	int warnings;
	float npcSpawn;
	float npcDeath;

};

