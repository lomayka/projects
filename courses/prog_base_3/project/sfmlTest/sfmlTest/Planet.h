#ifndef Planet_H
#define Planet_H

#include <SFML/Graphics.hpp>
#include <conio.h>
#include <string>
#include <iostream>
#include "PointF.h"
#include "SpaceShip.h"
#include "View.h"
#include "Star.h"
#include "List.h"
#define PlanetFrame 60

using namespace sf;

class Planet{
private: PointF point;
public: std::string name;
		Image images[PlanetFrame];
		Texture textures[PlanetFrame];
		Sprite sprites[PlanetFrame];
		float angle;
		Planet(std::string name, PointF point, float startAngle){ // todo frameCount
			this->name = name;
			this->point.x = point.x;
			this->point.y = point.y;
			this->angle = startAngle;
			for (int i = 0; i < PlanetFrame; i++){
				std::string num = std::to_string(i + 1);
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
			for (int i = 0; i < PlanetFrame; i++){
				this->sprites[i].setPosition(this->point.x, this->point.y);

			}
			this->angle = this->angle + 0.0002;

}
};
#endif