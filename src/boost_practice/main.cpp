#include <iostream>
using namespace std;

template<int... Elements>  struct count;

template<>
struct count<>
{
    static const int value = 0;
};

template<int T, int... Args>
struct count<T, Args...>
{
    static const int value = 1 + count<Args...>::value;
};
            
int main(int argc, char* argv[])
{
    cout<<count<0,1,2,3,4>::value;
    int i=0;
    cout<<!i<<endl;
}    

















