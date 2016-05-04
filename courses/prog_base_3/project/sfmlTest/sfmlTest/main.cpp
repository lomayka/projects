#include <SFML/Graphics.hpp>
#include <conio.h>
#include <string>
#include <iostream>
#include "PointF.h"
#include "SpaceShip.h"

using namespace sf;

class Planet{
private: PointF point;
public: std::string name;
public: Image images[60];
public: Texture textures[60];
public: Sprite sprites[60];
		Planet(std::string name,PointF point,int frameCount){
			this->name = name;
			this->point.x = point.x;
			this->point.y = point.y;
			for (int i = 1; i < frameCount; i++){
				std::string num = std::to_string(i);
				this->name = name;
				std::string str = "images/Planets/" + name + "/" + num + ".png";
				this->images[i].loadFromFile(str);
				this->textures[i].loadFromImage(this->images[i]);
				this->sprites[i].setTexture(this->textures[i]);
				this->sprites[i].setPosition(this->point.x, this->point.y);
			}
		}

public: PointF getCoord(){
			return this->point;
}

};


int main()
{
	RenderWindow window(VideoMode(1600,900), "Test");
	//PointF point = new PointF(100, 100);
	PointF point(400,400);
	Planet planet("Planet1", point, 60);
	
	Texture fon;
	Sprite fonsprite;
	fon.loadFromFile("images/fon.png");
	fonsprite.setTexture(fon);
	PointF spaceshipPoint(20, 20);
	SpaceShip myspaceShip("spaceship", spaceshipPoint);


	
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//window.clear();
		
		for (int i = 1; i < 60; i++){
			for (int j = 0; j < 1000; j++){
				window.draw(fonsprite);
				window.draw(planet.sprites[i]);
				window.draw(myspaceShip.sprite);
				window.display();
			}
			
		}
	}
	return 0;
}