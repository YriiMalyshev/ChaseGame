#include "pch.h"
#include "../Characters.h"

TEST(PredatorTest, MoveToValidPoint) {
    Predator predator("Predator1", Point2D(0, 0), false);
    predator.moveTo(2, 3); // Движение вниз на 3 клетки
    EXPECT_EQ(predator.getX(), 0);
    EXPECT_EQ(predator.getY(), 3);
}

TEST(PredatorTest, MoveToInvalidDirection) {
    Predator predator("Predator1", Point2D(0, 0), false);
    predator.moveTo(8, 3); // Движение в несуществующем направлении
    EXPECT_EQ(predator.getX(), 0);
    EXPECT_EQ(predator.getY(), 0);
}

TEST(PredatorTest, MoveToInvalidSteps) {
    Predator predator("Predator1", Point2D(0, 0), false);
    predator.moveTo(1, -3); // Движение на отрицательное количество клеток
    EXPECT_EQ(predator.getX(), 0);
    EXPECT_EQ(predator.getY(), 0);
}

TEST(PredatorTest, AskRangeValidInput) {
    Predator predator("Predator1", Point2D(0, 0), false);
    std::istringstream input("3\n");
    std::cin.rdbuf(input.rdbuf());
    int range = predator.askRange();
    EXPECT_EQ(range, 3);
}

TEST(PredatorTest, AskRangeInvalidInput) {
    Predator predator("Predator1", Point2D(0, 0), false);
    std::istringstream input("invalid\n5\n");
    std::cin.rdbuf(input.rdbuf());
    int range = predator.askRange();
    EXPECT_EQ(range, 5);
}

TEST(PredatorTest, AskDirectionValidInput) {
    Predator predator("Predator1", Point2D(0, 0), false);
    std::istringstream input("1\n");
    std::cin.rdbuf(input.rdbuf());
    int direction = predator.askDirection();
    EXPECT_EQ(direction, 1);
}

TEST(PredatorTest, AskDirectionInvalidInput) {
    Predator predator("Predator1", Point2D(0, 0), false);
    std::istringstream input("invalid\n2\n");
    std::cin.rdbuf(input.rdbuf());
    int direction = predator.askDirection();
    EXPECT_EQ(direction, 2);
}

TEST(PredatorTest, AutoMove) {
    Predator predator("Predator1", Point2D(0, 0), true);
    predator.autoMove();
    EXPECT_GE(predator.getX(), -5);
    EXPECT_LE(predator.getX(), 5);
    EXPECT_GE(predator.getY(), -5);
    EXPECT_LE(predator.getY(), 5);
}
