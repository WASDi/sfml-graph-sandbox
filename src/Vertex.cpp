#include "Vertex.h"
#include <stdio.h>
#include <string>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

sf::Font* initFont() {
	sf::Font* font = new sf::Font();
	font->loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
	return font;
}

sf::Font* Vertex::font = initFont();

Vertex::Vertex(int idx, sf::Shape* shape) : idx(idx), shape(shape) {
	this->text = new sf::Text(std::to_string(idx), *font);
	this->text->setFillColor(sf::Color::White);
	this->text->setScale(0.7, 0.7);
	this->text->setPosition(
			shape->getPosition().x - 12 + (idx < 10 ? 6 : 0),
			shape->getPosition().y - 14
			);

}

Vertex::~Vertex() {
	delete this->shape;
	delete this->text;
}