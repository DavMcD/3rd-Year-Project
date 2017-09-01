//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include "Screens.h"




////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
int main()
{
	//// Create the main window 
	//sf::RenderWindow myWindow(sf::VideoMode(800, 600), "SFML OpenGL");

	// Create a clock for measuring time elapsed     
	sf::Clock Clock;

	sf::Font myFont;
	myFont.loadFromFile("arial.ttf");
	sf::Text text;

	srand(time(NULL));

	std::vector<cScreen*> screensVec;
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(1200, 800, 32), "SFML Demo 3");


	//Screens preparations
	menuScreen s0;
	screensVec.push_back(&s0);
	gameScreen s1;
	screensVec.push_back(&s1);
	gameOverScreen s2;
	screensVec.push_back(&s2);

	//Main loop
	while (screen >= 0)
	{
		screen = screensVec[screen]->Run(App);
	}

	return EXIT_SUCCESS;


	//// Start game loop 
	//while (myWindow.isOpen())
	//{
	//	// Process events 
	//	sf::Event Event;
	//	while (myWindow.pollEvent(Event))
	//	{
	//		// Close window : exit 
	//		if (Event.type == sf::Event::Closed)
	//			myWindow.close();

	//		// Escape key : exit 
	//		if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
	//			myWindow.close();

	//		if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Z))
	//			MainMenu menu = new MainMenu(myWindow);


	//		

	//	}

		//Prepare for drawing 
		// Clear color and depth buffer 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//// Apply some transformations 
		//glMatrixMode(GL_MODELVIEW);
		//glLoadIdentity();

		//double angle = Clock.getElapsedTime().asMilliseconds();
		//glTranslated(+400, +300, 0); //shift to original position
		//glRotated(angle / 10, 0, 0, 1); // rotate
		//glTranslated(-400, -300, 0);// shift centre to origin


		text.setFont(myFont); // font is a sf::Font

		// set the string to display
		text.setString("Hello world");

		// set the character size
		text.setCharacterSize(104); // in pixels, not points!

		// set the color
		text.setOutlineColor(sf::Color::Blue);

		// set the text style
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		//myWindow.draw(text);

		// Finally, display rendered frame on screen 
		//myWindow.display();
	//}

	//return EXIT_SUCCESS;
}