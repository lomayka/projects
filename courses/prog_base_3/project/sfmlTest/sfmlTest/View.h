#ifndef View_H
#define View_H

#include <SFML/Graphics.hpp>
#include "PointF.h"

using namespace sf;

View view;

View getplayercoordinateforview(PointF point) {
	view.setCenter(point.x, point.y); 
	return view;

}


View viewmap(float time) {


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (view.getCenter().x < 10000)
		   view.move(0.1*time, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (view.getCenter().y < 5900)
		   view.move(0, 0.1*time);
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (view.getCenter().x > 800) 
			view.move(-0.1*time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (view.getCenter().y > 500)
		view.move(0, -0.1*time);
	}
	return view;

}

#endif