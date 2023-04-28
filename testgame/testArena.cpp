#include "pch.h"
#include "../Arena.h"

TEST(ArenaTest, ArenaCreation) {
	Prey prey (" ", Point2D(3,3), true);
	Predator predator (" ", Point2D(6, 3), true);
	ASSERT_NO_THROW(Arena arena(10, 20, &prey, &predator));
}

TEST(ArenaTest, ArenaInvalidDimensions) {
	Prey prey(" ", Point2D(3, 3), true);
	Predator predator(" ", Point2D(6, 3), true);
	ASSERT_THROW(Arena arena(0, 10, &prey, &predator), std::invalid_argument);
	ASSERT_THROW(Arena arena(100, 10, &prey, &predator), std::invalid_argument);
	ASSERT_THROW(Arena arena(10, 0, &prey, &predator), std::invalid_argument);
	ASSERT_THROW(Arena arena(10, 100, &prey, &predator), std::invalid_argument);
}

//TEST(ArenaTest, ArenaClearStep) {
//	Prey prey(" ", Point2D(3, 3), true);;
//	Point2D prey_location(2, 2);
//	prey.setLocation(prey_location);
//
//	Predator predator;
//	Point2D predator_location(5, 6);
//	predator.setLocation(predator_location);
//
//	Arena arena(10, 20, &prey, &predator);
//
//	arena.clearStep();
//	ASSERT_EQ(arena.field[8][6], ' ');
//	ASSERT_EQ(arena.field[8][5], ' ');
//	ASSERT_EQ(arena.field[7][13], ' ');
//	ASSERT_EQ(arena.field[7][12], ' ');
//}

//TEST(ArenaTest, ArenaCheckOverRun) {
//	Prey prey;
//	Location prey_location(-1, 5);
//	prey.setLocation(prey_location);
//
//	Predator predator;
//	Location predator_location(2, 101);
//	predator.setLocation(predator_location);
//
//	Arena arena(10, 20, &prey, &predator);
//
//	ASSERT_TRUE(arena.checkOverRun());
//}
