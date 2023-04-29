#include "pch.h"
#include "testPoint2D.cpp"
#include "testArena.cpp"
#include "testPredator.cpp"
#include "testPrey.cpp"


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}