// Copyright 2022 Frolov Gleb

#ifndef MODULES_BULICHEVA_DARYA_BIL_INTERPOL_INCLUDE_APPLICATION_H_
#define MODULES_BULICHEVA_DARYA_BIL_INTERPOL_INCLUDE_APPLICATION_H_

#include <array>
#include <string>
#include <vector>

class BilInerpolApp {
 public:
  BilInerpolApp();
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_BULICHEVA_DARYA_BIL_INTERPOL_INCLUDE_APPLICATION_H_
