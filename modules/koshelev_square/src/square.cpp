// Copyright 2022 Koshelev Sergey
#include <algorithm>
#include "include/square.h"

long double AreaCalculator::Pi() {
    return std::acos(-1);
}

long double AreaCalculator::Square(long double x) {
    return x * x;
}

void AreaCalculator::SortDescending2(long double* a, long double* b) {
    if (a < b) {
        std::swap(*a, *b);
    }
}

void AreaCalculator::SortDescending3(long double* a,
  long double* b, long double* c) {
    SortDescending2(a, b);
    SortDescending2(b, c);
    SortDescending2(a, b);
}

long double AreaCalculator::KahanAreaOfTriangle(long double a,
  long double b, long double c) {
    SortDescending3(&a, &b, &c);
    return 0.25 * std::sqrt((a + (b + c)) * (c - (a - b)) * (c + (a - b)) *
        (a + (b - c)));
}

long double AreaCalculator::AreaOfIntersection(const Circle& c1,
  const Circle& c2) {
    long double R = c1.r;
    long double r = c2.r;
    long double d = std::hypot(c2.x - c1.x, c2.y - c1.y);
    if (R + r <= d) {
        return 0;
    }
    SortDescending2(&R, &r);
    if (d <= R - r) {
        return Pi() * Square(r);
    }
    long double area = 2 * KahanAreaOfTriangle(R, r, d);
    long double y = area / d;
    long double A = std::asin(y / R) * Square(R);
    long double a = std::asin(y / r);
    a *= Square(r);
    SortDescending2(&A, &a);
    return (A - area) + a;
}
