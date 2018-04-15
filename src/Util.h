#ifndef UTIL_H
#define UTIL_H

#include <SFML/System/Vector2.hpp>

class Util {
public:

	static float distance(const sf::Vector2f* a, const sf::Vector2f* b);
	static bool intersects(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y);
	
	static void init_rand();
	static float randf();
	
private:
	Util();
};

#endif /* UTIL_H */

