// Copyright 2022 Koshelev Sergey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Koshelev_Sergey_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;
  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Koshelev_Sergey_ComplexNumberTest, Can_Imaginary_Nubmer) {
  double re = 0.0;
  double im = 7.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Koshelev_Sergey_ComplexNumberTest, Can_Create_Real_Nubmer) {
  double re = 14.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}
