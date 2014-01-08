#include "strategy.h"
#include <iostream>
#include <functional> //store std::function
using namespace std;

//What is strategy patter?
//
//
//When do I want to use it?
//
//
//Why do I want to use it?
//
//
//How can I notice the characteristics of the
//situation where strategy fits perfectly
//
class A
{
public:
  A(){cout<<"constructor A"<<endl;}
  ~A(){cout<<"destructor A"<<endl;}
  void print() {cout<<"I am A"<<endl;}
};

class B
{
private:
  A m_A;
public:
  B(){cout<<"constructor B"<<endl;}
  ~B(){cout<<"destructor B"<<endl;}
  void print() {m_A.print();}
};

void StrategyTest()
{
  B b;

}
