#include<string>
void HashTest();
void StringHashTest();
void MyStructHashTest();
void unordered_map_test();

template<class T>
class MyHash;

struct S
{
	S(std::string f, std::string s):
		first(f), second(s){}
	std::string first;
    std::string second;
};

