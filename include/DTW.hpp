//
// DTW.hpp
//
// Copyright (c) 2019 Charles Jekel
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//


#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
const std::string DTW_VERSION = "0.0.1";


namespace DTW
{
  double p_norm (std::vector<double> a, std::vector<double> b, double p) {
      double d = 0;
      for (int i = 0; i < a.size() ; i++) {
        d += std::pow(std::abs(a[i] - b[i]), p);
      }
      return std::pow(d, 1.0/p);
  };

  double dtw_distance_only(std::vector<std::vector<double>> a,
                          std::vector<std::vector<double>> b,
                          double p)
  {
    int n = a.size();
    int o = b.size();
    int a_m = a[0].size();
    int b_m = b[0].size();
    if (a_m != b_m)
      {
        throw std::invalid_argument( "a and b must have the same number of dimensions!" );
      }
    std::vector<std::vector<double> > d(n, std::vector<double> (o, 0.0));
    d[0][0] = p_norm(a[0], b[0], p);
    for (int i=1; i < n; i++)
      {
        d[i][0] = d[i-1][0] + p_norm(a[i], b[0], p);
      }
    for (int i=1; i < o ; i++)
      {
        d[0][i] = d[0][i-1] + p_norm(a[i], b[0], p);
      }
    for (int i=1; i < n ; i++)
      {
        for (int j=1; j < o; j++){
          d[i][j] = p_norm(a[i], b[j], p) + std::fmin(std::fmin(d[i-1][j], d[i][j-1]), d[i-1][j-1]);
        }  
      }
    return d[n-1][o-1];
  };


  std::vector<std::vector<double> > dtw_vector_assemble(std::vector<std::vector<double>> d,
                                                        std::vector<std::vector<double>> c,
                                                        int n, int o) {
    for (int i=1; i < n; i++)
      {
        d[i][0] = d[i-1][0] + c[i][0];
      }
    for (int i=1; i < o ; i++)
      {
        d[0][i] = d[0][i-1] + c[0][i];
      }
    for (int i=1; i < n ; i++)
      {
        for (int j=1; j < o; j++){
          d[i][j] = c[i][j] + std::fmin(std::fmin(d[i-1][j], d[i][j-1]), d[i-1][j-1]);
        }  
      }
    return d;
  };


  class DTW {

  public:
    /* Compute the Dynamic Time Warping distance between two curves in space

    */

    std::vector<std::vector<double> > a_vector, b_vector;
    int a_data, n_dim, b_data;
    double p, distance;
    std::vector<std::vector<double> > dtw_vector, pairwise_vector;
    DTW (std::vector<std::vector<double> > a, std::vector<std::vector<double> > b, double p) : 
      a_vector(a), b_vector(b), p(p) {
        a_data = a.size();
        b_data = b.size();
        int a_m = a_vector[0].size();
        int b_m = b_vector[0].size();
        
        if (a_m != b_m)
        {
          throw std::invalid_argument( "a and b must have the same number of dimensions!" );
        }
        else
        {
          n_dim = a_m;
        }    

        std::vector<std::vector<double> > c(a_data, std::vector<double> (b_data, 0.0));

        for (int i=0; i < a_data; i++){
          for (int j=0; j < b_data; j++) {
            c[i][j] = p_norm(a_vector[i], b_vector[j], p);
          }
        }
        pairwise_vector = c;
        std::vector<std::vector<double> > d(a_data, std::vector<double> (b_data, 0.0));
        d[0][0] = pairwise_vector[0][0];
        dtw_vector = dtw_vector_assemble(d, pairwise_vector, a_data, b_data);
        distance = dtw_vector[a_data-1][b_data-1];
      };
    std::vector<std::vector<int> > path () {
      int i = a_data - 1;
      int j = b_data - 1;
      std::vector<std::vector<int> > my_path = { {i, j} };
      while (i > 0 || j > 0) {
        if (i == 0)
        {
          j -= 1;
        }
        else if (j == 0)
        {
          i -= 1;
        }
        else
        {
          double temp_step = std::fmin(std::fmin(dtw_vector[i-1][j], dtw_vector[i][j-1]),
                                      dtw_vector[i-1][j-1]);
          if (temp_step == dtw_vector[i-1][j])
          {
            i -= 1;
          }
          else if (temp_step == dtw_vector[i][j-1])
          {
            j -= 1;
          }
          else
          {
            i -= 1;
            j -= 1;
          }
        }
        my_path.push_back ({i, j});
      }
      std::reverse(my_path.begin(), my_path.end());
      return my_path;
    }
  };

}

