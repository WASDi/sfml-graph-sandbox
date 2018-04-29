#include "KruskalAlgorithm.h"
#include "Util.h"

#include <stdio.h>
#include <SFML/Graphics/Color.hpp>

KruskalAlgorithm::KruskalAlgorithm(std::list<Vertex*> vertices, std::list<Edge*> edges) :
vertices(vertices),
edges(edges) {
}

void KruskalAlgorithm::execute() {
	for (auto& vertex : this->vertices) {
		if (Util::randf() > 0.7) {
			vertex->shape->setFillColor(sf::Color::Blue);
		}
	}
	for (auto& edge : this->edges) {
		if (Util::randf() > 0.7) {
			edge->shape->setFillColor(sf::Color::Yellow);
		}
	}
}
