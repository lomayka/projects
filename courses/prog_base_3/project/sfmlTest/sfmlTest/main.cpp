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
#include "Player.h"
#define PlanetFrame 60
#define Pi 3.14159265






int main()
{
	
	
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
	fon.loadFromFile("../sfmlTest/images/gFonTest.png");
	fonsprite.setTexture(fon);
	Texture spacestation;
	Sprite spacestationSprite;
	spacestation.loadFromFile("../sfmlTest/images/spacestation.png");
	spacestationSprite.setTexture(spacestation);
	PointF spacestationPosition(9000, 1500);
	spacestationSprite.setPosition(spacestationPosition.x, spacestationPosition.y);
	SpaceShip * spaceshipsarr[4];
    spaceshipsarr[0] = new SpaceShip("spaceship1", spacestationPosition, 300, 5,5,500);
	spaceshipsarr[1] = new SpaceShip("spaceship2", spacestationPosition, 150, 2, 3, 650);
	spaceshipsarr[2] = new SpaceShip("spaceship3", spacestationPosition, 350, 7,6,550);
	spaceshipsarr[3] = new SpaceShip("spaceship4", spacestationPosition, 400, 6,6,600);

	
	PointF sunPosition(5400, 3100);
	Star sun(sunPosition, "sun");
	Time t = milliseconds(12);
	Time t1 = milliseconds(20);
	CircleShape shape(500,200);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color(255, 0, 0));
	shape.setOrigin(500, 500);
	Font font;
	font.loadFromFile("../sfmlTest/ofont.ru_Academy.ttf");
	Text newGame("New Game", font, 40);
	newGame.setColor(Color::Yellow);
	newGame.setStyle(Text::Bold);
	Text exit("Exit", font, 40);
	exit.setColor(Color::Yellow);
	exit.setStyle(Text::Bold);
	Text start("", font, 40);
	Text repair("", font, 40);
	Text h("", font, 40);
	Text w("", font, 40);
	Text s("", font, 40);
	Text spaceshipinfo("", font, 40);
	

    int tempX = 0;
	int tempY = 0;
	float distance = 0;
	float rotation = 0;
	float tempAngle = 0;
	bool att_status = false;
	bool isPressed = false;
	bool isSelected = false;
	bool isPlanetSelected = false;
	bool isStationSelected = false;
	bool isSpaceOnce = false;
	bool isAttack = false;
	bool isLock = false;
	bool isCliked = false;
	bool SpriteIsSelect[4] = {false,false,false,false};
	bool SpritesSelectStatus = false;
	int N = 1000;
	int M = 0;
	int PlanetNum = 1000;
	float explosionCountX = 0;
	float explosionCountY = 0;
	int gamePart = 0;
	PointF center(5400,3100);
	Rocket rocket;
	
	planet.move(center, 1500);

	Texture StartText;
	Sprite StartSprite;
	StartText.loadFromFile("../sfmlTest/images/start1.png");
	StartSprite.setTexture(StartText);
	Texture SpaceStationInside;
	Sprite SpaceStationInsideSprite; 
	SpaceStationInside.loadFromFile("../sfmlTest/images/spacestationinside2.png");
	SpaceStationInsideSprite.setTexture(SpaceStationInside);
	Texture PlanetInside;
	Sprite PlanetInsideSprite;
	PlanetInside.loadFromFile("../sfmlTest/images/city.png");
	PlanetInsideSprite.setTexture(PlanetInside);
	//Player player;
	SpaceShip myspaceShip = *spaceshipsarr[0];
	//player.setSpaceship(myspaceShip);
	Pirate p("spaceship6", sunPosition, 200, 500, 2, 2,"Test");
	PointF pposit(spacestationPosition.x + 200, spacestationPosition.y + 100);
	Pirate p1("spaceship1", pposit, 300, 500, 5, 5,"Nigadai");
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
	test.loadFromFile("../sfmlTest/images/rockets.png");
	testSprite.setTexture(test);
	Texture spaceships[4];
	Sprite spaceshipsSprite[4];
	for (int i = 0; i < 4; i++){
		spaceships[i].loadFromFile("../sfmlTest/images/SpaceShips/spaceship" + std::to_string(i + 1) + ".png");
		spaceshipsSprite[i].setTexture(spaceships[i]);
		int posY = 0;
		if (i < 2) posY = 80;
		else posY = 250;
		spaceshipsSprite[i].setPosition(200 * (i % 2) + 30, posY);
	}
	Text info("Info", font, 20);
	Text chose("", font, 40);
	Text description("", font, 30);
	description.setColor(Color::Yellow);
	info.setPosition(view.getCenter().x - 620, view.getCenter().y - 350);
	//myspaceShip.setWeapon(3);
	Clock clockClick, clockPirate, clockPlanet, clockStation,upgradeHealthClock;
	Time timeClick, timePirate, timePlanet, timeStation, upgradeHealthTime;
