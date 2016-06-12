#ifndef Player_H
#define Player_H

#include <SFML/Graphics.hpp>
#include <string>
#include "PointF.h"
#include "SpaceShip.h"

class Player{
private:
	std::string name;
	int money;
	int level;
	SpaceShip spaceship;
public:
	Player(){
		this->money = 3000;
		this->level = 1;
	}
	void setSpaceship(SpaceShip spaceship){
		this->spaceship = spaceship;
	}
	int getMoney(){
		return this->money;
	}
	void setMoney(){
		this->money = money;
	}
	SpaceShip getSpaceShip(){
		return this->spaceship;
	}
	void setSpaceShip(SpaceShip spaceship){
		this->spaceship = spaceship;
	}
};

#endif