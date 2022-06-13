// Copyright 2022 Koshelev Sergey

#ifndef MODULES_KOSHELEV_SQUARE_INCLUDE_SQUARE_H_
#define MODULES_KOSHELEV_SQUARE_INCLUDE_SQUARE_H_

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

struct Circle {
    long double x;
    long double y;
    long double r;
};

class AreaCalculator {
 private:
     static void SortDescending2(long double* a, long double* b);
     static void SortDescending3(long double* a, long double* b,
         long double* c);
     static long double KahanAreaOfTriangle(long double a,
         long double b, long double c);

 public:
     static long double Pi();
     static long double Square(long double x);
     static long double AreaOfIntersection(const Circle& c1,
         const Circle& c2);
};

#endif  // MODULES_KOSHELEV_SQUARE_INCLUDE_SQUARE_H_
