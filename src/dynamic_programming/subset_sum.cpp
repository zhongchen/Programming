#include "subset_sum.h"
#include <memory>
#include <bitset>
#include <iostream>
using namespace std;

//The more proper name may be 
//subpart sum
//Basically it tries to verify 
//whether we can find a sub part of a group of numbers 
//which sums up to a targeted number

//assumption
//the group consists of only positive integers

//use std::bitset to optimize memory usage

constexpr unsigned int MAXSIZE = 1000;

void subset_sum_test()
{
  vector<int> vec = {1, 6, 7, 4, 5, 6, 7, 10, 1, 1, 2};
  int targetd_number = 23;

  subset_sum(vec, targetd_number);
}

void print_subgroup(const vector<int>& vec, 
                    const int target, 
		    const std::bitset<MAXSIZE>& flag_table)
{
  const int rowSize = vec.size();
  const int colSize = target;

  int target_copy = target;

  if (flag_table[rowSize*colSize-1])
  {
    cout<<"there exists a sub group that sum up to value "<<target<<endl;
    for (int i=rowSize-1; i>0; --i)
    {
      //The check is necessary
      if (target_copy == vec[i])
      {
	cout<<vec[i]<<endl;
	return;
      }
      else if (target_copy - vec[i] >0)
      {
	if (flag_table[(i-1)*colSize + target_copy-vec[i]-1])
	{
	  cout<<vec[i]<<" ";
	  target_copy -= vec[i];
	}
      }
    }

    //The last one needs to be handled independently
    //Can I improve this?

    if (target_copy==vec[0])
    {
      cout<<vec[0]<<endl;
    }
  }
  else
  {
    cout<<"not exist a sub group that sum up to value "<<target<<endl;
  }
}

void subset_sum(const vector<int>& vec, const int target)
{
  if (vec.empty())
  {
    cout<<"the size of the vector is empty"<<endl;
    return;
  }

  const int rowSize = vec.size();
  const int colSize = target;

  //rowSize by colSize flag table
  //flag_table(i,j) stands for whether
  //it is possible to add a sub group of values
  //form a[1] to a[i] so that the sum is j
  std::bitset<MAXSIZE> flag_table;

  //index from zero
  flag_table.set(vec[0]-1);

  for (int i=1; i<rowSize; ++i)
  {
    flag_table.set(i*colSize+vec[i]-1);

    for (int j=1; j<=target; ++j)
    {
      if (flag_table[(i-1)*colSize + j-1])
      {
	flag_table.set(i*colSize + j-1);
      }

      if ((j-vec[i]>0) && flag_table[(i-1)*colSize + j-vec[i]-1]) 
      {
	flag_table.set(i*colSize + j-1);
      }

    }
  }

  cout<<"Finishing Finding Process"<<endl;

  print_subgroup(vec, target, flag_table);
}

