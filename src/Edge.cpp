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

bool Edge::shortestFirstComparator(Edge* a, Edge* b) {
	return a->length() < b->length();
}

bool Edge::longestFirstComparator(Edge* a, Edge* b) {
	return !shortestFirstComparator(a, b);
}

bool Edge::sharesVertexWith(Edge* that) {
	return this->from == that->from || this->from == that->to ||
			this->to == that->from || this->to == that->to;
}

float Edge::length() {
	return Util::distance(this->from->getPosition(), this->to->getPosition());
}

#define USE_STACKOVERFLOW_INSTEAD_OF_MY_SHITTY_ALGORITM true

bool Edge::intersects(Edge* that) {
	if (USE_STACKOVERFLOW_INSTEAD_OF_MY_SHITTY_ALGORITM) {
		const auto& p0 = this->from->getPosition();
		const auto& p1 = this->to->getPosition();
		const auto& p2 = that->from->getPosition();
		const auto& p3 = that->to->getPosition();
		return Util::intersects(p0->x, p0->y, p1->x, p1->y, p2->x, p2->y, p3->x, p3->y);
	}

	const sf::Vector2f a = *this->from->getPosition();
	const sf::Vector2f b = *this->to->getPosition();
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float k = dy / dx;
	float m = a.y - k * a.x;
	//y = kx+m

	float p1Sign = k * that->from->getPosition()->x + m - that->from->getPosition()->y;
	float p2Sign = k * that->to->getPosition()->x + m - that->to->getPosition()->y;

	if ((p1Sign > 0 && p2Sign < 0) || (p1Sign < 0 && p2Sign > 0)) {
		// BUG: Here we just know that "that" crosses the *infinitely extended* "this".
		return true;
	}
	return false;
}

#define LINE_WIDTH 5

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

