#include <SFML/Graphics.hpp>

using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
int main()
{
	RenderWindow window(sf::VideoMode(620, 420), "Lesson 3. kychka-pc.ru"); 

	Image heroimage; 
	heroimage.loadFromFile("images/fon.png");

	Texture herotexture;
	herotexture.loadFromImage(heroimage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(herosprite);//выводим спрайт на экран
		window.display();
	}

	return 0;
}