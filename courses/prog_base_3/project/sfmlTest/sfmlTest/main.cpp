#include <SFML/Graphics.hpp>
#include <conio.h>

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(1600,900), "Test"); 

	Image fon; 
	fon.loadFromFile("images/fon.png");

	Texture fontexture;
	fontexture.loadFromImage(fon);

	Sprite fonsprite;
	fonsprite.setTexture(fontexture);
	fonsprite.setPosition(0, 0);

	Image spaceship;
	spaceship.loadFromFile("images/spaceship.png");

	Texture spaceshiptexture;
	spaceshiptexture.loadFromImage(spaceship);

	Sprite spaceshipsprite;
	spaceshipsprite.setTexture(spaceshiptexture);
	spaceshipsprite.setPosition(20, 40);
	int i = 0;
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(fonsprite);
		spaceshipsprite.setPosition(20 + i, 40);
		window.draw(spaceshipsprite);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Right)) i++;
	}
	return 0;
}