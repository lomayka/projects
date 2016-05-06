#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"

using namespace sf;


class SpaceShip{
private: PointF position;
public: std::string name;
		Image image;
		Texture texture;
		Sprite sprite;
	SpaceShip(std::string name,PointF startPosition){
		this->name = name;
		this->position = startPosition;
		image.loadFromFile("images/SpaceShips/" + name + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(position.x, position.y);

	}
	SpaceShip(){

	}
public: 
	PointF getSpaceShipPosotion(){
		return this->position;
	}

};