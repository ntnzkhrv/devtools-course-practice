// Copyright 2022 Frolov Gleb

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/application.h"

using ::testing::internal::RE;

class BilInerpolAppTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("calculate-price");
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
  BilInerpolApp app_;
  std::string output_;
};

TEST_F(BilInerpolAppTest, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is an application to bilinear interpolation.");
}

TEST_F(BilInerpolAppTest, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "1", "2", "3" };

  Act(args);

  Assert("ERROR: Should be 4 arguments.");
}

TEST_F(BilInerpolAppTest, Test_With_Integer) {
  std::vector<std::string> args = { "55", "9", "11", "23" };

  Act(args);

  Assert("Result: 24.5");
}

TEST_F(BilInerpolAppTest, Test_With_Double) {
  std::vector<std::string> args = { "5.5", "1.9", "10.1", "7.4" };

  Act(args);

  Assert("Result: 6.225");
}

TEST_F(BilInerpolAppTest, Test_With_Negative_Value) {
  std::vector<std::string> args = { "-50", "10.3", "10.1", "22.6" };

  Act(args);

  Assert("Result: -1.75");
}
