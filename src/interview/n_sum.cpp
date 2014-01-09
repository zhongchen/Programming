#include "n_sum.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//Problem desciption
//Find all the possible ways to
//add up a number of positive integers
//so that their sum is n
//Example n=4
//1 1 1 1
//2 1 1
//2 2
//3 1
//3 1 
void n_sum(int i);

void n_sum_helper(vector<int> vec, const int upper_bound, const int remaining);

void n_sum_test()
{
  for (int i=1; i<6; ++i)
  {
    n_sum(i);
    cout<<endl;
  }
}

template <typename T>
void print_result(vector<T> vec)
{
  for_each(vec.begin(), vec.end(), 
           [](const T& t){cout<<t<<" ";});
  cout<<endl;
}

void n_sum(int i)
{
  vector<int> vec;
  n_sum_helper(vec, i, i);
}

void n_sum_helper(vector<int> vec, int upper_bound, int remaining)
{
  if (remaining<0)
  { 
    cerr<<"error"<<endl;
    return;
  }
  else if (remaining==0)
  {
    print_result(vec);
    return;
  }
  else if (remaining==1)
  {
    vec.push_back(remaining);
    print_result(vec);
  }
  else
  {
    for (int i=1; i<upper_bound; ++i)
    {
      if (i<=remaining)
      {
	vec.push_back(i);
	n_sum_helper(vec, i+1, remaining-i);
	vec.pop_back();
      }
    }
  }
}

