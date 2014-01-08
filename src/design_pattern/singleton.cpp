#include <iostream>
#include <memory>
using namespace std;


class Singleton
{
public:
  //disable copy and move functionality
  Singleton(const Singleton& s) = delete;
  Singleton operator=(const Singleton& s) = delete;
  Singleton(const Singleton&& s) = delete;
  Singleton operator=(const Singleton&& s) = delete;
  
  void method();
  static shared_ptr<Singleton> get_instance();

private:
  Singleton(){cout<<"get created"<<endl;};
  static shared_ptr<Singleton> m_singleton;
}; //don't forget the semicolon

void Singleton::method()
{
  cout<<"Singlton"<<endl;
}

shared_ptr<Singleton> Singleton::m_singleton = nullptr;

shared_ptr<Singleton> Singleton::get_instance()
{
  if (m_singleton)
  {
    return m_singleton;
  }
  else
  {
    m_singleton = shared_ptr<Singleton>(new Singleton);
    return m_singleton; 
  }
}


void singleton_test()
{
  shared_ptr<Singleton> s1, s2;
  s1 = Singleton::get_instance();
  s1->method();
  s2 = Singleton::get_instance();
  s2->method();
}
