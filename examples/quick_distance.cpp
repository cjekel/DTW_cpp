//
// quick_distance.cpp
//
// Copyright (c) 2019 Charles Jekel
// MIT licensed
//


#include <iostream>
#include <vector>
#include <DTW.hpp>

int main ()
{
  double p = 2;  // the p-norm to use; 2.0 = euclidean, 1.0 = manhattan
  std::vector<std::vector<double> > a = { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2} };
  std::vector<std::vector<double> > b = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0} };
  // Compute the DTW distance between a an b
  // a[number_of_data_points][number_of_dimensions]
  // b[number_of_data_points][number_of_dimensions]
  // The number of dimensions between a and b must agree
  std::cout << "DTW distance: " << DTW::dtw_distance_only(a, b, p) << std::endl;
  return 0;
}
