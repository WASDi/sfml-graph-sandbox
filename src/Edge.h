#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"
#include <SFML/Graphics/Shape.hpp>

class Edge {
public:
	Edge(Vertex* from, Vertex* to);
	~Edge();
	
	static bool shortestFirstComparator(Edge* a, Edge* b);
	static bool longestFirstComparator(Edge* a, Edge* b);

	bool sharesVertexWith(Edge* that);
	float length();
	bool intersects(Edge* that);

	Vertex* from;
	Vertex* to;

	sf::Shape* shape;

private:

	sf::Shape* generateShape();

};

#endif /* EDGE_H */

