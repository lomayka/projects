#include <SFML/Graphics.hpp>

using namespace sf;
int main()
{
	RenderWindow window(VideoMode(1600,900), "Test"); 

	Image heroimage; 
	heroimage.loadFromFile("images/fon.png");

	Texture herotexture;
	herotexture.loadFromImage(heroimage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setPosition(0, 0);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}