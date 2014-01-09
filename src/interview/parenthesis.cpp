#include "parenthesis.h"
#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

void print_parenthesis(int n);

void print_parenthesis_helper(string str, int lsize, int rsize);

void print_parenthesis_test()
{
  int num = 5;
  for (int i=1; i<num; ++i)
  {
    cout<<i<<'\t'<<"parathesis"<<endl;
    print_parenthesis(i);
    cout<<endl;
  }
}

void print_parenthesis(int n)
{
  print_parenthesis_helper("", n, n);
}

void print_parenthesis_helper(string str, int lsize, int rsize)
{
  if ((lsize<0)||(rsize<0))
  {
    cerr<<"invalid size error"<<endl;
    return;
  }

  if (lsize==0 && rsize==0)
  {
    cout<<str<<endl;
    return;
  }

  if (lsize > rsize)
  {
    cerr<<"error left size is larger than right size"<<endl;
  }
  else if (lsize==rsize)
  {
    print_parenthesis_helper(str+"(", lsize-1, rsize);
  }
  else
  {
    if (lsize>0)
    {
      print_parenthesis_helper(str+"(", lsize-1, rsize);
    }

    if (rsize>0)
    {
      print_parenthesis_helper(str+")", lsize, rsize-1);
    }
  }
}

