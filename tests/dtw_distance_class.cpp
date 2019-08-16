//
// dtw_distance_class.cpp
//
// Copyright (c) 2019 Charles Jekel
// MIT licensed
//


#include <cmath>
#include <vector>
#include "../include/DTW.hpp"
#include "assertion-macros.h"



template<typename T>
std::vector<double> linspace(T start_in, T end_in, int num_in)
{
  // source for this template from user Akavall
  // https://stackoverflow.com/questions/27028226/python-linspace-in-c
  std::vector<double> linspaced;

  double start = static_cast<double>(start_in);
  double end = static_cast<double>(end_in);
  double num = static_cast<double>(num_in);

  if (num == 0) { return linspaced; }
  if (num == 1) 
    {
      linspaced.push_back(start);
      return linspaced;
    }

  double delta = (end - start) / (num - 1);

  for(int i=0; i < num-1; ++i)
    {
      linspaced.push_back(start + delta * i);
    }
  linspaced.push_back(end); // I want to ensure that start and end
                            // are exactly the same as the input
  return linspaced;
}


int main () {
  int success = 0;

  // ========= Test case 1 ========= 
  std::vector<std::vector<double> > a = { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2} };
  std::vector<std::vector<double> > b = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0} };

  double ans = 10.0;
  DTW::DTW MyDtw (a, b, 2.0);
  if (MyDtw.distance != ans)
  {
    assert_equal(MyDtw.distance, ans);
    success = 1;
  }

  // ========= Test case 2 ========= 
  std::vector<std::vector<double> > p = { {0, 0}, {1, 1}, {2, 2} };
  std::vector<std::vector<double> > q = { {0, 1}, {1, 2}, {2, 3} };
  ans = 3.0;
  DTW::DTW MyDtw1 (p, q, 2.0);
  if (MyDtw1.distance != ans)
  {
    assert_equal(MyDtw1.distance, ans);
    success = 1;
  }

  // ========= Test case 3 ========= 
  double r1 = 10.0;
  double r2 = 100.0;
  double twopi = 2*M_PI;
  std::vector<double> theta = linspace(0.0, twopi, 100);
  std::vector<std::vector<double> > curve1 (100, std::vector<double> (2, 0.0));
  std::vector<std::vector<double> > curve2 (100, std::vector<double> (2, 0.0));
  for (int i = 0; i < 100; i++)
  {
    curve1[i] = { r1*std::cos(theta[i]), r1*std::sin(theta[i]) };
    curve2[i] = { r2*std::cos(theta[i]), r2*std::sin(theta[i]) };
  }
  
  double theta_array[100];
  ans = 9000.0;
  DTW::DTW MyDtw2 (curve1, curve2, 2.0);
  if (MyDtw2.distance != ans)
  {
    assert_equal(MyDtw2.distance, ans);
    success = 1;
  }
  return success;
}