#ifndef KRUSKALALGORITHM_H
#define KRUSKALALGORITHM_H

#include "Vertex.h"
#include "Edge.h"
#include <list>

class KruskalAlgorithm {
public:
	KruskalAlgorithm(std::list<Vertex*> vertices, std::list<Edge*> edges);
	void execute();
private:
	std::list<Vertex*> vertices;
	std::list<Edge*> edges;

};

#endif /* KRUSKALALGORITHM_H */

