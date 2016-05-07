#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"

using namespace sf;


class SpaceShip{
//private: PointF position;
public: std::string name;
		PointF position;
		bool isMove;
		Image image;
		Texture texture;
		Sprite sprite;
	SpaceShip(std::string name,PointF startPosition){
		this->name = name;
		this->position = startPosition;
		this->isMove = false;
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
	void move(){
		this->sprite.setPosition(this->position.x,this->position.y);
	}

};