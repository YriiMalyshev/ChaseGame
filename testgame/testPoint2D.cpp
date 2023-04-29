#pragma once

#include "../Point2D.h"
#include "pch.h"

// ���������, ��� ����������� ������������� ���������� �������� x � y
TEST(Point2DTest, Constructor) {
    Point2D p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

// ���������, ��� ����� setPoint ������������� ���������� �������� x � y
TEST(Point2DTest, SetPoint) {
    Point2D p;
    p.setPoint(5, 6);
    EXPECT_EQ(p.getX(), 5);
    EXPECT_EQ(p.getY(), 6);
}

// ���������, ��� �������� == �������� ��������� ��� ���� �����
TEST(Point2DTest, OperatorEquals) {
    Point2D p1(2, 3);
    Point2D p2(2, 3);
    Point2D p3(4, 5);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

// ���������, ��� �������� << ������� ���������� ������
TEST(Point2DTest, OperatorOutput) {
    Point2D p(2, 3);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ(ss.str(), "(2, 3)");
}
