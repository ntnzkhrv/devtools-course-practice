// Copyright 2022 Shilov Roman

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/application.h"

using ::testing::internal::RE;

class Text_for_regexp_test : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("regular-search");
    for (std::size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  Text_for_regexp_app app_;
  std::string output_;
};

TEST_F(Text_for_regexp_test, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application to looking for a regular expression.");
}

TEST_F(Text_for_regexp_test, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "1", "2", "3" };

  Act(args);

  Assert("ERROR: Should be 2 arguments.");
}

TEST_F(Text_for_regexp_test, Can_create_object_with_parameter) {
  std::vector<std::string> args = {"qwer", "qwer"};

  Act(args);

  Assert("qwer");
}

TEST_F(Text_for_regexp_test, Can_search_regexp_1) {
  std::vector<std::string> args = {"qwer tyui asdf ghjk", "q"};

  Act(args);

  Assert("qwer");
}

TEST_F(Text_for_regexp_test, Can_search_regexp_2) {
  std::vector<std::string> args = {"qwer tyui asdf ghjk", "qw"};

  Act(args);

  Assert("qwer");
}

TEST_F(Text_for_regexp_test, Can_search_regexp_3) {
  std::vector<std::string> args = {"qwer tyui asdf ghjk", "ui"};

  Act(args);

  Assert("tyui");
}

TEST_F(Text_for_regexp_test, Can_search_regexp_4) {
  std::vector<std::string> args = {"qwer tyui qw00 ghjk", "wr"};

  Act(args);

  Assert("Not found");
}
