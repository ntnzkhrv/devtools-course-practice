// Copyright 2022 Lukashuk Diana

#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <vector>

#include "include/PermutationGeneration.h"

bool equality(int *mas1, int *mas2, int size) {
  for (int i = 0; i < size; i++) {
    if (mas1[i] != mas2[i]) return false;
  }
  return true;
}

PermutationGeneration test_constr_cop(PermutationGeneration pg) { return pg; }

TEST(Lukashuk_Diana_Memory_Test, check_defolt_constructor) {
  PermutationGeneration a;
  EXPECT_EQ(a.get_size_inp(), 0);
}

TEST(Lukashuk_Diana_Memory_Test, check_dm_and_size_constructor) {
  int *in = new int[3]{0, 1, 2};
  PermutationGeneration a(in, 3);
  PermutationGeneration b;
  delete[] in;
  EXPECT_EQ(a.get_size_inp(), 3);
  EXPECT_EQ(b.get_size_inp(), 0);
}

TEST(Lukashuk_Diana_Memory_Test, check_constructor_cop) {
  int *in = new int[3]{0, 1, 2};
  PermutationGeneration a(in, 3);
  delete[] in;
  PermutationGeneration b;
  ASSERT_NO_THROW(test_constr_cop(a));
  ASSERT_NO_THROW(test_constr_cop(b));
}

TEST(Lukashuk_Diana_functions, factorial) {
  EXPECT_EQ(factorial(0), 1);
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(4), 24);
}

TEST(Lukashuk_Diana_functions, equality_mas) {
  {
    int *in = new int[3]{0, 2, 1};
    int *in1 = new int[3]{0, 2, 1};
    EXPECT_EQ(equality(in, in1, 3), true);
    delete[] in;
    delete[] in1;
  }
  {
    int *in = new int[3]{0, 1, 2};
    int *in1 = new int[3]{0, 2, 1};
    EXPECT_EQ(equality(in, in1, 3), 0);
    delete[] in;
    delete[] in1;
  }
  {
    int *in = new int[3]{0, 1, 2};
    int *in1 = new int[3]{0, 0, 0};
    EXPECT_EQ(equality(in, in1, 3), 0);
    delete[] in;
    delete[] in1;
  }
}

TEST(Lukashuk_Diana_functions, sort_mas) {
  {
    int *in = new int[3]{0, 2, 1};
    sort_mas(in, 3);
    EXPECT_EQ(in[0], 0);
    EXPECT_EQ(in[1], 1);
    EXPECT_EQ(in[2], 2);
    delete[] in;
  }

  {
    int *in = new int[3]{0, 0, 1};
    sort_mas(in, 3);
    EXPECT_EQ(in[0], 0);
    EXPECT_EQ(in[1], 0);
    EXPECT_EQ(in[2], 1);
    delete[] in;
  }

  {
    int *in = new int[3]{2, 3, 1};
    sort_mas(in, 3);
    EXPECT_EQ(in[0], 1);
    EXPECT_EQ(in[1], 2);
    EXPECT_EQ(in[2], 3);
    delete[] in;
  }
}

TEST(Lukashuk_Diana_functions, res_pg) {
  {
    int *in = new int[1]{0};
    PermutationGeneration a(in, 1);
    delete[] in;
    a.do_res();
    int **r = a.get_res();
    EXPECT_EQ(a.get_size_res(), 1);
    EXPECT_EQ(r[0][0], 0);
    for (int i = 0; i < a.get_size_res(); i++) delete[] r[i];
    delete[] r;
  }
  {
    int *in = new int[3]{0, 1, 2};
    PermutationGeneration a(in, 3);
    PermutationGeneration b;

    a.do_res();
    int **r = a.get_res();
    int **r1 = b.get_res();

    int **res = new int *[a.get_size_res()];
    res[0] = new int[a.get_size_inp()]{0, 1, 2};
    res[1] = new int[a.get_size_inp()]{0, 2, 1};
    res[2] = new int[a.get_size_inp()]{1, 0, 2};
    res[3] = new int[a.get_size_inp()]{1, 2, 0};
    res[4] = new int[a.get_size_inp()]{2, 0, 1};
    res[5] = new int[a.get_size_inp()]{2, 1, 0};
    EXPECT_EQ(a.get_size_res(), 6);
    EXPECT_EQ(r1, nullptr);
    EXPECT_TRUE(equality(r[0], res[0], a.get_size_inp()));
    EXPECT_TRUE(equality(r[1], res[1], a.get_size_inp()));
    EXPECT_TRUE(equality(r[2], res[2], a.get_size_inp()));
    EXPECT_TRUE(equality(r[3], res[3], a.get_size_inp()));
    EXPECT_TRUE(equality(r[4], res[4], a.get_size_inp()));
    EXPECT_TRUE(equality(r[5], res[5], a.get_size_inp()));

    for (int i = 0; i < a.get_size_res(); i++) delete[] r[i];
    for (int i = 0; i < a.get_size_res(); i++) delete[] res[i];
    delete[] in;
    delete[] r;
    delete[] res;
  }
}
