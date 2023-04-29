#include "pch.h"
#include "../Arena.h"



TEST(ArenaTest, ArenaCreation) {
	Prey* prey = new Prey("Poozik", Point2D(7, 5), true);
	Predator* predator = new Predator("Kozyavik", Point2D(3, 2), true);
	ASSERT_NO_THROW(Arena arena(10, 20, prey, predator));
}

TEST(ArenaTest, ArenaInvalidDimensions) {
	Prey* prey = new Prey("Poozik", Point2D(7, 5), true);
	Predator* predator = new Predator("Kozyavik", Point2D(3, 2), true);
	ASSERT_THROW(Arena arena(0, 10, prey, predator), std::invalid_argument);
	ASSERT_THROW(Arena arena(100, 10, prey, predator), std::invalid_argument);
	ASSERT_THROW(Arena arena(10, 0, prey, predator), std::invalid_argument);
	ASSERT_THROW(Arena arena(10, 100, prey, predator), std::invalid_argument);
}

