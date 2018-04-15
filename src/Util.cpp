#include <math.h>
#include <random>

#include "Util.h"

Util::Util() {
}

float Util::distance(const sf::Vector2f* a, const sf::Vector2f* b) {
	float dx = a->x - b-> x;
	float dy = a->y - b-> y;
	return sqrtf(dx * dx + dy * dy);
}

void Util::init_rand() {
	srand(time(NULL));
}

float Util::randf() {
	return (float) rand() / (float) ((unsigned) RAND_MAX + 1);
}

