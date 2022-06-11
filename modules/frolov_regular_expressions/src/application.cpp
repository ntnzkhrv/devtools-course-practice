// Copyright 2022 Shilov Roman

#include <string>
#include <sstream>
#include <vector>
#include "include/application.h"
#include "include/regular_expressions.h"

Text_for_regexp_app::Text_for_regexp_app() : message_("") {}

void Text_for_regexp_app::help(const char* appname, const char* message) {
  message_ = std::string(message) +
      "This is an application to looking for a regular expression.\n\n" +
      "Enter text as the first argument.\n\n" +
      "The second argument enter a regular expression. \n";
}

bool Text_for_regexp_app::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 3) {
    help(argv[0], "ERROR: Should be 2 arguments.\n\n");
    return false;
  }
  return true;
}

std::string Text_for_regexp_app::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  std::vector <std::string> values;
  for (int i = 1; i < argc; i++)
    values.push_back(argv[i]);
  Text_for_regexp text(values[0]);
  std::string res = text.Search_for_regexp(values[1]);
  return res;
}
