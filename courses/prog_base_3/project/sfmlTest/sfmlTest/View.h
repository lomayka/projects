#include <SFML/Graphics.hpp>
#include "PointF.h"

using namespace sf;

View view;

View getplayercoordinateforview(PointF point) { //функция для считывания координат игрока
	view.setCenter(point.x+750, point.y+375); //следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо. эксперементируйте
	return view;

}


View viewmap(float time) { //функция для перемещения камеры по карте. принимает время sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1*time, 0);//скроллим карту вправо (см урок, когда мы двигали героя - всё тоже самое)
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1*time);//скроллим карту вниз (см урок, когда мы двигали героя - всё тоже самое)
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1*time, 0);//скроллим карту влево (см урок, когда мы двигали героя - всё тоже самое)
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1*time);//скроллим карту вправо (см урок, когда мы двигали героя - всё тоже самое)
	}
	return view;

}