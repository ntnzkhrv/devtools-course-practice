// Copyright 2022 Zakharov Anton

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Zakharov_Anton_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(Zakharov_Anton_ComplexNumberTest, Can_Sum) {
    double re1 = 1.0;
    double im1 = 2.0;
    double re2 = 1.0;
    double im2 = 2.0;
    ComplexNumber first(re1, im1);
    ComplexNumber second(re2, im2);

    ComplexNumber sum = first + second;

    EXPECT_EQ(2.0, sum.getRe());
    EXPECT_EQ(4.0, sum.getIm());
}
TEST(Zakharov_Anton_ComplexNumberTest, Can_Create_Minus) {
    ComplexNumber c1(2.0, 1.0);
    ComplexNumber c2(2.0, 3.0);
    ComplexNumber s1(0, -2);
    ComplexNumber result = c1 - c2;

    EXPECT_EQ(s1 == result, 1);
}
TEST(Zakharov_Anton_ComplexNumberTest, Can_Perform_Difference) {
    double a_re = 10.0;
    double a_im = 15.0;

    double b_re = 19.0;
    double b_im = 28.0;

    ComplexNumber a(a_re, a_im);
    ComplexNumber b(b_re, b_im);
    b = a - b;

    EXPECT_EQ(a_re - b_re, b.getRe());
    EXPECT_EQ(a_im - b_im, b.getIm());
}
