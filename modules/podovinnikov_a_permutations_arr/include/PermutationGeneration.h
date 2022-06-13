// Copyright 2022 Podovinnikov Artyom

#ifndef MODULES_PODOVINNIKOV_A_PERMUTATIONS_ARR_INCLUDE_PERMUTATIONGENERATION_H_
#define MODULES_PODOVINNIKOV_A_PERMUTATIONS_ARR_INCLUDE_PERMUTATIONGENERATION_H_

#include <iostream>

class PermutationGeneration {
 private:
  int* inp;
  int** res;
  int size_inp;
  int size_res;

 public:
  void do_res();
  PermutationGeneration();
  PermutationGeneration(int* input, int size);
  PermutationGeneration(const PermutationGeneration& pg);

  int get_size_inp();
  int get_size_res();
  int** get_res();

  void viv() {
    for (int j = 0; j < size_res; j++) {
      for (int i = 0; i < size_inp; i++) {
        std::cout << res[j][i] << " ";
      }
      std::cout << "\n";
    }
  }
  ~PermutationGeneration();
};

PermutationGeneration test_constr_cop(PermutationGeneration pg);
int factorial(int number);
void sort_mas(int* mas, int size);
bool equality(int* mas1, int* mas2, int size);
#endif  // MODULES_PODOVINNIKOV_A_PERMUTATIONS_ARR_INCLUDE_PERMUTATIONGENERATION_H_
