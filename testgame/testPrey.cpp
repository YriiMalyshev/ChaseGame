#include "pch.h"
#include "../Characters.h"

TEST(PreyTest, ConstructorTest) {
    string name = "Prey1";
    Point2D location(1, 1);
    bool npcFlag = false;

    Prey prey(name, location, npcFlag);

    EXPECT_EQ(prey.getName(), name);
    EXPECT_EQ(prey.getLocation().getX(), location.getX());
    EXPECT_EQ(prey.getLocation().getY(), location.getY());
    EXPECT_EQ(prey.isNPC(), npcFlag);
}

TEST(PreyTest, MoveToTest) {
    Point2D location(0, 0);
    Prey character("John", location, false);
    character.moveTo(Point2D(5, 5));
    EXPECT_EQ(character.getLocation().getX(), 5);
    EXPECT_EQ(character.getLocation().getY(), 5);
}

TEST(PreyTest, MoveToDirectionTest) {
    Point2D location(0, 0);
    Prey character("John", location, false);
    character.moveTo(1, 3);
    EXPECT_EQ(character.getLocation().getX(), 3);
    EXPECT_EQ(character.getLocation().getY(), 0);
}

TEST(PreyTest, IsNPCTest) {
    Point2D location(0, 0);
    Prey character("John", location, true);
    EXPECT_TRUE(character.isNPC());
}

TEST(PreyTest, AskDirectionTest) {
    Point2D location(0, 0);
    Prey prey("Rabbit", location, false);
    // Заменим стандартный ввод на ввод из строки
    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(prey.askDirection(), 1);
}

TEST(PreyTest, AutoMoveTest) {
    Point2D location(0, 0);
    Prey prey("Rabbit", location, false);
    prey.autoMove();
    EXPECT_NE(prey.getLocation().getX(), 0);
    EXPECT_NE(prey.getLocation().getY(), 0);
}

int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}