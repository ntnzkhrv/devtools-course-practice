// Copyright 2022 Brazhnik Dmitry

#ifndef MODULES_BRAZHNIK_DMITRY_CONVERTER_ARAB_ROM_INCLUDE_CONVERTER_APPLICATION_H_
#define MODULES_BRAZHNIK_DMITRY_CONVERTER_ARAB_ROM_INCLUDE_CONVERTER_APPLICATION_H_

#include <string>
#include "include/converter.h"

class ConverterApplication {
 private:
     std::string getHelp(const std::string& appname);
     bool checkArgument(const std::string& str);
     int parseArgument(const char* arg);
 public:
     std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_BRAZHNIK_DMITRY_CONVERTER_ARAB_ROM_INCLUDE_CONVERTER_APPLICATION_H_
