// Copyright 2022 Narlyeev Parahat

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/mst_finder.h"

int main(int argc, const char** argv) {
    MSTFinder app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
