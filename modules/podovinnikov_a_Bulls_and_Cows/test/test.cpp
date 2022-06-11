// Copyright 2022 Podovinnikov Artyom
#include <gtest/gtest.h>

#include "include/BullsAndCows.h"
TEST(BullsCows, Construct) {
  BullsCows a("3465");
  ASSERT_NO_THROW();
}
TEST(BullsCows, CompareIdenticalStr) {
  BullsCows a("3465");
  a.SetPlayerNum("3465");
  a.CompareStrings(a.GetRiddleNum(), a.GetPlayerNum());
  ASSERT_EQ(a.GetBulls(), 4);
  ASSERT_EQ(a.GetCows(), 0);
}
TEST(BullsCows, CompareDifferentStrTest1) {
  BullsCows a("3465");
  a.SetPlayerNum("4593");
  a.CompareStrings(a.GetRiddleNum(), a.GetPlayerNum());
  ASSERT_EQ(a.GetBulls(), 0);
  ASSERT_EQ(a.GetCows(), 3);
}
TEST(BullsCows, CompareDifferentStrTest2) {
  BullsCows a("3465");
  a.SetPlayerNum("4563");
  a.CompareStrings(a.GetRiddleNum(), a.GetPlayerNum());
  ASSERT_EQ(a.GetBulls(), 1);
  ASSERT_EQ(a.GetCows(), 3);
}
TEST(BullsCows, SimillarNumsInRiddleNum) {
  BullsCows a;
  ASSERT_ANY_THROW(a.SetRiddleNum("33542"));
}
TEST(BullsCows, SimillarNumsInPlayerNum) {
  BullsCows a;
  ASSERT_ANY_THROW(a.SetPlayerNum("33542"));
}
TEST(BullsCows, NumbersOfDifferentLengths) {
  BullsCows a;
  a.SetRiddleNum("38542");
  ASSERT_ANY_THROW(a.SetPlayerNum("3654"));
}
