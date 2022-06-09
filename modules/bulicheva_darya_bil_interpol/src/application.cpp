// Copyright 2022 Frolov Gleb

#include <string>
#include <sstream>
#include <vector>
#include "include/application.h"
#include "include/bil_interpol.h"

BilInerpolApp::BilInerpolApp() : message_("") {}

void BilInerpolApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is an application to bilinear interpolation.\n\n" +
    "You can interpolate only four values\n\n" +
    "Please provide arguments in the following format:\n" +
    appname + "<value_1>" + "<value_2>" + "<value_3>" + "<value_4>";
}

bool BilInerpolApp::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 5) {
    help(argv[0], "ERROR: Should be 4 arguments.\n\n");
    return false;
  }
  return true;
}

std::string BilInerpolApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  std::vector<double> values;
  for (int i = 1; i < argc; i++)
    values.push_back(std::stod(argv[i]));
  bilen_interpol bl(values);
  double res = bl.interpolate();
  message_ = "Result: " + std::to_string(res);
  return message_;
}
