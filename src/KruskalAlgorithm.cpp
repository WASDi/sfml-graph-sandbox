#include "KruskalAlgorithm.h"
#include "Util.h"

#include <stdio.h>
#include <SFML/Graphics/Color.hpp>
#include <set>

KruskalAlgorithm::KruskalAlgorithm(std::list<Vertex*> vertices, std::list<Edge*> edges) :
vertices(vertices),
edges(edges) {
	this->edges.sort(Edge::shortestFirstComparator);
}

void KruskalAlgorithm::execute() {
	std::map<int, std::set<int>*> vertex2disjointSet = std::map<int, std::set<int>*>();

	for (auto& vertex : this->vertices) {
		std::set<int>* disjointSet = new std::set<int>();
		disjointSet->insert(vertex->idx);
		vertex2disjointSet.insert(std::make_pair(vertex->idx, disjointSet));
	}

	for (auto& edge : this->edges) {
		std::set<int>* fromSet = vertex2disjointSet[edge->from->idx];
		std::set<int>* toSet = vertex2disjointSet[edge->to->idx];
		if (fromSet == toSet) {
			// this edge is SHIT
			edge->shape->setFillColor(sf::Color(211, 211, 211));
		} else {
			// this edge is NICE
			edge->shape->setFillColor(sf::Color::Black);
			// merge sets!
			// add everything in fromSet to toSet
			toSet->insert(fromSet->begin(), fromSet->end());
			// make everything in "from" point to "to"
			for (const int idx : *fromSet) {
				vertex2disjointSet.erase(idx);
				vertex2disjointSet.insert(std::make_pair(idx, toSet));
			}
		}
	}

	for (const auto& any : vertex2disjointSet) {
		int vertexIdx = any.first;
		std::set<int>* set = any.second;
	}
}
