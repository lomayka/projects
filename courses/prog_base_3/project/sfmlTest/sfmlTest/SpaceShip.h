#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"

using namespace sf;


class SpaceShip{
private: PointF position;
		 int health;
public: std::string name;
		
		bool isMove;
		bool isRotate;
		Image image;
		Texture texture;
		Sprite sprite;
		float currAngle;
	SpaceShip(std::string name,PointF startPosition){
		this->name = name;
		this->position = startPosition;
		this->isMove = false;
		this->isRotate = false;
		this->currAngle = 0;
		this->health = 250;
		image.loadFromFile("images/SpaceShips/" + name + ".png");
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

};