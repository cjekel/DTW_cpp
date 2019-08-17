# Compute the Dynamic Time Warping distance between two 2D vectors
```c++
double p = 2;  // the p-norm to use; 2.0 = euclidean, 1.0 = manhattan
std::vector<std::vector<double> > a = { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2} };
std::vector<std::vector<double> > b = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0} };
// Compute the DTW distance between a an b
// a[number_of_data_points][number_of_dimensions]
// b[number_of_data_points][number_of_dimensions]

// The number of dimensions between a and b must agree!
// if not std::invalid_argument is raised.

// a and b do not need the same number of data points
```

# examples

- [quick_distance.cpp](https://github.com/cjekel/DTW_cpp/blob/master/examples/quick_distance.cpp) compute only the DTW distance between 2D vectors a and b
- [dtw_class.cpp](https://github.com/cjekel/DTW_cpp/blob/master/examples/dtw_class.cpp) DTW class has access to the pairwise distance vector, DTW distance vector, and can calculate the DTW path

# linux instructions

```bash
g++ -I ../include quick_distance.cpp
./a.out
```

```bash
g++ -I ../include dtw_class.cpp
./a.out
```

# windows instructions

```bat
cl -I ..\include quick_distance.cpp
.\quick_distance.exe
```

```bat
cl -I ..\include dtw_class.cpp
.\dtw_class.exe
```