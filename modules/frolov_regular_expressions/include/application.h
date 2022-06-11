// Copyright 2022 Shilov Roman

#ifndef MODULES_FROLOV_REGULAR_EXPRESSIONS_INCLUDE_APPLICATION_H_
#define MODULES_FROLOV_REGULAR_EXPRESSIONS_INCLUDE_APPLICATION_H_

#include <array>
#include <string>
#include <vector>

class Text_for_regexp_app {
 public:
  Text_for_regexp_app();
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_FROLOV_REGULAR_EXPRESSIONS_INCLUDE_APPLICATION_H_
