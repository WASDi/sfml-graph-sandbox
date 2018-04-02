#ifndef VERTEX_H
#define VERTEX_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Vertex {
public:

	static sf::Font* font;

	Vertex(int idx, sf::Shape* shape);
	~Vertex();

	int idx;
	sf::Shape* shape;
	sf::Text* text;

private:
};

#endif /* VERTEX_H */

