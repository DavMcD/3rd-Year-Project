#include "stdafx.h"
#include "gameScreen.h"

using namespace std;

gameScreen::gameScreen() : myPlayer("player2.png", clock)
{

	texture.loadFromFile("player2.png");
	rectSourceSprite = sf::IntRect(0, 0, 32, 32);
	sprite = sf::Sprite(texture, rectSourceSprite);
	bgTexture.loadFromFile("background.png");
	enemyTexture.loadFromFile("enemy.png");
	enemySprite = sf::Sprite(enemyTexture);
	//enemyTexture = sf::Texture();
	bgSprite = sf::Sprite(bgTexture);
	bgSprite.setScale(1.5, 1.231);
	//myPlayer = new Player("player.png", clock);
}


gameScreen::~gameScreen()
{
}

int gameScreen::Run(sf::RenderWindow &App)
{

	sf::Sprite tester(enemyTexture);
	//("player.png", clock); 
	//sf::IntRect rectSourceSprite(0, 0, 32, 32);
	//sf::Sprite sprite(texture, rectSourceSprite);

	//std::vector<PlayerBullet> pBullets;
	//std::vector<Enemy> enemies;
	//std::vector<StrongBullet> sBullets;

	
	//gameMusic.openFromFile("game_music.wav");
	//gameMusic.play();

	//bufferF.loadFromFile("fire.wav");
	//fireS.setBuffer(bufferF);
	//bufferH.loadFromFile("Hurt.wav");
	//hurtS.setBuffer(bufferH);

	//
	//myFont.loadFromFile("segoepr.ttf");
	//scoreText.setFont(myFont); //score text logic
	//scoreText.setCharacterSize(28);
	//scoreText.setFillColor(sf::Color::Red);// set the color
	//scoreText.setPosition(sf::Vector2f(0, 10));
	//scoreText.setRotation(-5);
	//livesText.setFont(myFont); //score text logic
	//livesText.setCharacterSize(28);
	//livesText.setFillColor(sf::Color::Red);// set the color
	//livesText.setPosition(sf::Vector2f(200, 10));
	//livesText.setRotation(-5);

	//Running = true;
	//mouseClicked = false;
	//enemySpawnRate = 7.0f;
	//score = 0;
	//lives = 5;

	reset();
	while (Running)
	{
		
		if (clock.getElapsedTime().asSeconds() > .5f) {
			if (rectSourceSprite.left == 64) {
				rectSourceSprite.left = 0;
			}
			else {
				rectSourceSprite.left += 32;
			}
			sprite.setTextureRect(rectSourceSprite);
			clock.restart();
			score++;
		}

		if (enemyTimer.getElapsedTime().asSeconds() > enemySpawnRate)
		{
			enemies.push_back(Enemy(myPlayer.getPlayerPosition(), enemySprite));
			if(enemySpawnRate>0.35)
				enemySpawnRate = enemySpawnRate * 0.9;
			enemyTimer.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && myPlayer.getPlayerPosition().y > 60) {
			myPlayer.movePlayer('u', 0.2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && myPlayer.getPlayerPosition().y < 730) {
			myPlayer.movePlayer('d', 0.2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && myPlayer.getPlayerPosition().x > 295) {
			myPlayer.movePlayer('l', 0.2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && myPlayer.getPlayerPosition().x < 1125) {
			myPlayer.movePlayer('r', 0.2);
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//this is logic for on mouse release since that is not a function
		{
			mouseClicked = true;
		}
		else
		{
			if (mouseClicked == true)
			{
				//create bullet based on the direction clicked and player location
				sf::Vector2f temp = sf::Vector2f(sf::Mouse::getPosition().x - myPlayer.getPlayerPosition().x - 200, sf::Mouse::getPosition().y - myPlayer.getPlayerPosition().y - 80);
				//pBullets.push_back(PlayerBullet(myPlayer.getPlayerPosition(), normVec2f(temp)));
				sBullets.push_back(StrongBullet(myPlayer.getPlayerPosition(), normVec2f(temp)));
				mouseClicked = false;
				fireS.play();
			}
		}

		while (App.pollEvent(Event))
		{
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
			{
				gameMusic.stop();
				App.close();
			}

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Num1))
				return(0); //number 1 brings you to the first of the scenes (which is 0 since we count from 0)

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Num3))
				return(2); //number 3 brings you to the third of the scenes (which is 2 since we count from 0)

			break;
		}

		App.clear();
		App.draw(bgSprite);
		//App.draw(tester);

		//for (std::vector<PlayerBullet>::iterator iter = pBullets.begin(); 
		
		//Loop over all bullets
		for (std::vector<StrongBullet>::iterator bulletIter = sBullets.begin();
			bulletIter != sBullets.end(); bulletIter++) 
		{
			//Check for Collision with enemies
			for (std::vector<Enemy>::iterator eIter = enemies.begin();
				eIter != enemies.end(); eIter++) 
			{
				
				//If they Collide
				if ((*eIter).collide((*bulletIter).pos)) {
					//Set both to inactive
					(*eIter).active = false;
					(*bulletIter).active = false;
					hurtS.play();
					score += 50;
				}
			}
			if (oldMan.collide((*bulletIter).pos))
			{
				(*bulletIter).active = false;
				oldMan.reset();
				npcTimer.restart();
				warnings--;
			}

			if (!(*bulletIter).onScreen())
				(*bulletIter).active = false;
		}

		int i = 0;
		/*
		while ( i < pBullets.size())
		{
			for (int it = 0; it < enemies.size();)
			{
				if (enemies[it].collide(pBullets[i].pos))
				{
					//enemies[it].~Enemy();
					//enemies.erase(enemies.begin() + it);
					enemies[it].active = false;
					hurtS.play();
					score += 50;
				}
				it++;
			}

			if (pBullets[i].inBounds() == false)
			{
				//(*iter).~PlayerBullet();
				//delete &iter;
				//pBullets.erase(pBullets.begin() + i);
				//erasing bullets makes the game crash
				pBullets[i].active = false;

			}
			else
			{
				if (pBullets[i].active)
				{
					pBullets[i].drawBullet(App);
				}
				//++i;
				//i++ should be here but the deletion code does not work so it has to be outside the if else or there is an endless loop
			}
			++i;
		}
		*/

		i = 0;
		while (i < enemies.size())
		{
			if (enemies[i].active)
			{
				enemies[i].drawEnemy(App);
			}

			sf::Vector2f temp = myPlayer.getPlayerPosition();
			temp = temp - enemies[i].getEnemyCentre();
			if (sqrt(temp.x*temp.x + temp.y*temp.y) < 25)//25 is half the enemy width, 16 is half the player width only using 20 to make the game forgiving
			{
				enemies[i].active = false;
				if (hurtTimer.getElapsedTime().asSeconds() >= 1.5)
				{
					hurtPlayer.play();
					lives--;
					hurtTimer.restart();
				}
				//lose a life code
			}
			i++;
		}

		if (lives < 5 && hurtTimer.getElapsedTime().asSeconds() <= 1.5)
		{
			myPlayer.changeColour();
		}
		else
		{
			myPlayer.resetColour();
		}

		if (lives == 0)
		{
			gameMusic.stop();
			return (2);
		}
		if (warnings == 0)
		{
			gameMusic.stop();
			return (2);
		}


		for (int i = 0; i < enemies.size(); i++)
		{
			float xDistance = myPlayer.getPlayerPosition().x - enemies[i].getEnemyCentre().x;
			float yDistance = myPlayer.getPlayerPosition().y - enemies[i].getEnemyCentre().y;

			float hypotenuse = sqrt((xDistance * xDistance) + (yDistance * yDistance));

			float xPos = 0;
			float yPos = 0;

			yPos += 0.17 * (yDistance / hypotenuse);
			xPos += 0.17 * (xDistance / hypotenuse);

			enemies[i].move(xPos, yPos);
		}

		//App.draw(sprite);
		myPlayer.drawPlayer(App);

		if (npcTimer.getElapsedTime().asSeconds() > npcSpawn)
		{
			oldMan.setActive(true);
			if (npcTimer.getElapsedTime().asSeconds() > npcSpawn + 0.5)
			{
				oldMan.setVun(true);
			}
		}
		if (npcTimer.getElapsedTime().asSeconds() > npcDeath)
		{
			oldMan.reset();
			npcTimer.restart();
		}

		if (oldMan.getActive())
			oldMan.draw(App);


		
		livesText.setString("Lives:\n   " + std::to_string(lives));
		warningText.setString("Strikes Left:\n   " + std::to_string(warnings));
		scoreText.setString("Score:\n   " + std::to_string(score));// set the string to display

		// set the text style
		//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		//Loop over all bullets
		for (std::vector<StrongBullet>::iterator bulletIter = sBullets.begin();
			bulletIter != sBullets.end(); bulletIter++) {
			(*bulletIter).draw(App);
		}
		App.draw(scoreText);
		App.draw(livesText);
		App.draw(warningText);
		App.display();

		//Garbage Collection, runs through all the vectors, checks for inactive and removes them from the std::vector
		enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Enemy e) { return !e.active; }), enemies.end());
		sBullets.erase(std::remove_if(sBullets.begin(), sBullets.end(), [](StrongBullet b) { return !b.active; }), sBullets.end());
	

	}

	return (-1);
}

