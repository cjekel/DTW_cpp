//
// p_norm.cpp
//
// Copyright (c) 2019 Charles Jekel
// MIT licensed
//


#include <vector>
#include <stdexcept>
#include <DTW.hpp>
#include "assertion-macros.h"


int main () {
  int success = 0;

  std::vector<double> a = {0, 0, 0, 2};
  std::vector<double> b = {0, 0, 0, 0};

  double ans = 2.0;
  double euc = DTW::p_norm(a, b, 2);
  if (euc != ans)
  {
    assert_equal(euc, ans);
    success = 1;
  }
  double man = DTW::p_norm(a, b, 1);
  if (man != ans)
  {
    assert_equal(man, ans);
    success = 1;
  }
  double p_100 = DTW::p_norm(a, b, 100);
  if (p_100 != ans)
  {
    assert_equal(p_100, ans);
    success = 1;
  }

  std::vector<double> c = {2, 2, 2, 2};
  std::vector<double> d = {0, 0, 0, 0};
  ans = 4.0;
  euc = DTW::p_norm(c, d, 2);
  if (euc != ans)
  {
    assert_equal(euc, ans);
    success = 1;
  }
  ans = 8.0;
  man = DTW::p_norm(c, d, 1);
  if (man != ans)
  {
    assert_equal(man, ans);
    success = 1;
  }

  std::vector<double> e = {1};
  std::vector<double> f = {0};
  ans = 1;
  euc = DTW::p_norm(e, f, 2);
  if (euc != ans)
  {
    assert_equal(euc, ans);
    success = 1;
  }
  man = DTW::p_norm(e, f, 1);
  if (man != ans)
  {
    assert_equal(man, ans);
    success = 1;
  }
  p_100 = DTW::p_norm(e, f, 100);
  if (p_100 != ans)
  {
    assert_equal(p_100, ans);
    success = 1;
  }

  return success;
}
