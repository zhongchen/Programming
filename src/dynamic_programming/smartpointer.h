class BaseClass
{
public:
  BaseClass();
  BaseClass(int i);
  ~BaseClass();

private:
  int value;
};

class DerivedClass: public BaseClass
{
public:
  DerivedClass();
  DerivedClass(int i);
  ~DerivedClass();
};

void shared_ptr_test();
void unique_ptr_test();
