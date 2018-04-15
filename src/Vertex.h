#ifndef VERTEX_H
#define VERTEX_H

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Vertex {
public:

	Vertex(int idx, float x, float y);
	~Vertex();

	const sf::Vector2f* getPosition();

	int idx;
	float x;
	float y;

	sf::Shape* shape;
	sf::Text* text;

private:
	static sf::Font* font;

	sf::Shape* generateShape();
	sf::Text* generateText();
};

#endif /* VERTEX_H */

