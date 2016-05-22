#include <SFML/Graphics.hpp>
#include "PointF.h"

using namespace sf;

class Star {

public:	
	Image image;
	Texture texture;
	Sprite sprite;
	std::string filename;
//private:
	PointF position;



	Star(PointF position,std::string filename){
		this->filename = filename;
		this->position = position;
		image.loadFromFile("../sfmlTest/images/" + filename + ".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setPosition(position.x, position.y);

	}



};