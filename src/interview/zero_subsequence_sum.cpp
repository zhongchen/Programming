#include "zero_subsequence_sum.h"
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>
#include <string>
#include <unordered_map>
#include <numeric> //contains partial_sum

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

template <typename T>
void printVector(const vector<T>& vec)
{
  for (auto v : vec)
  {
    cout<<v<<" ";
  }
  cout<<endl;

}

void printResultOne(const vector<int>& vec)
{
  for (auto v : vec)
  {
    cout<<"0 "<<v<<endl;
  }
}

void printResultTwo(const vector<int>& vec)
{
  for(int i=0; i<vec.size()-1; ++i)
  {
    for (int j=i+1; j<vec.size(); j++)
    {
      cout<<vec[i]+1<<" "<<vec[j]<<endl;
    }
  }
}

void zero_subsequence_sum(vector<int> vec)
{
  cout<<"start processing zero subsequence problem"<<endl;

  vector<int> partial_sum_result(vec.size());
  std::partial_sum(vec.begin(), vec.end(),
      partial_sum_result.begin());

  printVector(partial_sum_result);
  std::unordered_map<int, vector<int>> index_count;

  for (int i=0; i<vec.size(); ++i)
  {
    const auto tmp = partial_sum_result[i];
    auto itr = index_count.find(tmp);

    if (itr != index_count.end())
    {
      index_count[tmp].push_back(i);
    }
    else
    {
      index_count.emplace(std::make_pair(tmp, vector<int>()));
      index_count[tmp].push_back(i);
    }
  }

  //Two possible zero sum subsequence
  //Scenairo One
  //array[0:i]
  for (auto v:index_count)
  {
    if (v.first==0)
    {
      printVector(v.second);
      printResultOne(v.second);
    }
  }

  //Scenario Two
  //array[i:j]
  for (auto v:index_count)
  {
    if (v.second.size() > 1)
    {
      printVector(v.second);
      printResultTwo(v.second);
    }
  }
}

void zero_subsequence_sum_test()
{
  vector<int> vec = {-1, -3, 4,0, -1, 1, 4};

  std::partial_sum(vec.begin(), vec.end(),
      std::ostream_iterator<int>(std::cout, " "));

  cout<<endl;
  zero_subsequence_sum(vec);
}
