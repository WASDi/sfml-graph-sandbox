#include <SFML/Graphics.hpp>
#include <complex>
#include <list>
#include "generate_graph.cpp"
#include "Vertex.h"

#define WIDTH 800
#define HEIGHT 800
#define MARGIN 20

#define UPDATE_INTERVAL 4.0

// TODO make into class
// TODO separate logic and graphics
int main() {
	Util::init_rand();
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My cool graphs!");
	window.setVerticalSyncEnabled(true);

	auto vertices = generateVertices(WIDTH, HEIGHT, MARGIN);
	auto edges = generateEdges(&vertices);

	sf::Clock deltaClock;
	sf::Clock totalClock;
	float nextUpdate = UPDATE_INTERVAL;
	while (window.isOpen()) {
		float deltaTime = deltaClock.restart().asSeconds();
		float totalTime = totalClock.getElapsedTime().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
				printf("Close!\n");
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				// UPDATE
				while (!vertices.empty()) delete vertices.front(), vertices.pop_front();
				while (!edges.empty()) delete edges.front(), edges.pop_front();
				vertices = generateVertices(WIDTH, HEIGHT, MARGIN);
				edges = generateEdges(&vertices);
			}
		}

		if (totalTime > nextUpdate) {
			// Here something can be run every UPDATE_INTERVAL seconds
			nextUpdate = totalTime + UPDATE_INTERVAL;
		}

		window.clear(sf::Color(222, 222, 222));

		for (auto& edge : edges) {
			window.draw(*edge);
		}

		for (auto& vertex : vertices) {
			window.draw(*vertex->shape);
			window.draw(*vertex->text);
		}

		window.display();
	}

	return 0;
}