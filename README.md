# DTW_cpp
A small Dynamic Time Warping (DTW) single header library for C++


[DTW.hpp](https://github.com/cjekel/DTW_cpp/blob/master/include/DTW.hpp) computes the DTW distance between two 2D c++ vectors ```a``` and ```b```!

# Features

- Supports N-Dimensional data
- ```a``` and ```b```can have different number of data points
- Compute the distance using any ```p```-norm
- ```DTW::dtw_distance_only(a, b, p);``` function which returns only the DTW distance
- ```DTW::DTW MyDtw (a, b, p);``` class contains the pairwise distance vector, DTW distance vector, DTW distance, and a function to calculate the DTW alignment path

# Examples

Check out the two [examples](https://github.com/cjekel/DTW_cpp/tree/master/examples).

# Tests

Run [run_tests.sh](https://github.com/cjekel/DTW_cpp/blob/master/tests/run_tests.sh) in a linux environment. 
- travisci tests using Ubuntu Xenial and g++ version 5.4.0
- also tested on openSUSE Leap 15.1 and g++ version 7.4.0

# Requirements

- C++11 standard or later