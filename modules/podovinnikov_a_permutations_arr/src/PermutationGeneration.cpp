// Copyright 2022 Lukashuk Diana

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "include/PermutationGeneration.h"

void sort_mas(int* mas, int size) {
  if (size > 0) {
    int dop;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (mas[i] > mas[j]) {
          dop = mas[i];
          mas[i] = mas[j];
          mas[j] = dop;
        }
      }
    }
  }
}

void PermutationGeneration::do_res() {
  sort_mas(inp, size_inp);
  int* size_level = new int[size_inp];
  for (int i = 0; i < size_inp; i++) {
    size_level[i] = factorial(size_inp - i - 1);
  }
  for (int column = 0; column < size_inp; column++) {
    int point = 0;
    int nom_min = 0;
    while (point != size_res) {
      for (int found_nom_min = 0; found_nom_min < column; found_nom_min++) {
        if (inp[nom_min] == res[point][found_nom_min]) {
          nom_min++;
          if (nom_min == size_inp) nom_min = 0;
          found_nom_min = 0;  // 21
        }
      }
      for (int a = 0; a < size_level[column]; a++) {
        res[point][column] = inp[nom_min];
        point++;
      }
      nom_min++;
      if (nom_min == size_inp) nom_min = 0;
    }
  }
  delete[] size_level;
}

PermutationGeneration::PermutationGeneration() {
  size_inp = 0;
  size_res = 0;
  inp = NULL;
  res = NULL;
}

PermutationGeneration::PermutationGeneration(int* input, int size) {
  if (size > 0) {
    size_inp = size;
    inp = new int[size];
    for (int j = 0; j < size_inp; j++) {
      inp[j] = input[j];
    }
    size_res = factorial(size);
    res = new int*[size_res];
    for (int i = 0; i < size_res; i++) {
      res[i] = new int[size_inp];
      for (int j = 0; j < size_inp; j++) {
        res[i][j] = 9;
      }
    }
  }
}

PermutationGeneration::PermutationGeneration(const PermutationGeneration& pg) {
    if (pg.size_inp > 0) {
      size_inp = pg.size_inp;
      inp = new int[size_inp];
      for (int j = 0; j < size_inp; j++) {
        inp[j] = pg.inp[j];
      }
      size_res = pg.size_res;
      res = new int*[size_res];
      for (int i = 0; i < size_res; i++) {
        res[i] = new int[size_inp];
        for (int j = 0; j < size_inp; j++) {
          res[i][j] = pg.res[i][j];
        }
      }
    } else {
      size_inp = 0;
      size_res = 0;
      inp = NULL;
      res = NULL;
    }
}

int PermutationGeneration::get_size_inp() { return size_inp; }

int PermutationGeneration::get_size_res() { return size_res; }

int** PermutationGeneration::get_res() {
  if (size_res > 0) {
    int** a = new int*[size_res];
    for (int i = 0; i < size_res; i++) {
      a[i] = new int[size_inp];
      for (int j = 0; j < size_inp; j++) {
        a[i][j] = res[i][j];
      }
    }
    return a;
  }
  return nullptr;
}

PermutationGeneration::~PermutationGeneration() {
  if (size_inp > 0) {
    delete[] inp;
    for (int i = 0; i < size_res; i++) delete[] res[i];
    delete[] res;
    size_inp = 0;
    size_res = 0;
  } else {
    size_inp = 0;
    size_res = 0;
  }
}

int factorial(int number) {
  int result = 1;
  for (int i = number; i > 1; i--) result = result * i;
  return result;
}
