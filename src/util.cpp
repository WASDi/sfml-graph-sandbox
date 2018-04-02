#include <SFML/System/Vector2.hpp>
#include <random>

float distance(const sf::Vector2f* a, const sf::Vector2f* b) {
	float dx = a->x - b-> x;
	float dy = a->y - b-> y;
	return sqrtf(dx * dx + dy * dy);
}

void init_rand() {
	srand(time(NULL));
}

float randf() {
	return (float) rand() / (float) ((unsigned) RAND_MAX + 1);
}