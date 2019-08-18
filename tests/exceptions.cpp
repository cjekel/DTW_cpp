//
// exceptions.cpp
//
// Copyright (c) 2019 Charles Jekel
// MIT licensed
//

#include <vector>
#include <stdexcept>
#include "include/DTW.hpp"

int main () {
  int success_one = 1;
  int success_two = 1;
  int success = 1;

  // ========= Test case 1 ========= 
  double p = 2;
  std::vector<std::vector<double> > a = { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2} };
  std::vector<std::vector<double> > c = { {0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0} };
  try
  {
    double r = DTW::dtw_distance_only(a, c, p);
  }
  catch (std::invalid_argument)
  {
    success_one = 0;
  }

  // ========= Test case 2 ========= 
  try
  {
    DTW::DTW MyDtw(a, c, p);
  }
  catch (std::invalid_argument)
  {
    success_two = 0;
  }
  if (success_one == 0 && success_two == 0)
  {
    success = 0;
  }
  return success;
};
