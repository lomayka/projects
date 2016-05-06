#include <SFML/Graphics.hpp>
#include <conio.h>
#include <string>
#include <iostream>
#include "PointF.h"
#include "SpaceShip.h"
#include "View.h"

using namespace sf;

class Planet{
private: PointF point;
public: std::string name;
        Image images[60];
        Texture textures[60];
        Sprite sprites[60];
		float angle;
		Planet(std::string name,PointF point,int frameCount){
			this->name = name;
			this->point.x = point.x;
			this->point.y = point.y;
			this->angle = 0;
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



public:	void move(float ){
			//float angle = 0.5;

			/*	if (this->point.x <=6500 && this->point.x >= 4800 && this->point.y <= 2300 && this->point.y >=1800){
					this->point.y += 0.15;
					for (int i = 0; i < 60; i++){
					this->sprites[i].setPosition(this->getCoord().x + angle / (this->getCoord().y - startPoint.y) * (this->getCoord().y - startPoint.y), this->getCoord().y + this->getCoord().y - startPoint.y);
					}
					this->point.x += angle / (this->getCoord().y - startPoint.y) * (this->getCoord().y - startPoint.y);
					}
					else
					{
					this->point.y += 0.15;
					for (int i = 0; i < 60; i++){
					this->sprites[i].setPosition(this->getCoord().x - angle / (this->getCoord().y - startPoint.y) * (this->getCoord().y - startPoint.y), this->getCoord().y + this->getCoord().y - startPoint.y);
					}
					this->point.x -= angle / (this->getCoord().y - startPoint.y) * (this->getCoord().y - startPoint.y);


					}*/  // дичь 

			this->point.x = 4800 + (cos(this->angle) * 1800);
			this->point.y = 3100 + (sin(this->angle) * 1800);
			for (int i = 0; i < 60; i++){
				this->sprites[i].setPosition(this->point.x, this->point.y);

			}
			this->angle = this->angle + 0.0002; 

}
};











int main()
{
	RenderWindow window(VideoMode(1600,900), "Test");
	view.reset(FloatRect(0, 0, 1600, 900));
	PointF point(4800,1800 );
	Planet planet("Planet1", point, 60);
	Clock clock;
	Clock clock1;

	
	Texture fon;
	Sprite fonsprite;
	fon.loadFromFile("images/globalFon.png");
	fonsprite.setTexture(fon);
	PointF spaceshipPoint(20, 20);
	SpaceShip myspaceShip("spaceship", spaceshipPoint);
	PointF spaceshipPoint1(20, 120);
	SpaceShip myspaceShip2("spaceship6", spaceshipPoint1);
	Time t = milliseconds(12);
	
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
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 400;
		
			for (int j = 0; j < 40; j++){
				float time1 = clock1.getElapsedTime().asMicroseconds();
				clock1.restart();
				time1= time1 / 200;
				
				window.draw(fonsprite);
				window.draw(planet.sprites[i]);
				window.draw(myspaceShip.sprite);
				window.draw(myspaceShip2.sprite);
				window.display();
				window.setView(view);
				window.clear();
				
					planet.move(time1);
					
				viewmap(time1);
			  
				sleep(t);

			}
			
			
			
			
		}
		
	}
	return 0;
}