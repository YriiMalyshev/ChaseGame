#include "gtest/gtest.h"
#include "../Characters.h"


//TEST(CharacterTest, TestConstructor) {
//    Point2D loc(10, 10);
//    Character c("Alice", loc, false);
//    EXPECT_EQ(c.getLocation().getX(), 10);
//    EXPECT_EQ(c.getLocation().getY(), 10);
//    EXPECT_FALSE(c.isNPC());
//}
//
//TEST(CharacterTest, TestMoveTo) {
//    Point2D loc(10, 10);
//    Character c("Alice", loc, false);
//    Point2D newLoc(5, 5);
//    c.moveTo(newLoc);
//    EXPECT_EQ(c.getLocation().getX(), 5);
//    EXPECT_EQ(c.getLocation().getY(), 5);
//}
//
//TEST(CharacterTest, TestMoveToDirection) {
//    Point2D loc(10, 10);
//    Character c("Alice", loc, false);
//    c.moveTo(0, 2);
//    EXPECT_EQ(c.getLocation().getX(), 10);
//    EXPECT_EQ(c.getLocation().getY(), 12);
//    c.moveTo(1, 3);
//    EXPECT_EQ(c.getLocation().getX(), 13);
//    EXPECT_EQ(c.getLocation().getY(), 12);
//    c.moveTo(2, 4);
//    EXPECT_EQ(c.getLocation().getX(), 13);
//    EXPECT_EQ(c.getLocation().getY(), 8);
//    c.moveTo(3, 5);
//    EXPECT_EQ(c.getLocation().getX(), 8);
//    EXPECT_EQ(c.getLocation().getY(), 8);
//    c.moveTo(4, 1);
//    EXPECT_EQ(c.getLocation().getX(), 7);
//    EXPECT_EQ(c.getLocation().getY(), 9);
//    c.moveTo(5, 1);
//    EXPECT_EQ(c.getLocation().getX(), 8);
//    EXPECT_EQ(c.getLocation().getY(), 10);
//    c.moveTo(6, 1);
//    EXPECT_EQ(c.getLocation().getX(), 9);
//    EXPECT_EQ(c.getLocation().getY(), 9);
//    c.moveTo(7, 1);
//    EXPECT_EQ(c.getLocation().getX(), 8);
//    EXPECT_EQ(c.getLocation().getY(), 8);
//}

//TEST(PreyTest, TestConstructor) {
//    Point2D loc(10, 10);
//    Prey p("Bob", loc, true);
//    EXPECT_EQ(p.getLocation().getX(), 10);
//    EXPECT_EQ(p.getLocation().getY(), 10);
//    EXPECT_TRUE(p.isNPC());
//}
//
//// “ест на запрос направлени€ у пользовател€ необходимо тестировать вручную
//
//TEST(PreyTest, TestAutoMove) {
//    Point2D loc(10, 10);
//    Prey p("Bob", loc, true);
//    p.autoMove();
//    EXPECT_GE(p.getLocation().getX(), 5);
//    EXPECT_GE(p.getLocation().getY(), 5);
//    EXPECT_LE(p.getLocation().getX(), 15);
//    EXPECT_LE(p.getLocation().getY(), 15);
//}
