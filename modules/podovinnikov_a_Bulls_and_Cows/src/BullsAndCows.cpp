// Copyright 2022 Podovinnikov Artyom
#include "include/BullsAndCows.h"

#include <sstream>
#include <string>

void BullsCows::CompareStrings(std::string str1, std::string str2) {
  for (unsigned int i = 0; i < str1.size(); i++) {
    if (str1[i] == str2[i]) Bulls++;
    for (unsigned int j = 0; j < str1.size(); j++)
      if (str1[i] == str2[j]) Cows++;
  }
  Cows -= Bulls;
}
void BullsCows::SetPlayerNum(std::string str1) {
  if (!SimillarNums(str1)) {
    if (str1.size() == RiddleNum.size()) {
      PlayerNum = str1;
    } else {
      throw "Wrong amount of digits in the riddle number";
    }

  } else {
    throw "there are duplicate digits in the number";
  }
}
void BullsCows::SetRiddleNum(std::string str1) {
  if (!SimillarNums(str1)) {
    RiddleNum = str1;
  } else {
    throw "there are duplicate digits in the number";
  }
}
int BullsCows::GetBulls() { return Bulls; }

int BullsCows::GetCows() { return Cows; }

std::string BullsCows::GetPlayerNum() { return PlayerNum; }

std::string BullsCows::GetRiddleNum() { return RiddleNum; }

BullsCows::BullsCows(std::string str) { RiddleNum = str; }
BullsCows::BullsCows() {}

bool BullsCows::SimillarNums(std::string str1) {
  for (unsigned int i = 0; i < str1.size(); i++)
    for (unsigned int j = i + 1; j < str1.size(); j++) {
      if (str1[i] == str1[j]) {
        return true;
      }
    }
  return false;
}
