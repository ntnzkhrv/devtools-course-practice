// Copyright 2022 Podovinnikov Artyom

#ifndef MODULES_PODOVINNIKOV_A_PERMUTATIONS_ARR_INCLUDE_APPLICATION_H_
#define MODULES_PODOVINNIKOV_A_PERMUTATIONS_ARR_INCLUDE_APPLICATION_H_

#include <string>
#include "PermutationGeneration.h"

class PermutationsApp {
 public:
    std::string operator()(int argc, const char** argv);
 private:
    bool isValid(std::string* out, int argc, const char** argv);
    std::string help();
};

#endif  // MODULES_PODOVINNIKOV_A_PERMUTATIONS_ARR_INCLUDE_APPLICATION_H_
