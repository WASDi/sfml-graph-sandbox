#include "GraphGenerator.h"

#include "Vertex.h"
#include "Edge.h"
#include "Util.h"
#include <list>

#define NUM_VERTICES 60
#define TOO_CLOSE_THRESHOLD 50
#define CONNETED_THRESHOLD 200

GraphGenerator::GraphGenerator(const int windowWidth, const int windowHeight, const int windowMargin) :
windowWidth(windowWidth),
windowHeight(windowHeight),
windowMargin(windowMargin) {
}

std::list<Vertex*> GraphGenerator::generateVertices() {
	std::list<Vertex*> vertices;
	for (int i = 0; i < NUM_VERTICES; i++) {
		float x = this->windowMargin + Util::randf()*(this->windowWidth - this->windowMargin * 2);
		float y = this->windowMargin + Util::randf()*(this->windowHeight - this->windowMargin * 2);
		Vertex* vertex = new Vertex(i + 1, x, y);
		vertices.push_back(vertex);
	}

	std::list<Vertex*> toRemove;
	int idx = 0;

	for (auto& vertex : vertices) {
		std::list<Vertex*>::iterator others = vertices.begin();
		for (std::advance(others, idx + 1); others != vertices.end(); ++others) {
			Vertex* other = *others;
			float dist = Util::distance(vertex->getPosition(), other->getPosition());
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

std::list<Edge*> GraphGenerator::generateEdges(std::list<Vertex*>* verticesPtr) {
	std::list<Vertex*> vertices = *verticesPtr;
	std::list<Edge*> edges;

	int idx = 0;
	for (auto& vertex : vertices) {
		std::list<Vertex*>::iterator others = vertices.begin();
		for (std::advance(others, idx + 1); others != vertices.end(); ++others) {
			Vertex* other = *others;
			float dist = Util::distance(vertex->getPosition(), other->getPosition());
			if (dist < CONNETED_THRESHOLD) {
				Edge* edge = new Edge(vertex, other);
				edges.push_back(edge);
			}
		}

		idx++;
	}

	// Make planar
	std::list<Edge*> toRemove;
	idx = 0;
	for (auto& edge : edges) {
		std::list<Edge*>::iterator others = edges.begin();
		for (std::advance(others, idx + 1); others != edges.end(); ++others) {
			Edge* other = *others;
			if (edge->sharesVertexWith(other)) {
				continue;
			} else if (edge->intersects(other)) {
				toRemove.push_back(edge);
				break;
			}
		}
		idx++;
	}

	for (auto& edge : toRemove) {
		edges.remove(edge);
		delete edge;
	}

	// TODO would look nice to remove edges that are *almost* parallel by per vertex, checking the angles of its connected edges

	return edges;
}