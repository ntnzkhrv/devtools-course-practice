// Copyright 2022 Podovinnikov Artyom

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
    PermutationsApp app;
    std::string output = app(argc, argv);
    std::cout << output << "\n";
    return 0;
}
