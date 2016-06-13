#ifndef SpaceShip_H
#define SpaceShip_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"

using namespace sf;


class SpaceShip{
private: PointF position;
		 int health;
		 bool isMove;
		 bool isRotate;
		 float currAngle;
		 int curr_health;
		 int weapon;
		 int protection;
		 int speed;
		 std::string filename;
		 
public: 
		Image image;
		Texture texture;
		Sprite sprite;
		
		
		


	SpaceShip(std::string filename,PointF startPosition,int health,int weapon,int protection,int speed){
		this->filename = filename;
		this->position = startPosition;
		this->isMove = false;
		this->isRotate = false;
		this->currAngle = 0;
		this->health = health;
		this->weapon = weapon;
		this->protection = protection;
		this->curr_health = this->health;
		this->speed = speed;
		image.loadFromFile("../sfmlTest/images/SpaceShips/" + filename + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(position.x, position.y);
		sprite.setOrigin(image.getSize().x / 2, image.getSize().y / 2);
	}
	SpaceShip(){

	}
public: 
	PointF getSpaceShipPosition(){
		return this->position;
	}
	void setSpaceShipPosition(PointF point){
		this->position = point;
		
	}
	void move(){
		this->sprite.setPosition(this->position.x,this->position.y);
	}
	bool getMove(){
		return this->isMove;
	}
	bool getRotate(){
		return this->isRotate;
	}
	void setMove(bool status)
	{
		this->isMove = status;
	}
	void setRotate(bool status){
		this->isRotate = status;
	}
	float getCurrAngle(){
		return this->currAngle;
	}
	void setCurrAngle(float angle){
		this->currAngle = angle;
	}
	Image getImage(){
		return this->image;
	}
	Texture getTexture(){
		return this->texture;
	}
	Sprite getSprite(){
		return this->sprite;
	}
	void setImage(Image image){
		this->image = image;
	}
	void changeBody(std::string name){
		image.loadFromFile("../sfmlTest/images/SpaceShips/" + name + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(this->position.x, this->position.y);
		sprite.setOrigin(image.getSize().x / 2, image.getSize().y / 2);
	}
	int getCurrHealth(){
		return this->curr_health;
	}
	void setCurrHealth(int curr_health)
	{
		this->curr_health = curr_health;
	}
	int getHealth(){
		return this->health;
	}
	void setWeapon(int weapon){
		this->weapon = weapon;
	}
	int getWeapon(){
		return this->weapon;
	}
	int getShield(){
		return this->protection;
	}
	int getSpeed(){
		return this->speed;
	}
	void setSpeed(int speed){
		this->speed = speed;
	}
	void setHealth(int health){
		this->health = health;
	}
	
};

#endif
