#include <SFML/Graphics.hpp>
#include <conio.h>
#include <string>
#include <iostream>
#include "PointF.h"
#include "SpaceShip.h"
#include "View.h"
#include "Star.h"
#include "Pirate.h"
#include "List.h"
#include "Planet.h"
#include "Rocket.h"
#define PlanetFrame 60
#define Pi 3.14159265






int main()
{
	RenderWindow window(VideoMode(1280,720), "Test");
	view.reset(FloatRect(0, 0, 1280, 720));
	List planet_list,pirate_list;
	PointF point(4300,1900 );
	Planet planet("Planet1", point,270);
	PointF point1(4800, 1500);
	Planet planet1("Planet2", point1,500);
	planet_list.list_add((void *)&planet);
	planet_list.list_add((void *)&planet1);
	Clock clock;
	Clock clock1;

	
	Texture fon;
	Sprite fonsprite;
	fon.loadFromFile("../sfmlTest/images/gFon.png");
	fonsprite.setTexture(fon);
	Texture spacestation;
	Sprite spacestationSprite;
	spacestation.loadFromFile("../sfmlTest/images/spacestation.png");
	spacestationSprite.setTexture(spacestation);
	PointF spacestationPosition(9000, 1500);
	spacestationSprite.setPosition(spacestationPosition.x, spacestationPosition.y);
	
	PointF spaceshipPoint1(20, 120);
	SpaceShip myspaceShip2("spaceship6", spaceshipPoint1);
	PointF sunPosition(6400, 3600);
	Star sun(sunPosition, "sun");
	Time t = milliseconds(12);
	CircleShape shape(500,200);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color(255, 0, 0));
	shape.setOrigin(500, 500);
	

    int tempX = 0;
	int tempY = 0;
	float distance = 0;
	float rotation = 0;
	float tempAngle = 0;
	bool att_status = false;
	bool isPressed = false;
	bool isSelected = false;
	bool isSpaceOnce = false;
	bool isAttack = false;
	bool isLock = false;
	int N = 1000;
	float explosionCountX = 0;
	float explosionCountY = 0;
	PointF center(6400,3600);
	Rocket rocket;
	
	planet.move(center, 1500);

	SpaceShip myspaceShip("spaceship1", spacestationPosition);
	Pirate p("spaceship6", sunPosition,myspaceShip);
	p.pirate_setSpeed(400);
	p.pirate_setHeath(200);
	Pirate p1("spaceship1", planet.getCoord(), myspaceShip);
	p1.pirate_setSpeed(400);
	p1.pirate_setHeath(200);
	pirate_list.list_add((void *)&p);
	pirate_list.list_add((void *)&p1);
	view = getplayercoordinateforview(myspaceShip.getSpaceShipPosition());
	Texture healthBar;
	Sprite healthBarSprite;
	healthBar.loadFromFile("../sfmlTest/images/right_hbar.png");
	healthBarSprite.setTexture(healthBar);
	healthBarSprite.setPosition(view.getCenter().x + 590, view.getCenter().y + 200);
	Texture healthBarEnemy;
	Sprite healthBarEnemySprite;
	healthBarEnemy.loadFromFile("../sfmlTest/images/left_hbar.png");
	healthBarEnemySprite.setTexture(healthBarEnemy);
	healthBarEnemySprite.setPosition(view.getCenter().x - 630, view.getCenter().y + 200);
	Texture health;
	Sprite healthSprite[110];
	health.loadFromFile("../sfmlTest/images/grad1.png");
	for (int i = 0; i < 108; i++){
		healthSprite[i].setTexture(health);
		healthSprite[i].setPosition(view.getCenter().x + 598, view.getCenter().y + 328-i);
	}
	Sprite healthEnemysSprite[110];
	health.loadFromFile("../sfmlTest/images/grad1.png");
	for (int i = 0; i < 108; i++){
		healthEnemysSprite[i].setTexture(health);
		healthEnemysSprite[i].setPosition(view.getCenter().x - 622, view.getCenter().y + 328 - i);
	}
	Texture test;
	Sprite testSprite;
	test.loadFromFile("../sfmlTest/images/test.png");
	testSprite.setTexture(test);

	while (window.isOpen())
	{
		
		
		Event event;

		for (int i = 0; i < PlanetFrame; i++){

			
		
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 400;

			isSpaceOnce = false;
			for (int j = 0; j < 40; j++){
				Vector2i pixelPos = Mouse::getPosition(window);
				Vector2f pos = window.mapPixelToCoords(pixelPos);
				float time1 = clock1.getElapsedTime().asMicroseconds();
				clock1.restart();
				time1= time1 / 200;
				isPressed = false;
				
				
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
						//float dpX = pos.x - p.getPiratePosition().x;
						//float dpY = pos.y - p.getPiratePosition().y;
						rotation = (atan2(dY, dX)) * 180 / Pi;
						//r = (atan2(dpY, dX)) * 180 / Pi;
						if (rotation < 0) rotation = 360 + rotation;
						myspaceShip.setCurrAngle(rotation);
						//p.sprite.setRotation(rotation);
	                    
						
					}
					if (event.key.code == Mouse::Right && myspaceShip.getMove() == true || event.key.code == Mouse::Right && myspaceShip.getRotate() == true){
						myspaceShip.setMove(false);
						myspaceShip.setRotate(false);
						myspaceShip.setCurrAngle(tempAngle);
					}
				}
				
				    
				if (myspaceShip.getMove() && myspaceShip.getRotate()){
					//std::cout << "Rotation" << rotation << "\n" <<"Temp Angle" <<tempAngle << "\n";
					if (tempAngle < rotation){
						if (rotation - tempAngle < 180){
							myspaceShip.sprite.setRotation(tempAngle);
							tempAngle += 1.5;
						}
						else {
							tempAngle += 360;
							myspaceShip.sprite.setRotation(tempAngle);
							tempAngle -= 1.5;
						}
						//std::cout <<"TA is:" <<tempAngle << "\n";
					}
					else if (tempAngle > rotation) {
						if (tempAngle - rotation < 180){
							myspaceShip.sprite.setRotation(tempAngle);
							tempAngle -= 1.5;
						}
						else {
							tempAngle -= 360;
							myspaceShip.sprite.setRotation(tempAngle);
							tempAngle += 1.5;
						}
					}
					if (tempAngle + 1.5 > rotation && tempAngle < rotation || tempAngle - 1.5 < rotation && tempAngle > rotation)
					myspaceShip.setRotate(false);
				}

					if (myspaceShip.getMove() && !myspaceShip.getRotate()){
						distance = sqrt((tempX - myspaceShip.getSpaceShipPosition().x)*(tempX - myspaceShip.getSpaceShipPosition().x) + (tempY - myspaceShip.getSpaceShipPosition().y)*(tempY - myspaceShip.getSpaceShipPosition().y));
						if (distance > 2){
							PointF sp(myspaceShip.getSpaceShipPosition().x + 2 * (tempX - myspaceShip.getSpaceShipPosition().x) / distance, myspaceShip.getSpaceShipPosition().y + 2 * (tempY - myspaceShip.getSpaceShipPosition().y) / distance);
							myspaceShip.setSpaceShipPosition(sp);
					
						}

						else myspaceShip.setMove(false); 
					}
					for (int n = 0; n < pirate_list.list_getSize(); n++){
						int dist = sqrt(((*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().x - myspaceShip.getSpaceShipPosition().x)*((*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().x - myspaceShip.getSpaceShipPosition().x) + ((*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().y - myspaceShip.getSpaceShipPosition().y)*((*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().y - myspaceShip.getSpaceShipPosition().y));
						if (dist < 500) {
							Vector2i pixelPosition = Mouse::getPosition(window);
							Vector2f position = window.mapPixelToCoords(pixelPosition);
							Pirate pirate = (*(Pirate *)pirate_list.list_getById(n));
							if (pirate.sprite.getGlobalBounds().contains(position) && (n == N || N == 1000)){
								if (event.type == Event::MouseButtonPressed){
									if (event.key.code == Mouse::Right && !isSelected ){
										isSelected = true;
										N = n;
									}
									else if (event.key.code == Mouse::Right && isSelected){
										isSelected = false;
										N = 1000;
										(*(Pirate *)pirate_list.list_getById(n)).sprite.setColor(Color::White);
									}
								}
								(*(Pirate *)pirate_list.list_getById(n)).sprite.setColor(Color::Red);

							}
							else if (!pirate.sprite.getGlobalBounds().contains(position) && !isSelected) (*(Pirate *)pirate_list.list_getById(n)).sprite.setColor(Color::White);
							if (Keyboard::isKeyPressed(Keyboard::Space) && isSelected && !isSpaceOnce)
							{
								isAttack = true;
								//N = n;
								rocket.rocket_setStartPosition(myspaceShip.getSpaceShipPosition());
								rocket.rocket_setPirate((*(Pirate *)pirate_list.list_getById(n)));
								
								isSpaceOnce = true;
								std::cout << "Health: " << (*(Pirate *)pirate_list.list_getById(n)).pirate_getHealth() << "\n";
							}
							if ((*(Pirate *)pirate_list.list_getById(n)).pirate_getCurrHealth() <= 0)
							{
								
								(*(Pirate *)pirate_list.list_getById(n)).image.loadFromFile("../sfmlTest/images/explode.png");
								(*(Pirate *)pirate_list.list_getById(n)).texture.loadFromImage((*(Pirate *)pirate_list.list_getById(n)).image);
								(*(Pirate *)pirate_list.list_getById(n)).sprite.setTexture((*(Pirate *)pirate_list.list_getById(n)).texture);
								(*(Pirate *)pirate_list.list_getById(n)).sprite.setTextureRect(IntRect(int(explosionCountX)*128, 128*int(explosionCountY), 128, 128));
								explosionCountX += 0.3;
								if (explosionCountX > 3){
									explosionCountX = 0;
									explosionCountY += 1;
								}
								if (explosionCountY == 4) pirate_list.list_delete(n);
							}
							if (isAttack && N != 1000){
								rocket.rocket_setPirate((*(Pirate *)pirate_list.list_getById(N)));
								if (rocket.Fire()){
									std::cout << "OK";
									(*(Pirate *)pirate_list.list_getById(N)).pirate_setCurrHealth((*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() - 25);
									rocket.rocket_setStartPosition(myspaceShip.getSpaceShipPosition());
									(*(Pirate *)pirate_list.list_getById(N)).pirate_setAttack();
									(*(Pirate *)pirate_list.list_getById(N)).setSpos((*(Pirate *)pirate_list.list_getById(N)).getPiratePosition());

									rocket.move();
									N = 1000;
									isAttack = false;
									isSelected = false;
									explosionCountY = 0;
									explosionCountX = 0;
								}
							
							}
						} 
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
					else if (Keyboard::isKeyPressed(Keyboard::Q)){
						if (!isPressed){
							myspaceShip.setCurrHealth(myspaceShip.getCurrHealth() - 5);
							isPressed = true;
						}
						
					}
					else if (Keyboard::isKeyPressed(Keyboard::T))
					{
						
					}
					
					
				window.draw(fonsprite);
				window.draw(sun.sprite);
				for (int n = 0; n < planet_list.list_getSize(); n++){
					window.draw((*(Planet *)planet_list.list_getById(n)).sprites[i]);
				}
				window.draw(spacestationSprite);
				if (isAttack && N != 1000) window.draw(rocket.sprite);
				if ( pirate_list.list_getSize()!= 0) window.draw(testSprite);
				window.draw(myspaceShip.sprite);
				window.draw(myspaceShip2.sprite);
				
				for (int n = 0; n < pirate_list.list_getSize(); n++){
				     window.draw((*(Pirate *)pirate_list.list_getById(n)).sprite);
				}
				if (att_status == 1){
					shape.setPosition(myspaceShip.getSpaceShipPosition().x, myspaceShip.getSpaceShipPosition().y);
					window.draw(shape);
				}
				window.draw(healthBarSprite);
				if (isSelected) window.draw(healthBarEnemySprite);
				float k = (float)myspaceShip.getCurrHealth() / myspaceShip.getHealth();
				for (int o = 0; o < k * 108;o++) window.draw(healthSprite[o]);
				if (isSelected)
				{
					float k1 = (float)(*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() / (*(Pirate *)pirate_list.list_getById(N)).pirate_getHealth();
					for (int o = 0; o < k1 * 108; o++)
						window.draw(healthEnemysSprite[o]);
				}
				window.display();
				window.setView(view);
				healthBarSprite.setPosition(view.getCenter().x + 590, view.getCenter().y + 200);
				healthBarEnemySprite.setPosition(view.getCenter().x - 630, view.getCenter().y + 200);
				for (int o = 0; o < k * 108; o++) healthSprite[o].setPosition(view.getCenter().x + 598, view.getCenter().y + 328 - o);;
				
				if (isSelected)
				{
					float k1 = (float)(*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() / (*(Pirate *)pirate_list.list_getById(N)).pirate_getHealth();
					for (int o = 0; o <  k1 * 108; o++)
						healthEnemysSprite[o].setPosition(view.getCenter().x - 622, view.getCenter().y + 328 - o);
				}
				//std::cout << view.getCenter().x << " + " << view.getCenter().y << "\n";
				window.clear();
				myspaceShip.move();
				
				for (int n = 0; n < pirate_list.list_getSize(); n++){
					testSprite.setPosition((*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().x, (*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().y);
					(*(Pirate *)pirate_list.list_getById(n)).AI(&myspaceShip,&planet_list,&testSprite);
				}
				
				for (int n = 0; n < planet_list.list_getSize(); n++){
					(*(Planet *)planet_list.list_getById(n)).move(center, (n+2)*800);
				}

					
					
				viewmap(time1);
				sleep(t);

			}
			
			
			
			
		}
		
	}
	return 0;
}