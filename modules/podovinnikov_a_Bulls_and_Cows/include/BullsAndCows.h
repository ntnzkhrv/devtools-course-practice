// Copyright 2022 Podovinnikov Artyom

#ifndef MODULES_PODOVINNIKOV_A_BULLS_AND_COWS_INCLUDE_BULLSANDCOWS_H_
#define MODULES_PODOVINNIKOV_A_BULLS_AND_COWS_INCLUDE_BULLSANDCOWS_H_

#include <ctime>
#include <iostream>
#include <string>
class BullsCows {
 private:
  std::string RiddleNum;
  std::string PlayerNum;
  int CountofNums = 0;
  int Bulls = 0;
  int Cows = 0;
  int Times = 0;

 public:
  BullsCows();
  explicit BullsCows(std::string str);
  void SetPlayerNum(std::string str1);
  void SetRiddleNum(std::string str1);
  int GetBulls();
  int GetCows();
  std::string GetPlayerNum();
  std::string GetRiddleNum();
  void CompareStrings(std::string str1, std::string str2);
  bool SimillarNums(std::string str1);
};

#endif  // MODULES_PODOVINNIKOV_A_BULLS_AND_COWS_INCLUDE_BULLSANDCOWS_H_
