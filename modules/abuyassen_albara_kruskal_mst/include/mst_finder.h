// Copyright 2022 Narlyeev Parahat

#ifndef MODULES_ABUYASSEN_ALBARA_KRUSKAL_MST_INCLUDE_MST_FINDER_H_
#define MODULES_ABUYASSEN_ALBARA_KRUSKAL_MST_INCLUDE_MST_FINDER_H_

#include <string>

class MSTFinder {
 public:
    MSTFinder();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

//! @}

#endif  // MODULES_ABUYASSEN_ALBARA_KRUSKAL_MST_INCLUDE_MST_FINDER_H_
