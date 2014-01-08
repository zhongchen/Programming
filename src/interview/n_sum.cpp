#include "n_sum.h"
#include <iostream>
#include <vector>
using namespace std;

void n_sum(int i);

void n_sum_helper(vector<int> vec, int upper_bound, int remaining);

void n_sum_test()
{
  for (int i=1; i<6; ++i)
  {
    n_sum(i);
    cout<<endl;
  }
}

void print_result(vector<int> vec)
{
  for (auto v: vec)
  {
    cout<<v<<" ";
  }
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

