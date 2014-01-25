#include "SearchTest.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
using namespace std;


void SearchTest()
{
  binary_search_test();
  equal_range_test();
}

void binary_search_test()
{
  vector<int> vec = {3,4,1,6,2,5}; 

  std::sort(vec.begin(), vec.end(), std::greater<int>());
  
  //Remeber to give the correct comparator for the function!!!!
  //The return value is a boolean
  cout<<std::binary_search(vec.begin(), vec.end(), 4, std::greater<int>())<<endl; //Found 
  cout<<std::binary_search(vec.begin(), vec.end(), 4)<<endl;  //Not Found
}

void lower_bound_test()
{
}

void upper_bound_test()
{

}

void equal_range_test()
{
  vector<int> vec = {3,4,1,6,2,3,5};
  std::sort(vec.begin(), vec.end());

  //using the same comparator as the sorting does
  auto result = equal_range(vec.begin(), vec.end(), 3);
  cout<<std::distance(vec.begin(), result.first)<<endl;
  cout<<std::distance(vec.begin(), result.second)<<endl;
}