start:
	RenderWindow window(VideoMode(1280, 720), "Test");

	while (window.isOpen())
	{
		Event event;
		
		if (gamePart == 0) {
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			Vector2i pixelPosition = Mouse::getPosition(window);
			Vector2f position = window.mapPixelToCoords(pixelPosition);
			if (newGame.getGlobalBounds().contains(position)) newGame.setColor(Color::Red);
			else newGame.setColor(Color::Yellow);
			if (exit.getGlobalBounds().contains(position)) exit.setColor(Color::Red);
			else exit.setColor(Color::Yellow);
			if (event.type == Event::MouseButtonPressed && newGame.getGlobalBounds().contains(position)){
				if (event.key.code == Mouse::Left){
					gamePart = 1;
				}
			}
			if (event.type == Event::MouseButtonPressed && exit.getGlobalBounds().contains(position)){
				if (event.key.code == Mouse::Left){
					window.close();
				}
			}

				newGame.setPosition(100, 450);
				exit.setPosition(100, 550);
				
				window.draw(StartSprite);
				window.draw(newGame);
				window.draw(exit);
				window.display();
				window.clear();
				sleep(t1);
		}
		else if (gamePart == 1)
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			
			chose.setString("Choose your spaceship:");
			chose.setPosition(20, 10);
			
			Vector2i pixelPosition = Mouse::getPosition(window);
			Vector2f position = window.mapPixelToCoords(pixelPosition);
			int num = 1000;
			for (int i = 0; i < 4; i++){
				if (spaceshipsSprite[i].getGlobalBounds().contains(position)){
					if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left){
						timeClick = clockClick.getElapsedTime();
						if (timeClick.asMilliseconds() > 200){
							if (!SpriteIsSelect[i])
							{
								for (int j = 0; j < 4; j++){
									SpriteIsSelect[j] = false;
									spaceshipsSprite[j].setColor(Color::White);
								}
								spaceshipsSprite[i].setColor(Color::Green);
								SpriteIsSelect[i] = true;
								std::string des = "Description:\nHealth: ";
								des.append(std::to_string(spaceshipsarr[i]->getCurrHealth()));
								des.append("\nWeapon level(1-10): " + std::to_string(spaceshipsarr[i]->getWeapon()));
								des.append("\nProtection level(1-10): " + std::to_string(spaceshipsarr[i]->getShield()));
								des.append("\nSpeed: " + std::to_string(spaceshipsarr[i]->getSpeed()));
								description.setString(des);

								description.setPosition(950, 10);
							}
							else
							{
								spaceshipsSprite[i].setColor(Color::White);
								SpriteIsSelect[i] = false;
								description.setString("");

							}
							clockClick.restart();
						}
						
						
					}
				}
				
				start.setPosition(100, 500);
				start.setString("Start game");
				if (start.getGlobalBounds().contains(position)) start.setColor(Color::Red);
				else start.setColor(Color::Yellow);
				if (start.getGlobalBounds().contains(position) && event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left){
					for (int k = 0; k < 4; k++){
						if (SpriteIsSelect[k]) {
							myspaceShip = *spaceshipsarr[k];
							gamePart = 2;
						}
					}
					
				}
			}

			
			window.draw(SpaceStationInsideSprite);
			window.draw(chose);
			for (int i = 0; i < 4; i++){
				window.draw(spaceshipsSprite[i]);
			}
			window.draw(start);
			window.draw(description);
			window.display();
			window.clear();
			sleep(t1);



		}
		else if (gamePart == 3){
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			Vector2i pixelPosition = Mouse::getPosition(window);
			Vector2f position = window.mapPixelToCoords(pixelPosition);
			start.setPosition(650, 550);
			start.setString("Start");
			if (start.getGlobalBounds().contains(position)) start.setColor(Color::Red);
			else start.setColor(Color::Yellow);
			repair.setPosition(100, 20);
			repair.setString("Repair");
			h.setPosition(100, 80);
			h.setString("Upgrade Health");
			w.setPosition(100, 140);
			w.setString("Upgrade Weapon");


			if (repair.getGlobalBounds().contains(position)) repair.setColor(Color::Red);
			else repair.setColor(Color::Yellow);
			if (w.getGlobalBounds().contains(position)) w.setColor(Color::Red);
			else w.setColor(Color::Yellow);
			if (h.getGlobalBounds().contains(position)) h.setColor(Color::Red);
			else h.setColor(Color::Yellow);
			upgradeHealthTime = upgradeHealthClock.getElapsedTime();

			if (h.getGlobalBounds().contains(position) && event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left){
				if (upgradeHealthTime.asMilliseconds() > 200){
					if (myspaceShip.getHealth() < 800) myspaceShip.setHealth(myspaceShip.getHealth() + 15);
					upgradeHealthClock.restart();
				}
			}
			if (w.getGlobalBounds().contains(position) && event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left){
				if (upgradeHealthTime.asMilliseconds() > 200){
					if (myspaceShip.getWeapon() < 10) myspaceShip.setWeapon(myspaceShip.getWeapon() + 1);
					upgradeHealthClock.restart();
				}
			}
			if (repair.getGlobalBounds().contains(position) && event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left){
				myspaceShip.setCurrHealth(myspaceShip.getHealth());

			}
			if (start.getGlobalBounds().contains(position) && event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left){
						gamePart = 2;
						goto start;
					
				

			}
			window.draw(PlanetInsideSprite);
			window.draw(start);
			window.draw(repair);
			window.draw(h);
			window.draw(w);
			window.display();
			window.clear();
			sleep(t1);

		}

		else if(gamePart == 2) {

			

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
					time1 = time1 / 200;
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
							PointF sp(myspaceShip.getSpaceShipPosition().x + (float)myspaceShip.getSpeed() / 250 * (tempX - myspaceShip.getSpaceShipPosition().x) / distance, myspaceShip.getSpaceShipPosition().y + (float)myspaceShip.getSpeed()/250 * (tempY - myspaceShip.getSpaceShipPosition().y) / distance);
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
									timePirate = clockPirate.getElapsedTime();
									if (timePirate.asMilliseconds() > 200){
										if (event.key.code == Mouse::Right && !isSelected){
											isSelected = true;
											N = n;
											M = n;
										}
										else if (event.key.code == Mouse::Right && isSelected){
											isSelected = false;
											N = 1000;
											(*(Pirate *)pirate_list.list_getById(n)).sprite.setColor(Color::White);
										}
										clockPirate.restart();
									}
								}
								(*(Pirate *)pirate_list.list_getById(n)).sprite.setColor(Color::Red);

							}
							else if (!pirate.sprite.getGlobalBounds().contains(position) && !isSelected) (*(Pirate *)pirate_list.list_getById(n)).sprite.setColor(Color::White);
							if (Keyboard::isKeyPressed(Keyboard::Space) && isSelected && !isSpaceOnce && !isAttack)
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
								(*(Pirate *)pirate_list.list_getById(n)).sprite.setTextureRect(IntRect(int(explosionCountX) * 128, 128 * int(explosionCountY), 128, 128));
								(*(Pirate *)pirate_list.list_getById(n)).setShow(false);
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
									(*(Pirate *)pirate_list.list_getById(N)).pirate_setCurrHealth((*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() - 25 * (float)myspaceShip.getWeapon() / (*(Pirate *)pirate_list.list_getById(N)).getShield());
									rocket.rocket_setStartPosition(myspaceShip.getSpaceShipPosition());
									(*(Pirate *)pirate_list.list_getById(N)).pirate_setAttack();
									(*(Pirate *)pirate_list.list_getById(N)).setAim(myspaceShip.getSpaceShipPosition());
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
					for (int n = 0; n < planet_list.list_getSize(); n++){
						for (int l = 0; l < 60; l++){
							Vector2i pixelPosition = Mouse::getPosition(window);
							Vector2f position = window.mapPixelToCoords(pixelPosition);
							if ((*(Planet *)planet_list.list_getById(n)).sprites[l].getGlobalBounds().contains(position)){
								for (int k = 0; k < 60; k++) (*(Planet *)planet_list.list_getById(n)).sprites[k].setColor(Color::Green);
								}
								else if (!(*(Planet *)planet_list.list_getById(n)).sprites[l].getGlobalBounds().contains(position) && !isPlanetSelected) for (int k = 0; k < 60; k++) (*(Planet *)planet_list.list_getById(n)).sprites[k].setColor(Color::White);
							timePlanet = clockPlanet.getElapsedTime();
							if (event.type == Event::MouseButtonPressed && (*(Planet *)planet_list.list_getById(n)).sprites[l].getGlobalBounds().contains(position)){
								
									if (timePlanet.asMilliseconds() > 200){
										if (event.key.code == Mouse::Right && !isPlanetSelected)
										{

										isPlanetSelected = true;
										PlanetNum = n;
										for (int k = 0; k < 60; k++) (*(Planet *)planet_list.list_getById(n)).sprites[k].setColor(Color::Green);
										clockPlanet.restart();
										break;
									}
								}
								
									if (timePlanet.asMilliseconds() > 200){
										if (event.key.code == Mouse::Right && isPlanetSelected)
										{
										isPlanetSelected = false;
										PlanetNum = 1000;
										for (int k = 0; k < 60; k++) (*(Planet *)planet_list.list_getById(n)).sprites[k].setColor(Color::White);
										clockPlanet.restart();
									}
								}
							}
							
						}
					}
					Vector2i pixelPosition = Mouse::getPosition(window);
					Vector2f position = window.mapPixelToCoords(pixelPosition);

					if (spacestationSprite.getGlobalBounds().contains(position)){

						spacestationSprite.setColor(Color::Green);
						timeStation = clockStation.getElapsedTime();
						if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Right && !isStationSelected){
							if (timeStation.asMilliseconds() > 200){
								isStationSelected = true;
								spacestationSprite.setColor(Color::Green);
								clockStation.restart();
							}
						}
						else if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Right && isStationSelected)
						{
							if (timeStation.asMilliseconds() > 200){
								isStationSelected = false;
								spacestationSprite.setColor(Color::White);
								clockStation.restart();
							}
						}
					}
					else if (!spacestationSprite.getGlobalBounds().contains(position) && !isStationSelected) spacestationSprite.setColor(Color::White);
					if (spacestationSprite.getGlobalBounds().contains(myspaceShip.getSpaceShipPosition().x, myspaceShip.getSpaceShipPosition().y) && isStationSelected){
						gamePart = 1;
						isStationSelected = false;
						spacestationSprite.setColor(Color::White);
						goto start;
					}
					if (PlanetNum != 1000){
						
						if ((*(Planet *)planet_list.list_getById(PlanetNum)).sprites[0].getGlobalBounds().contains(myspaceShip.getSpaceShipPosition().x, myspaceShip.getSpaceShipPosition().y))
						{
							
							gamePart = 3;
							isPlanetSelected = false;
							PlanetNum = 1000;
							goto start;

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
					else if (Keyboard::isKeyPressed(Keyboard::Escape)){
						gamePart = 0;
						goto start;
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

					//window.setView(view);
					window.draw(fonsprite);
					window.draw(sun.sprite);
					for (int n = 0; n < planet_list.list_getSize(); n++){
						window.draw((*(Planet *)planet_list.list_getById(n)).sprites[i]);
					}
					window.draw(spacestationSprite);
					if (isAttack && N != 1000) window.draw(rocket.sprite);
					if (pirate_list.list_getSize() != 0 && (*(Pirate *)pirate_list.list_getById(M)).getShow()) window.draw(testSprite);
					window.draw(myspaceShip.sprite);

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
					for (int o = 0; o < k * 108; o++) window.draw(healthSprite[o]);
					if (isSelected)
					{
						float k1 = (float)(*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() / (*(Pirate *)pirate_list.list_getById(N)).pirate_getHealth();
						for (int o = 0; o < k1 * 108; o++)
							window.draw(healthEnemysSprite[o]);
					}
					if (isSelected){		
						window.draw(info);
					}
					window.draw(spaceshipinfo);
					View minimap(sf::FloatRect(0, 0, 380,200));
					minimap.setViewport(sf::FloatRect(0.5, -0.27, 0.5, 0.5));
					minimap.zoom(55.f);
					window.setView(minimap);
					window.draw(fonsprite);
					window.draw(sun.sprite);
					for (int n = 0; n < planet_list.list_getSize(); n++){
						window.draw((*(Planet *)planet_list.list_getById(n)).sprites[i]);
					}
					window.draw(spacestationSprite);
					if (isAttack && N != 1000) window.draw(rocket.sprite);
					if (pirate_list.list_getSize() != 0 && (*(Pirate *)pirate_list.list_getById(M)).getShow()) window.draw(testSprite);
					window.draw(myspaceShip.sprite);

					for (int n = 0; n < pirate_list.list_getSize(); n++){
						window.draw((*(Pirate *)pirate_list.list_getById(n)).sprite);
					}
					if (att_status == 1){
						shape.setPosition(myspaceShip.getSpaceShipPosition().x, myspaceShip.getSpaceShipPosition().y);
						window.draw(shape);
					}
					window.draw(healthBarSprite);
					if (isSelected) window.draw(healthBarEnemySprite);
					float l = (float)myspaceShip.getCurrHealth() / myspaceShip.getHealth();
					for (int o = 0; o < l * 108; o++) window.draw(healthSprite[o]);
					if (isSelected)
					{
						float l1 = (float)(*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() / (*(Pirate *)pirate_list.list_getById(N)).pirate_getHealth();
						for (int o = 0; o < l1 * 108; o++)
							window.draw(healthEnemysSprite[o]);
					}
					if (isSelected){
						window.draw(info);
					}

					window.display();
					window.setView(view);
					

					
					
					healthBarSprite.setPosition(view.getCenter().x + 590, view.getCenter().y + 200);
					healthBarEnemySprite.setPosition(view.getCenter().x - 630, view.getCenter().y + 200);
					spaceshipinfo.setString("Speed: " + std::to_string(myspaceShip.getSpeed()) + ";  Weapon: " + std::to_string(myspaceShip.getWeapon()) + ";  Protection: " + std::to_string(myspaceShip.getShield()) + ";  Health: " + std::to_string(myspaceShip.getCurrHealth()) + "/" + std::to_string(myspaceShip.getHealth()));
					spaceshipinfo.setPosition(view.getCenter().x-400, view.getCenter().y + 300);


					for (int o = 0; o < k * 108; o++) healthSprite[o].setPosition(view.getCenter().x + 598, view.getCenter().y + 328 - o);;

					if (isSelected)
					{
						float k1 = (float)(*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth() / (*(Pirate *)pirate_list.list_getById(N)).pirate_getHealth();
						for (int o = 0; o < k1 * 108; o++)
							healthEnemysSprite[o].setPosition(view.getCenter().x - 622, view.getCenter().y + 328 - o);
					}
					//std::cout << view.getCenter().x << " + " << view.getCenter().y << "\n";
					if (isSelected){

						info.setPosition(view.getCenter().x - 620, view.getCenter().y - 350);
						int h = (*(Pirate *)pirate_list.list_getById(N)).pirate_getCurrHealth();
						std::string infostr;
						infostr.append("Name: " + (*(Pirate *)pirate_list.list_getById(N)).getName());
						infostr.append("\nHealth: ");
						infostr.append(std::to_string(h));
						infostr.append("\nProtection: ");
						infostr.append(std::to_string((*(Pirate *)pirate_list.list_getById(N)).getShield()));
						infostr.append("\nWeapon: " + std::to_string((*(Pirate *)pirate_list.list_getById(N)).getWeapon()));
						infostr.append("\nSpeed: " + std::to_string((*(Pirate *)pirate_list.list_getById(N)).getSpeed()));
						info.setString(infostr);
					}

					window.clear();
					myspaceShip.move();

					for (int n = 0; n < pirate_list.list_getSize(); n++){
						testSprite.setPosition((*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().x, (*(Pirate *)pirate_list.list_getById(n)).getPiratePosition().y);
						(*(Pirate *)pirate_list.list_getById(n)).AI(&myspaceShip, &planet_list, &testSprite);
					}

					for (int n = 0; n < planet_list.list_getSize(); n++){
						(*(Planet *)planet_list.list_getById(n)).move(center, (n + 2) * 800);
					}

					if (myspaceShip.getCurrHealth() <= 0){
						gamePart = 1;
						goto start;
					}


					viewmap(time1);
					sleep(t);

				}




			}
		}
		
		
	}
	return 0;
}