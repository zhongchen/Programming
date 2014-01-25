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
    vector<int> vec={3,4,1,6,2,5}; 
    auto itr = vec.begin() + 3;
    std::nth_element(vec.begin(), itr, vec.end()); 
    cout<<*itr<<endl;

    std::copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, " "));

    cout<<endl;

    itr = vec.begin() + 1;
    std::nth_element(vec.begin(), itr, vec.end(), std::greater<int>()); 
    cout<<*itr<<endl;

    std::copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, " "));
    cout<<endl;
}

void partial_sort_test()
{
    vector<int> vec = {3,4,1,6,2,5};
    int n = 3;

    cout<<"The original vector is"<<endl;
    std::copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, " "));
    cout<<endl;
    //sort the first n element
    auto itr = vec.begin() + n;
    cout<<"First "<<n<<" are sorted in ascending order"<<endl;

    std::partial_sort(vec.begin(), itr, vec.end()); 
    std::copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, " "));
    std::cout<<endl;

    n = 2;
    cout<<"First "<<n<<" are sorted in descending order"<<endl;
    itr = vec.begin() + n;
    std::partial_sort(vec.begin(), itr, vec.end(), std::greater<int>());
    std::copy(vec.begin(), vec.end(), ostream_iterator<int>(std::cout, " "));
    std::cout<<endl;
}

