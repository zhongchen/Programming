#include "knapsack.h"
#include <bitset>
#include <vector>
#include <iterator>
#include <iostream>
#include <memory>

using namespace std;

constexpr unsigned int MAX_BITS = 100000;

//The code is not beautiful...
//
struct bag
{
  //Constructor
  bag(int w, int v)
    :weight(w), 
     value(v)
  {
  }
  int weight;
  int value;
};

void knapsack_test()
{
  const int max_weight = 22;
  vector<unique_ptr<bag>> bags;

  bags.push_back(unique_ptr<bag>(new bag{4,6}));
  bags.push_back(unique_ptr<bag>(new bag{5,8}));
  bags.push_back(unique_ptr<bag>(new bag{8,12}));
  bags.push_back(unique_ptr<bag>(new bag{9,13}));

//  knapsack(max_weight, bags);
  knapsack_unique_bag(max_weight, bags);

}

void print_result(
    const int& weight,
    const vector<int>& values,
    const vector<int>& back_pointers)
{
  cout<<"The max value is "<<values[weight]<<endl;
  std::copy(back_pointers.begin(), back_pointers.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;
  std::copy(values.begin(), values.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;

  cout<<"Print result"<<endl;
  int temp = weight;

  while (back_pointers[temp]!=0)
  {
    cout<<back_pointers[temp]<<endl;
    temp = back_pointers[temp];
  }
}

void calculate_value(
    const int& weight, 
    const vector<unique_ptr<bag>>& bags,
    vector<int>& values,
    vector<int>& back_pointers)
{

  int max_value = 0;
  int index = 0;

  for(auto itr=bags.begin(); itr!=bags.end(); ++itr)
  {
    //weight exactly equals to one bag
    if (weight==(*itr)->weight)
    {
      if ((*itr)->value>max_value)
      {
	values[weight] = (*itr)->value;
	back_pointers[weight] = 0;
      }
      else
      {
	values[weight] = max_value;
	back_pointers[weight] = index;
      }
      return;
    }
    else if (weight > (*itr)->weight)
    {
      if (values[weight-(*itr)->weight]+(*itr)->value > max_value)
      {
	max_value = values[weight-(*itr)->weight]+(*itr)->value;
	index = weight - (*itr)->weight;
      }
    }
    else
    {
	values[weight] = max_value;
	back_pointers[weight] = index;
	return;
    }
  }
  values[weight] = max_value;
  back_pointers[weight] = index;
}

//assume the bags are in increaing weight order
void knapsack(const int& weight, const vector<unique_ptr<bag>>& bags)
{
  if (bags.empty())
  {
    cerr<<"bags are empty"<<endl;
  }

  //Let's weight be the index!!!
  //Simply the indexing problem!!!
  vector<int> values(weight+1);
  //back_pointers keep track of the previous index
  vector<int> back_pointers(weight+1);

  for (int i=1; i<=weight; ++i)
  {
    calculate_value(i, bags, values, back_pointers);
  }
  print_result(weight, values, back_pointers);
}

void copy_flag(
    std::bitset<MAX_BITS>& flags, 
    const int source, 
    const int destination, 
    const int colNum)
{
  for (int j=0; j<colNum; ++j)
  {
    if(flags[(source-1)*colNum+j])
    {
      flags.set((destination-1)*colNum+j);
    }
  }
}
void calculate_value_unique(
    const int& weight, 
    const vector<unique_ptr<bag>>& bags,
    vector<int>& values,
    vector<int>& back_pointers,
    std::bitset<MAX_BITS>& flags)
{

  int max_value = 0;
  int index = 0;
  //signal which bag is used in every iteration
  int bag_index = -1;

  //Each row stores the flags to indicate
  //which bags are used
  int colNum = bags.size();

  for (int i=0; i<bags.size(); ++i)
  {
    //weight exactly equals to one bag
    if (weight==bags[i]->weight)
    {
      if (bags[i]->value>max_value)
      {
	values[weight] = bags[i]->value;
	back_pointers[weight] = 0;
	flags.set((weight-1)*colNum+i);
      }
      else
      {
	values[weight] = max_value;
	back_pointers[weight] = index;
	//bag_index must not be -1
	copy_flag(flags, index, weight, colNum);
	flags.set((weight-1)*colNum+bag_index);
      }
      return;
    }
    else if (weight > bags[i]->weight)
    {
      if ((values[weight-bags[i]->weight]+bags[i]->value > max_value)
	 &&!flags[(weight-bags[i]->weight-1)*colNum+i])
      {
	max_value = values[weight-bags[i]->weight]+bags[i]->value;
	index = weight - bags[i]->weight;
	bag_index = i;
      }
    }
    else
    {
      //Current bag weight is larger than the targeted weight
      values[weight] = max_value;
      back_pointers[weight] = index;
      if (bag_index!=-1)
      {
	copy_flag(flags, index, weight, colNum);
	flags.set((weight-1)*colNum+bag_index);
      }
      return;
    }
  }
  values[weight] = max_value;
  back_pointers[weight] = index;
  if (bag_index !=-1)
  {
    copy_flag(flags, index, weight, colNum);
    flags.set((weight-1)*colNum+bag_index);
  }
}
void knapsack_unique_bag(const int& weight, const vector<unique_ptr<bag>>& bags)
{
  auto max_possible_weight = 0;
  auto max_possible_value = 0;

  for (auto itr = bags.begin(); itr != bags.end(); ++itr)
  {
    max_possible_weight += (*itr)->weight;
    max_possible_value += (*itr)->value;
  }

  if (weight > max_possible_weight)
  {
    cout<<"Weight is larger than the total bags weight"<<endl;
    cout<<"Value is "<<max_possible_value<<endl;
    return;
  }

  std::bitset<MAX_BITS> flag_table;

  vector<int> values(weight+1);

  //back_pointers keep track of the previous index
  vector<int> back_pointers(weight+1);

  for (int i=1; i<=weight; ++i)
  {
    calculate_value_unique(i, bags, values, back_pointers,flag_table);
  }
  print_result(weight, values, back_pointers);
}

