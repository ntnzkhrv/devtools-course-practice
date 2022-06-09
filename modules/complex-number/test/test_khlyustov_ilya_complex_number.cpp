// Copyright 2022 Ilya "Riladavin" Khlyustov

#include <gtest/gtest.h>
#include <string>

#include "include/complex_number.h"

TEST(KhlyustovIlyaComplexNumberTest, DefaultConstructor) {
  ASSERT_NO_THROW(ComplexNumber());
}

TEST(KhlyustovIlyaComplexNumberTest, ParameterizedConstructor) {
  ASSERT_NO_THROW(ComplexNumber(1.0, 2.0));
}

TEST(KhlyustovIlyaComplexNumberTest, CopyConstructor) {
  ASSERT_NO_THROW(ComplexNumber(ComplexNumber()));
}

TEST(KhlyustovIlyaComplexNumberTest, AssignmentOperator) {
  auto origin = ComplexNumber(1.0, 2.0);
  auto copy = ComplexNumber();
  ASSERT_NO_THROW(copy = origin);
}

TEST(KhlyustovIlyaComplexNumberTest, EqualityOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(1.0, 2.0);
  ASSERT_EQ(first, second);
}

TEST(KhlyustovIlyaComplexNumberTest, CopyEqualsToOrigin) {
  auto origin = ComplexNumber(1.0, 2.0);
  auto copy = origin;
  ASSERT_EQ(origin, copy);
}

TEST(KhlyustovIlyaComplexNumberTest, InequalityOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  ASSERT_NE(first, second);
}

TEST(KhlyustovIlyaComplexNumberTest, AdditionOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto sum = first + second;
  ASSERT_EQ(sum, ComplexNumber(4.0, 6.0));
}

TEST(KhlyustovIlyaComplexNumberTest, SubtractionOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto sub = first - second;
  ASSERT_EQ(sub, ComplexNumber(-2.0, -2.0));
}

TEST(KhlyustovIlyaComplexNumberTest, MultiplicationOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto product = first * second;
  ASSERT_EQ(product, ComplexNumber(-5.0, 10.0));
}

TEST(KhlyustovIlyaComplexNumberTest, DivisionOperator) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber(3.0, 4.0);
  auto division = first / second;
  ASSERT_EQ(division, ComplexNumber(0.44, 0.08));
}

TEST(KhlyustovIlyaComplexNumberTest, DivisionByZeroError) {
  auto first = ComplexNumber(1.0, 2.0);
  auto second = ComplexNumber();
  ASSERT_THROW(first / second, std::string);
}