void gameScreen::reset()
{
	myPlayer.setPlayerPosition(sf::Vector2f(500, 400));
	texture.loadFromFile("player2.png");
	rectSourceSprite = sf::IntRect(0, 0, 32, 32);
	sprite = sf::Sprite(texture, rectSourceSprite);

	gameMusic.openFromFile("game_music.wav");
	gameMusic.play();

	bufferF.loadFromFile("fire.wav");
	fireS.setBuffer(bufferF);
	bufferH.loadFromFile("Hurt.wav");
	hurtS.setBuffer(bufferH);
	bufferPlayerH.loadFromFile("PlayerHurt.wav");
	hurtPlayer.setBuffer(bufferPlayerH);


	myFont.loadFromFile("segoepr.ttf");
	scoreText.setFont(myFont); //score text logic
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(sf::Color::White);// set the color
	scoreText.setOutlineThickness(1);
	scoreText.setOutlineColor(sf::Color::Red);
	scoreText.setPosition(sf::Vector2f(0, 500));
	scoreText.setRotation(-5);

	livesText.setFont(myFont); //score text logic
	livesText.setCharacterSize(30);
	livesText.setOutlineThickness(1);
	livesText.setOutlineColor(sf::Color::Red);
	livesText.setFillColor(sf::Color::White);// set the color
	livesText.setPosition(sf::Vector2f(0, 200));
	livesText.setRotation(-5);

	warningText.setFont(myFont); //score text logic
	warningText.setCharacterSize(30);
	warningText.setOutlineThickness(1);
	warningText.setOutlineColor(sf::Color::Red);
	warningText.setFillColor(sf::Color::White);// set the color
	warningText.setPosition(sf::Vector2f(0, 350));
	warningText.setRotation(-5);

	sBullets.clear();
	enemies.clear();
	npcTimer.restart();
	warnings = 3;
	npcSpawn = 5 + rand() % 5;
	npcDeath = npcSpawn + 2 + rand() % 3;
	Running = true;
	mouseClicked = false;
	enemySpawnRate = 5.0f;
	score = 0;
	lives = 5;
}

sf::Vector2f gameScreen::normVec2f(sf::Vector2f vec)
{
	float magnitude = sqrt(vec.x*vec.x + vec.y*vec.y);
	return sf::Vector2f((vec.x/magnitude),(vec.y/magnitude));
}

