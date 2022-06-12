// Copyright 2022 Zakharov Anton

#include <gtest/gtest.h>
#include <vector>
#include "include/fib_heap.h"

TEST(FibHeapTest, can_create) {
    ASSERT_NO_THROW(FibHeap f);
}

TEST(FibHeapTest, can_insert) {
    FibHeap f;
    ASSERT_NO_THROW(f.insert(1));
}

TEST(FibHeapTest, can_extract_min) {
    FibHeap f;
    f.insert(1);
    ASSERT_NO_THROW(f.extract_min());
}

TEST(FibHeapTest, extract_min_works_correctly) {
    FibHeap f;
    f.insert(1);
    ASSERT_EQ(f.extract_min(), 1);
}

TEST(FibHeapTest, delete_node_works) {
    FibHeap f;
    FibHeapNode* node = f.insert(1);
    ASSERT_NO_THROW(f.delete_node(node));
}

TEST(FibHeapTest, fib_heap_works) {
    FibHeap f;
    std::vector<int> values =
    { 5, 19, 2, 14, 27, 43, 31, 0, 1, 42, 11, 4, 7, 9, 67, 21, 6 };
    std::vector<FibHeapNode*> nodes;
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        nodes.push_back(f.insert(values[i]));
    }
    for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
        f.delete_node(nodes[i]);
    }
    ASSERT_EQ(0, f.m_numOfNodes);
}

TEST(FibHeapTest, fib_heap_works2) {
    FibHeap f;
    std::vector<int> values =
    { 5, 19, 2, 14, 27, 43, 31, 0, 1, 42, 11, 4, 7, 9, 67, 21, 6 };
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        f.insert(values[i]);
    }
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        f.extract_min();
    }
    ASSERT_EQ(0, f.m_numOfNodes);
}

TEST(FibHeapTest, fib_heap_works3) {
    FibHeap f;
    std::vector<int> values =
    { 5, 19, 2, 14, 27, 43, 31, 0, 1, 42, 11, 4, 7, 9, 67, 21, 6 };
    std::vector<FibHeapNode*> nodes;
    for (int i = static_cast<int>(values.size()) - 1; i >= 0; i--) {
        nodes.push_back(f.insert(values[i]));
    }
    for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
        f.delete_node(nodes[i]);
    }
    ASSERT_EQ(0, f.m_numOfNodes);
}

TEST(FibHeapTest, fib_heap_works4) {
    FibHeap f;
    std::vector<int> values =
    { 5, 19, 2, 14, 27, 43, 31, 0, 1, 42, 11, 4, 7, 9, 67, 21, 6 };
    for (int i = static_cast<int>(values.size()) - 1; i >= 0; i--) {
        f.insert(values[i]);
    }
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        f.extract_min();
    }
    ASSERT_EQ(0, f.m_numOfNodes);
}
