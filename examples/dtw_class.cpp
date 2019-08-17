//
// dtw_class.cpp
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

  // initialize the DTW object
  DTW::DTW MyDtw (a, b, p);
  // The distance is calculated and stored in MyDtw.distance
  std::cout << "DTW distance: " << MyDtw.distance << std::endl;

  // The pairwise distance between each point is stored in
  // MyDtw.pairwise_vector
  // The shape is MyDtw.pairwise_vector[a.size()][b.size()]
  std::cout << "First pairwise distance: " << MyDtw.pairwise_vector[0][0] << std::endl;

  // The DTW distance matrix is stored in MyDtw.dtw_vector
  // The shape is MyDtw.dtw_vector[a.size()][b.size()]
  std::cout << "The 1,1 value of the DTW distance matrix: ";
  std::cout << MyDtw.dtw_vector[1][1] << std::endl;

  // You can calculate the DTW alignment path with MyDtw.path()
  // This retruns a 2D vector of the indexies through MyDtw.dtw_vector
  // for alignment. This path goes from MyDtw.dtw_vector[0][0], to 
  // MyDtw.dtw_vector[i][j], up until MyDtw.dtw_vector[a.size()-1][b.size()-1]
  std::vector<std::vector<int> > path;
  path = MyDtw.path();
  std::cout << "DTW Path: " << std::endl;
  for (int i = 0; i < path.size(); ++i)
    std::cout << "i=" << path[i][0] << " j=" << path[i][1] << std::endl;
  return 0;
}