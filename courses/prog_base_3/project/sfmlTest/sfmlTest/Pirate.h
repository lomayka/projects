#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"
#define Pi 3.14159265

using namespace sf;

class Pirate{
private: PointF position;
		 int health;
		 bool isMove;
		 bool isRotate;
		 float currAngle;
		 float distance;
		 float rotation;

public: std::string name;
		Image image;
		Texture texture;
		Sprite sprite;


            Pirate(std::string name, PointF startPosition){
			this->name = name;
			this->position = startPosition;
			this->isMove = false;
			this->isRotate = false;
			this->currAngle = 0;
			this->health = 400;
			this->distance = 0;
			image.loadFromFile("../sfmlTest/images/SpaceShips/" + name + ".png");
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setPosition(position.x, position.y);
			sprite.setOrigin(image.getSize().x / 2, image.getSize().y / 2);
		}
			void findDistance(SpaceShip spaceship){
				rotation = (atan2(spaceship.getSpaceShipPosition().y - this->position.x, spaceship.getSpaceShipPosition().x - this->position.y)) * 180 / Pi;
				//if (currAngle < rotation) currAngle += 0.5;
				sprite.setRotation(10);
				std::cout << "Rotation is:" << rotation << "\n";
				distance = sqrt((this->position.x - spaceship.getSpaceShipPosition().x)*(this->position.x - spaceship.getSpaceShipPosition().x) + (this->position.y - spaceship.getSpaceShipPosition().y)*(this->position.y - spaceship.getSpaceShipPosition().y));
				if (distance < 2000 && distance > 20) {
					PointF sp(this->position.x + 0.5 * (spaceship.getSpaceShipPosition().x - this->position.x) / distance, this->position.y + 0.5 * (spaceship.getSpaceShipPosition().y - this->position.y) / distance);
					this->position = sp;
					this->move();
				}
			}
			PointF getPiratePosition(){
				return this->position;
			}
			void move(){
				this->sprite.setPosition(this->position.x, this->position.y);
			}
};