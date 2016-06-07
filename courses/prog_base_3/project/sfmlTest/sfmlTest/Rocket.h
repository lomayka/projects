#ifndef Rocket_H
#define Rocket_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"
#include "List.h"
#include "Planet.h"
#include "Pirate.h"
#define Pi 3.14159265

using namespace sf;

class Rocket{
private: PointF position;
		 float speed;
		 float distance;
		 float rotation;
		 Pirate pirate;

public: 
		Image image;
		Texture texture;
		Sprite sprite;


		Rocket(){
			this->distance = 0;
			this->speed = 400;
			image.loadFromFile("../sfmlTest/images/rockets.png");
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setPosition(position.x, position.y);
			sprite.setOrigin(image.getSize().x / 2, image.getSize().y / 2);
		}
		bool Fire(){
			rotation = (atan2(pirate.getPiratePosition().y - this->position.y, pirate.getPiratePosition().x - this->position.x)) * 180 / Pi;
			sprite.setRotation(rotation);
			distance = sqrt((this->position.x - pirate.getPiratePosition().x)*(this->position.x - pirate.getPiratePosition().x) + (this->position.y - pirate.getPiratePosition().y)*(this->position.y - pirate.getPiratePosition().y));

			PointF sp(this->position.x + (this->speed / 400) * (pirate.getPiratePosition().x - this->position.x) / distance, this->position.y + (this->speed / 400) * (pirate.getPiratePosition().y - this->position.y) / distance);
					this->position = sp;
					this->move();
			if (distance < 50) return true;
			else return false;
				//std::cout << "X - " << dest.x << " Y - " << dest.y << "\n";


			}
		void move(){
			this->sprite.setPosition(this->position.x, this->position.y);
		}
		void rocket_setSpeed(float speed)
		{
			this->speed = speed;
		}
		void rocket_setStartPosition(PointF position)
		{
			this->position = position;
		}
		void rocket_setPirate(Pirate pirate)
		{
			this->pirate = pirate;
		}

};
#endif