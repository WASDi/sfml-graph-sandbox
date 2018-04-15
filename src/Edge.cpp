#include "Edge.h"
#include "Util.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <math.h>

Edge::Edge(Vertex* from, Vertex* to) : from(from), to(to) {
	this->shape = generateShape();
}

Edge::~Edge() {
	delete this->shape;
}

#define LINE_WIDTH 4
sf::Shape* Edge::generateShape() {
	const sf::Vector2f a = *this->from->getPosition();
	const sf::Vector2f b = *this->to->getPosition();
	float centerX = (a.x + b.x) / 2;
	float centerY = (a.y + b.y) / 2;
	
	float length = Util::distance(&a, &b);
	float angle = atan2(b.y - a.y, b.x - a.x) * 180 / M_PI;

	sf::RectangleShape* line = new sf::RectangleShape(sf::Vector2f(length, LINE_WIDTH));
	line->setFillColor(sf::Color::Black);
	line->setPosition(centerX, centerY);
	line->setOrigin(length / 2, LINE_WIDTH / 2);
	line->setRotation(angle);
	return line;
}

