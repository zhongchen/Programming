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
	vector<int> vec; 
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(5);

	std::sort(vec.begin(), vec.end(), std::greater<int>());
	
	//Remeber to give the correct comparator for the function!!!!
	std::binary_search(vec.begin(), vec.end(), 4, std::greater<int>()); 
}

void lower_bound_test()
{
}

void upper_bound_test()
{

}

void equal_range_test()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);

	auto result = equal_range(vec.begin(), vec.end(), 3);
	cout<<std::distance(vec.begin(), result.first)<<endl;
	cout<<std::distance(vec.begin(), result.second)<<endl;
}