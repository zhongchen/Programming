#include "smartpointer.h"
#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

BaseClass::BaseClass()
{
  cout<<"default base class constructor"<<endl;
}

BaseClass::BaseClass(int i)
{
  value = i;
  cout<<"parameter base class constructor"<<endl;
}

BaseClass::~BaseClass()
{
  cout<<"default base class destructor"<<endl;
}

DerivedClass::DerivedClass()
{
  cout<<"default derived class constructor"<<endl;
}

DerivedClass::DerivedClass(int i): BaseClass(i)
{
  cout<<"parameter derived class constructor"<<endl;
}

DerivedClass::~DerivedClass()
{
  cout<<"default derived class destructor"<<endl;
}

void shared_ptr_test()
{
  auto ptr = make_shared<BaseClass>(5);
  cout<<endl;
  shared_ptr<BaseClass> baseptr(new DerivedClass(4));
  shared_ptr<DerivedClass> derivedptr;
  derivedptr = static_pointer_cast<DerivedClass>(baseptr); 
  cout<<endl;
}
template <typename T>
void foo(T* t){
  cout<< *t <<endl;
}

void unique_ptr_test(){
  //unique_ptr only allows one copy of the pointer
  std::unique_ptr<int> p1(new int(42));
  if(p1)
  //try not to call get() as much as possible.
  foo(p1.get());
  // transfer ownership
  std::unique_ptr<int> p2 = std::move(p1); 
  (*p2)++;

  if(p2)
  foo(p2.get());
}
