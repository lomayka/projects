#ifndef Pirate_H
#define Pirate_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"
#include "List.h"
#include "Planet.h"
#define Pi 3.14159265

using namespace sf;

class Pirate{
private: PointF position;
		 int health;
		 int shield;
		 int weapon;
		 int curr_health;
		 float speed;
		 bool isMove;
		 bool isRotate;
		 float currAngle;
		 float distance;
		 float rotation;
		 bool isAttack;
		 bool isFire;
		 bool isShow;
		 PointF aim;
		 PointF spos;

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
			this->health = 200;
			this->curr_health = this->health;
			this->distance = 0;
			this->speed = 400;
			this->weapon = 1;
			this->shield = 1;
			this->isFire = false;
			this->isAttack = false;
			this->isShow = false;
			image.loadFromFile("../sfmlTest/images/SpaceShips/" + name + ".png");
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setPosition(position.x, position.y);
			sprite.setOrigin(image.getSize().x / 2, image.getSize().y / 2);
		}
			Pirate()
			{

			}
			void AI(SpaceShip * spaceship, List * list,Sprite * s){
	  
				static int status = 0;
				rotation = (atan2((*spaceship).getSpaceShipPosition().y - this->position.y, (*spaceship).getSpaceShipPosition().x - this->position.x)) * 180 / Pi;
				sprite.setRotation(rotation);
				//std::cout << "Rotation is:" << rotation << "\n";
				distance = sqrt((this->position.x - (*spaceship).getSpaceShipPosition().x)*(this->position.x - (*spaceship).getSpaceShipPosition().x) + (this->position.y - (*spaceship).getSpaceShipPosition().y)*(this->position.y - (*spaceship).getSpaceShipPosition().y));
				if (distance < 2000) {
					if (distance > 200){
						PointF sp(this->position.x + (this->speed / 400) * ((*spaceship).getSpaceShipPosition().x - this->position.x) / distance, this->position.y + (this->speed / 400) * ((*spaceship).getSpaceShipPosition().y - this->position.y) / distance);
						this->position = sp;
						this->move();
					}
					if (isAttack){
						isShow = true;
						int dist = sqrt((spos.x - aim.x)*(spos.x - aim.x) + (spos.y - aim.y)*(spos.y - aim.y));
						int rot = (atan2(aim.y - this->position.y, aim.x - this->position.x)) * 180 / Pi;
						std::cout << dist << "\n";
						if (dist > 20){
							PointF sp(spos.x + (this->speed / 400) * (aim.x - spos.x) / dist, spos.y + (this->speed / 400) * (aim.y - spos.y) / dist);
							this->spos = sp;
							
							(*s).setPosition(spos.x, spos.y);
							(*s).setRotation(rot);
						}
						else
						{   
							this->spos = position;

							(*spaceship).setCurrHealth((*spaceship).getCurrHealth() - 10);
							this->aim = (*spaceship).getSpaceShipPosition();
						}
						
					
					}
				}
				else {
					PointF dest = (*((Planet *)(*list).list_getById(status))).getCoord();
					rotation = (atan2(dest.y - this->position.y, dest.x - this->position.x)) * 180 / Pi;
					sprite.setRotation(rotation);
					float dist = sqrt((this->position.x - dest.x)*(this->position.x - dest.x) + (this->position.y - dest.y)*(this->position.y - dest.y));
					if (dist > 100) {
						PointF sp(this->position.x + (this->speed / 400) * (dest.x - this->position.x) / dist, this->position.y + (this->speed / 400) * (dest.y - this->position.y) / dist);
						this->position = sp;
						this->move();
					}
					else
					{
						status += 1;
						if (status == (*list).list_getSize()) status = 0;
					}
					//std::cout << "X - " << dest.x << " Y - " << dest.y << "\n";


				}
			}
			PointF getPiratePosition(){
				return this->position;
			}
			void move(){
				this->sprite.setPosition(this->position.x, this->position.y);
			}
			void pirate_setSpeed(float speed)
			{
				this->speed = speed;
			}
			void pirate_setHeath(int health){
				this->health = health;
			}

			int pirate_getHealth(){
				return this->health;
			}
			int pirate_getCurrHealth()
			{
				return this->curr_health;
			}
			void pirate_setCurrHealth(int curr_health){
				this->curr_health = curr_health;
			}
			void pirate_setAttack()
			{
				this->isAttack = true;
			}
			void setSpos(PointF spos){
				this->spos = spos;
			}
			void setAim(PointF aim){
				this->aim = aim;
			}
			bool getAttack(){
				return this->isAttack;
			}
			bool getShow(){
				return this->isShow;
			}
			void setShow(bool status)
			{
				this->isShow = status;
			}
			void setShield(int shield){
				this->shield = shield;
			}
			int getShield(){
				return this->shield;
			}
};
#endif