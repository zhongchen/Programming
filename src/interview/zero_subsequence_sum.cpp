#include "zero_subsequence_sum.h"
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <string>

using namespace std;

/*
 *
 * The algorithm is used to find all the subsequence that 
 * sums up to zero
 *
 *
 * It first calculates the partial sum
 * Then it finds all positions that have value zero
 * and all the pairs that have the same value;
 * 
*/

void zero_subsequence_sum(vector<int> vec)
{
  vector<int> partial_sum_result;
  std::partial_sum(vec.begin(), vec.end(),
      partial_sum_result.begin());

  mymap index_count;

  for (int i=0; i<vec.size(); ++i)
  {
    auto tmp = partial_sum_result[i];
//    index_count[tmp].push_back(i);
  }
/*
  for (auto v:index_count)
  {
    if (v.first==0)
    {
      cout<<v.second<<endl;
    }
  }*/
}

void zero_subsequence_sum_test()
{
  vector<int> vec = {-1, -3, 4, 5, 4};

  std::partial_sum(vec.begin(), vec.end(),
      std::ostream_iterator<int>(std::cout, " "));

  cout<<endl;
  zero_subsequence_sum(vec);
}
