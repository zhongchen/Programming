#include "SortTest.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>
using namespace std;


//There four kinds of sorts available at my disposal.
//partial_sort, nth_element, sort, stable_store
//needs random access iterator, not applicable for list
//only for vectors, deques, strings, arrays

void SortTest()
{
	cout<<"Different Sorting Test"<<endl;
	nth_element_test();
	partial_sort_test();
}

void nth_element_test()
{
	vector<int> vec; 
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(5);
	vector<int>::iterator goalitr = vec.begin() + 3;
	std::nth_element(vec.begin(), goalitr, vec.end()); 
	cout<<*goalitr<<endl;

	for (auto i : vec)
	{
		cout<<i<<'\t';
	}

	cout<<endl;

	goalitr = vec.begin() + 1;
	std::nth_element(vec.begin(), goalitr, vec.end(), std::greater<int>()); 
	cout<<*goalitr<<endl;

	for (auto i : vec)
	{
		cout<<i<<'\t';
	}

	cout<<endl;

	std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, " "));

	cout<<endl;
}

void partial_sort_test()
{
	vector<int> vec; 
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(5);
	
	vector<int>::iterator goalitr = vec.begin() + 3;
	std::nth_element(vec.begin(), goalitr, vec.end()); 
	cout<<*goalitr<<endl;

	for (auto i : vec)
	{
		cout<<i<<'\t';
	}
}

