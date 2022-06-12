// Copyright 2022 Brazhnik Dmitry

#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "include/converter_application.h"

std::string ConverterApplication::getHelp(const std::string& appname) {
    return  "This is an application for converting arabic numbers to roman\n" \
        "Format for arguments:\n" +
        appname + " <arabic number> "
        "Argument must be positive integer more than 1.";
}

std::string ConverterApplication::operator()(int argc, const char** argv) {
    int arab;
    if (argc == 1) {
        return getHelp(argv[0]);
    }
    try {
        if (argc > 2) {
            std::string error_msg = "Error occured: ";
            error_msg += "Should be 1 arguments.";
            throw std::runtime_error(error_msg);
        }
        arab = parseArgument(argv[1]);
    }
    catch (std::exception& exp) {
        return exp.what();
    }
    Converter c;
    arabien ar;
    ar.val = arab;
    std::ostringstream oss;
    std::string roman = c.ConvertArabToRom(ar).val;
    oss << roman;
    return oss.str();
}

bool ConverterApplication::checkArgument(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int ConverterApplication::parseArgument(const char* arg) {
    if (!checkArgument(arg))
        throw std::runtime_error("Error occured: Wrong argument type.\n");
    return std::stoi(arg);
}
