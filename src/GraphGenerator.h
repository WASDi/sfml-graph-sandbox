#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include "Vertex.h"
#include "Edge.h"
#include <list>

class GraphGenerator {
public:
	GraphGenerator(const int windowWidth, const int windowHeight, const int windowMargin);
	std::list<Vertex*> generateVertices();
	std::list<Edge*> generateEdges(std::list<Vertex*>* verticesPtr);
private:

	const int windowWidth;
	const int windowHeight;
	const int windowMargin;

};

#endif /* GRAPHGENERATOR_H */

