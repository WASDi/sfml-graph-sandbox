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

bool Util::intersects(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y) {
	// https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
	float s1_x, s1_y, s2_x, s2_y;
	s1_x = p1_x - p0_x;
	s1_y = p1_y - p0_y;
	s2_x = p3_x - p2_x;
	s2_y = p3_y - p2_y;

	float s, t;
	s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
	t = (s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

	return (s >= 0 && s <= 1 && t >= 0 && t <= 1);
}

void Util::init_rand() {
	srand(time(NULL));
}

float Util::randf() {
	return (float) rand() / (float) ((unsigned) RAND_MAX + 1);
}

