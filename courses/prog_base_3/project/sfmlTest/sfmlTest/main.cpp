#include <SFML/Graphics.hpp>
#include <conio.h>
#include <string>
#include <iostream>
#include "PointF.h"
#include "SpaceShip.h"
#include "View.h"
#include "Star.h"
#include "Pirate.h"
#define Pi 3.14159265

using namespace sf;

class Planet{
private: PointF point;
public: std::string name;
        Image images[60];
        Texture textures[60];
        Sprite sprites[60];
		float angle;
		Planet(std::string name,PointF point,int frameCount,float startAngle){
			this->name = name;
			this->point.x = point.x;
			this->point.y = point.y;
			this->angle = startAngle;
			for (int i = 1; i < frameCount; i++){
				std::string num = std::to_string(i);
				this->name = name;
				std::string str = "../sfmlTest/images/Planets/" + name + "/" + num + ".png";
				this->images[i].loadFromFile(str);
				this->textures[i].loadFromImage(this->images[i]);
				this->sprites[i].setTexture(this->textures[i]);
				this->sprites[i].setPosition(this->point.x, this->point.y);
				this->sprites[i].setRotation(20);
			}
		}

public: PointF getCoord(){
                return this->point;
}



public:	void move(PointF center, int rad){

			this->point.x = center.x + (cos(this->angle) * rad);
			this->point.y = center.y + (sin(this->angle) * rad);
			for (int i = 0; i < 60; i++){
				this->sprites[i].setPosition(this->point.x, this->point.y);

			}
			this->angle = this->angle + 0.0002; 

}
};



int main()
{
	RenderWindow window(VideoMode(1920,1080), "Test");
	view.reset(FloatRect(0, 0, 1920, 1080));
	PointF point(4300,1900 );
	Planet planet("Planet1", point, 60,270);
	PointF point1(4800, 1500);
	Planet planet1("Planet2", point1, 60,500);
	Clock clock;
	Clock clock1;

	
	Texture fon;
	Sprite fonsprite;
	fon.loadFromFile("../sfmlTest/images/gFon.png");
	fonsprite.setTexture(fon);
	
	PointF spaceshipPoint1(20, 120);
	SpaceShip myspaceShip2("spaceship6", spaceshipPoint1);
	PointF sunPosition(6400, 3600);
	Star sun(sunPosition, "sun");
	Time t = milliseconds(12);

    int tempX = 0;
	int tempY = 0;
	float distance = 0;
	float rotation = 0;
	float tempAngle = 0;
	PointF center(6400,3600);
	
	planet.move(center, 1500);

	SpaceShip myspaceShip("spaceship1", planet.getCoord());
	Pirate p("spaceship6", sunPosition);
	view = getplayercoordinateforview(myspaceShip.getSpaceShipPosition());

	while (window.isOpen())
	{
		
		
		Event event;

		for (int i = 1; i < 60; i++){
			
		
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 400;

		
			for (int j = 0; j < 40; j++){
				Vector2i pixelPos = Mouse::getPosition(window);
				Vector2f pos = window.mapPixelToCoords(pixelPos);
				float time1 = clock1.getElapsedTime().asMicroseconds();
				clock1.restart();
				time1= time1 / 200;
				
				
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
					if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left && myspaceShip.getMove() == false){
						myspaceShip.setMove(true);
						myspaceShip.setRotate(true);
						tempAngle = myspaceShip.getCurrAngle();
						tempX = pos.x;
						tempY = pos.y;
						float dX = pos.x - myspaceShip.getSpaceShipPosition().x;
						float dY = pos.y - myspaceShip.getSpaceShipPosition().y;
						rotation = (atan2(dY, dX)) * 180 / Pi;
						myspaceShip.setCurrAngle(rotation);
	                    
						
					}
					if (event.key.code == Mouse::Right && myspaceShip.getMove() == true || event.key.code == Mouse::Right && myspaceShip.getRotate() == true){
						myspaceShip.setMove(false);
						myspaceShip.setRotate(false);
						myspaceShip.setCurrAngle(tempAngle);
					}
				}
				
				    
				if (myspaceShip.getMove() && myspaceShip.getRotate()){
					if (tempAngle < rotation){
						myspaceShip.sprite.setRotation(tempAngle);
						tempAngle += 0.5;
						//std::cout <<"TA is:" <<tempAngle << "\n";
					}
					else if (tempAngle > rotation) {
						myspaceShip.sprite.setRotation(tempAngle);
						tempAngle -= 0.5;
					}
					if (tempAngle + 0.5 > rotation && tempAngle < rotation || tempAngle - 0.5 < rotation && tempAngle > rotation)
					myspaceShip.setRotate(false);
				}

					if (myspaceShip.getMove() && !myspaceShip.getRotate()){
						distance = sqrt((tempX - myspaceShip.getSpaceShipPosition().x)*(tempX - myspaceShip.getSpaceShipPosition().x) + (tempY - myspaceShip.getSpaceShipPosition().y)*(tempY - myspaceShip.getSpaceShipPosition().y));
						if (distance > 2){
							PointF sp(myspaceShip.getSpaceShipPosition().x + 1 * (tempX - myspaceShip.getSpaceShipPosition().x) / distance, myspaceShip.getSpaceShipPosition().y + 1 * (tempY - myspaceShip.getSpaceShipPosition().y) / distance);
							myspaceShip.setSpaceShipPosition(sp);
					
						}

						else myspaceShip.setMove(false); 
					}


					if (Keyboard::isKeyPressed(Keyboard::Num1)){
						myspaceShip.changeBody("spaceship1");
					}
					else if (Keyboard::isKeyPressed(Keyboard::Num2)){
						myspaceShip.changeBody("spaceship2");
					}
					else if (Keyboard::isKeyPressed(Keyboard::Num3)){
						myspaceShip.changeBody("spaceship3");
					}
					else if (Keyboard::isKeyPressed(Keyboard::Num4)){
						myspaceShip.changeBody("spaceship4");
					}
					else if (Keyboard::isKeyPressed(Keyboard::Num5)){
						myspaceShip.changeBody("spaceship5");
					}
					else if (Keyboard::isKeyPressed(Keyboard::Num6)){
						myspaceShip.changeBody("spaceship6");
					}

					

				window.draw(fonsprite);
				window.draw(sun.sprite);
				window.draw(planet.sprites[i]);
				window.draw(planet1.sprites[i]);
				window.draw(myspaceShip.sprite);
				window.draw(myspaceShip2.sprite);
				window.draw(p.sprite);
				window.display();
				window.setView(view);
				window.clear();
				myspaceShip.move();
				p.findDistance(myspaceShip);
					planet.move(center,1500);
					planet1.move(center, 2100);
					
				viewmap(time1);
			  
				sleep(t);

			}
			
			
			
			
		}
		
	}
	return 0;
}