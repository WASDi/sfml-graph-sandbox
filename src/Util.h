#ifndef UTIL_H
#define UTIL_H

#include <SFML/System/Vector2.hpp>

class Util {
public:

	static float distance(const sf::Vector2f* a, const sf::Vector2f* b);
	
	static void init_rand();
	static float randf();
	
private:
	Util();
};

#endif /* UTIL_H */

