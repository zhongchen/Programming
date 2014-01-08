#include "HashTest.h"
#include <functional> //std::hash
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void HashTest()
{
	unordered_map_test();
    //StringHashTest();
    //MyStructHashTest();
}

void unordered_map_test()
{
	unordered_map<int, int> myMap;
	for (int i =0; i < 10; ++i)
	{
		cout<<"number of items: "<<myMap.size()<<endl;
		cout<<"number of buckets: "<<myMap.bucket_count()<<endl;
		cout<<"load factor: "<<myMap.load_factor()<<endl;
		//cout<<"max load factor: "<<myMap.max_load_factor()<<endl;
		myMap[i] = i;
	}

	for (int i = 0; i < myMap.bucket_count(); ++i)
	{
		cout<<myMap.bucket_size(i)<<" ";
	}
	cout<<endl;
	
	unordered_map<int, int>::iterator itr = myMap.find(4);
	if (itr != myMap.end())
	{
		cout<<"found"<<endl;
		cout<<itr->first<<endl;
		cout<<itr->second<<endl;
	}
	else
	{
		cout<<"not found"<<endl;
	}
}

void StringHashTest()
{
    string mystring = "this is a hash testing string";
    std::hash<std::string> string_hash_fn;
    std::size_t strhash = string_hash_fn(mystring);
    cout<<"The hash for the string is :"<<strhash<<endl;

	cout<<"Int hash"<<endl;
	std::hash<int> int_hash_fn;
	for (int j = 0; j < 10; ++j)
	{
		cout<<int_hash_fn(j)<<endl;
	}
}


template<>
class MyHash<S>
{
public:
    std::size_t operator()(const S & s) const
	{
		auto firstHash = std::hash<string>()(s.first);
		auto secondHash = std::hash<string>()(s.second);
		return firstHash ^ (secondHash << 1);   
	}
};

void MyStructHashTest()
{
    S s("f", "s");
    cout<<s.first<<'\t'<<s.second<<endl;
    cout<<MyHash<S>()(s)<<endl;
}
