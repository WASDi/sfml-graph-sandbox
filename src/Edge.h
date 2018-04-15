#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"
#include <SFML/Graphics/Shape.hpp>

class Edge {
public:
	Edge(Vertex* from, Vertex* to);
	~Edge();
	
	bool sharesVertexWith(Edge* that);
	bool intersects(Edge* that);

	Vertex* from;
	Vertex* to;

	sf::Shape* shape;

private:

	sf::Shape* generateShape();

};

#endif /* EDGE_H */

