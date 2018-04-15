#include "Vertex.h"
#include "Util.h"
#include <stdio.h>
#include <string>

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

sf::Font* initFont() {
	sf::Font* font = new sf::Font();
	font->loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
	return font;
}

sf::Font* Vertex::font = initFont();

Vertex::Vertex(int idx, float x, float y) : idx(idx), x(x), y(y) {
	this->shape = this->generateShape();
	this->text = this->generateText();
}

Vertex::~Vertex() {
	delete this->shape;
	delete this->text;
}

const sf::Vector2f* Vertex::getPosition() {
	return &this->shape->getPosition();
}

#define CIRCLE_RADIUS 15

sf::Shape* Vertex::generateShape() {
	sf::Shape* shape = new sf::CircleShape(CIRCLE_RADIUS);
	shape->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
	shape->setPosition(this->x, this->y);
	shape->setFillColor(sf::Color::Green);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color(250, 150, 100));
	return shape;
}

sf::Text* Vertex::generateText() {
	sf::Text* text = new sf::Text(std::to_string(idx), *font);
	text->setFillColor(sf::Color::White);
	text->setScale(0.7, 0.7);
	text->setPosition(
			shape->getPosition().x - 12 + (idx < 10 ? 6 : 0),
			shape->getPosition().y - 14
			);
	return text;
}