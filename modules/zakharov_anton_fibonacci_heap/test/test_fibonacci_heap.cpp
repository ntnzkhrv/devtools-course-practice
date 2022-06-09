// Copyright 2022 Zakharov Anton

#include <gtest/gtest.h>
#include "include/fibonacci_heap.h"


TEST(FibonacciHeap, Can_create_int_heap) {
  // Arrange, Act, Assert
  ASSERT_NO_THROW(FibonacciHeap<int>());
}

TEST(FibonacciHeap, Can_insert_value) {
  // Arrange
    FibonacciHeap<int> a;

  // Act, Assert
  ASSERT_NO_THROW(a.insert(27));
}

TEST(FibonacciHeap, Can_insert_otr_value) {
    // Arrange
    FibonacciHeap<int> a;

    // Act, Assert
    ASSERT_NO_THROW(a.insert(-7));
}

TEST(FibonacciHeap, Can_insert_zerro_value) {
    // Arrange
    FibonacciHeap<int> a;

    // Act, Assert
    ASSERT_NO_THROW(a.insert(0));
}