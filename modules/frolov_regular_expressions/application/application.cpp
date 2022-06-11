// Copyright 2022 Shilov Roman

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/application.h"

int main(int argc, const char** argv) {
  Text_for_regexp_app app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
