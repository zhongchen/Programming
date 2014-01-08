#include "RandomTest.h"
#include <iostream>
#include <map>
#include <random> //std::random
using namespace std;

void RandomTest()
{
	Uniform_Int_Test();
	Uniform_Real_Test();
	Random_Device_Test();
}

void Uniform_Int_Test()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0,4); //[0,4]
	for (int i =0; i < 10; ++i)
	{
		cout<<dist(gen)<<' ';
	}
	cout<<endl;
}

void Uniform_Real_Test()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(0,1); //[0,1)
	for (int i=0; i<10; ++i)
	{
		cout<<dist(gen)<<' ';
	}
	cout<<endl;
}

void Random_Device_Test()
{
	std::random_device rd; 
	std::map<int, int> hist;
	std::uniform_int_distribution<int> dist(0,5);

	for (int i=0; i < 10000; ++i)
	{
		++hist[dist(rd)];
	}

	for (auto p : hist)
	{
		string temp = std::string(p.second / 100, '*') ;
		cout<<p.first <<" " << p.second / 100 <<endl;
	}
}