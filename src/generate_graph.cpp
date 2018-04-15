#include "Vertex.h"
#include "Edge.h"
#include "Util.h"
#include <SFML/Graphics/Shape.hpp>
#include <list>
#include <SFML/Graphics/RectangleShape.hpp>

#define NUM_VERTICES 60
#define CIRCLE_RADIUS 15
#define LINE_WIDTH 4

#define TOO_CLOSE_THRESHOLD 40
#define CONNETED_THRESHOLD 150

std::list<Vertex*> generateVertices(const int WIDTH, const int HEIGHT, const int MARGIN) {
	std::list<Vertex*> vertices;
	for (int i = 0; i < NUM_VERTICES; i++) {
		sf::Shape* shape = new sf::CircleShape(CIRCLE_RADIUS);
		shape->setOrigin(CIRCLE_RADIUS, CIRCLE_RADIUS);
		shape->setPosition(
				MARGIN + Util::randf()*(WIDTH - CIRCLE_RADIUS * 2 - MARGIN * 2),
				MARGIN + Util::randf()*(HEIGHT - CIRCLE_RADIUS * 2 - MARGIN * 2)
				);
		shape->setFillColor(sf::Color::Green);
		shape->setOutlineThickness(1);
		shape->setOutlineColor(sf::Color(250, 150, 100));
		Vertex* vertex = new Vertex(i + 1, shape);
		vertices.push_back(vertex);
	}

	std::list<Vertex*> toRemove;
	int idx = 0;

	for (auto& vertex : vertices) {
		std::list<Vertex*>::iterator others = vertices.begin();
		for (std::advance(others, idx + 1); others != vertices.end(); ++others) {
			Vertex* other = *others;
			float dist = Util::distance(&vertex->shape->getPosition(), &other->shape->getPosition());
			if (dist < TOO_CLOSE_THRESHOLD) {
				toRemove.push_back(vertex);
				break;
			}
		}

		idx++;
	}

	for (auto& vertex : toRemove) {
		vertices.remove(vertex);
		delete vertex;
	}

	return vertices;
}

sf::RectangleShape* lineBetween(const sf::Vector2f a, const sf::Vector2f b) {
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

std::list<sf::RectangleShape*> generateEdges(std::list<Vertex*>* verticesPtr) {
	std::list<Vertex*> vertices = *verticesPtr;
	std::list<sf::RectangleShape*> edges;
	
	int idx = 0;
	for (auto& vertex : vertices) {
		std::list<Vertex*>::iterator others = vertices.begin();
		for (std::advance(others, idx + 1); others != vertices.end(); ++others) {
			Vertex* other = *others;
			float dist = Util::distance(&vertex->shape->getPosition(), &other->shape->getPosition());
			if (dist < CONNETED_THRESHOLD) {
				sf::RectangleShape* line = lineBetween(vertex->shape->getPosition(), other->shape->getPosition());
				edges.push_back(line);
			}
		}
		
		idx++;
	}
	
	Edge* kuk = new Edge(vertices.front(), vertices.back());
	
	// Make planar
	std::list<sf::RectangleShape*> toRemove;
	for(auto& edge : edges) {
		std::list<sf::RectangleShape*>::iterator others = edges.begin();
		for (std::advance(others, idx + 1); others != edges.end(); ++others) {
			sf::RectangleShape* other = *others;
			// TODO if edge cross "other"
			if (false) {
				toRemove.push_back(edge);
				break;
			}
		}
	}
	
	for (auto& edge : toRemove) {
		edges.remove(edge);
		delete edge;
	}

	return edges;
}