// Copyright 2022 Koshelev Sergey
#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "include/square.h"

TEST(AreaCalculatorTest, AreaOfIntersectionWorks) {
    Circle c1;
    Circle c2;
    ASSERT_NO_THROW(AreaCalculator::AreaOfIntersection(c1, c2));
}

TEST(AreaCalculatorTest, non_intersections_circles_return_0) {
    Circle c1;
    c1.x = 1;
    c1.y = 1;
    c1.r = 2;
    Circle c2;
    c2.x = 33;
    c2.y = 33;
    c2.r = 2;
    ASSERT_EQ(AreaCalculator::AreaOfIntersection(c1, c2), 0);
}

TEST(AreaCalculatorTest, matching_circles) {
    Circle c1;
    c1.x = 1;
    c1.y = 1;
    c1.r = 2;
    Circle c2;
    c2.x = 1;
    c2.y = 1;
    c2.r = 2;
    long double area = AreaCalculator::Pi() * AreaCalculator::Square(c1.r);
    ASSERT_DOUBLE_EQ(std::round(AreaCalculator::AreaOfIntersection(c1, c2)
    *100)/100, std::round(area*100)/100);
}

TEST(AreaCalculatorTest, matching_circles2) {
    Circle c1;
    c1.x = 1;
    c1.y = 1;
    c1.r = 2;
    Circle c2;
    c2.x = 1;
    c2.y = 1;
    c2.r = 2;
    long double area = AreaCalculator::Pi() * AreaCalculator::Square(c2.r);
    ASSERT_DOUBLE_EQ(std::round(AreaCalculator::AreaOfIntersection(c1, c2)
    *100)/100, std::round(area*100)/100);
}

TEST(AreaCalculatorTest, second_circle_in_first) {
    Circle c1;
    c1.x = 1;
    c1.y = 1;
    c1.r = 1;
    Circle c2;
    c2.x = 1;
    c2.y = 1;
    c2.r = 2;
    long double area = AreaCalculator::Pi() * AreaCalculator::Square(c1.r);
    ASSERT_DOUBLE_EQ(std::round(AreaCalculator::AreaOfIntersection(c1, c2)
    *100)/100, std::round(area*100)/100);
}

TEST(AreaCalculatorTest, intersected_circles) {
    Circle c1;
    c1.x = 5;
    c1.y = 0;
    c1.r = 5;
    Circle c2;
    c2.x = -3;
    c2.y = 0;
    c2.r = 5;
    long double area = AreaCalculator::AreaOfIntersection(c1, c2);
    ASSERT_DOUBLE_EQ(std::round(area*100)/100,
    std::round(8.1750554396642201*100)/100);
}

TEST(AreaCalculatorTest, intersected_circles2) {
    Circle c1;
    c1.x = 5;
    c1.y = 20;
    c1.r = 8;
    Circle c2;
    c2.x = -3;
    c2.y = 35;
    c2.r = 10;
    long double area = AreaCalculator::AreaOfIntersection(c2, c1);
    ASSERT_DOUBLE_EQ(std::round(area*100)/100,
    std::round(3.9401951425039785*100)/100);
}

TEST(AreaCalculatorTest, circles_touch) {
    Circle c1;
    c1.x = 5;
    c1.y = 0;
    c1.r = 5;
    Circle c2;
    c2.x = -5;
    c2.y = 0;
    c2.r = 5;
    long double area = AreaCalculator::AreaOfIntersection(c2, c1);
    ASSERT_DOUBLE_EQ(area, 0);
}
