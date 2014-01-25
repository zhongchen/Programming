#include "Animation.h"
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

//bitset size
const unsigned int BITSETSIZE = 10000;
//to do error checking
//scale
//
//
//Calculate the number of steps of animation
//use bitset to record the state of each step

int CalculateMaxNumSteps(int speed, string initial)
{
    int num_step = 0;
    int max_num_step = 0;
    int distance = 0;
    int length = initial.size();
    auto data = initial.data();

    for (int i=0; i<length; ++i)
    {
	if (data[i]=='R')
	{
	    distance = length-1-i;
	}
	else if (data[i]=='L')
	{
	    distance = i;
	}
	else if (data[i]=='.')
	{
	    continue;
	}
	else
	{
	    cerr<<"error initialization"<<endl;
	}
	num_step = distance / speed + 1;
	if (num_step > max_num_step)
	    max_num_step = num_step;
    }
    return max_num_step;
}

void RunAnimation(int speed, string init, std::bitset<BITSETSIZE>& states)
{
    int chamber_length = init.size();
    auto data = init.data();
    int distance = 0;
    int steps = 0;
    //Initial states;
    for (int i=0; i<init.size(); ++i)
    {
	if (data[i]=='R' || data[i]=='L')
	{
	    states.set(i);
	}
    }

    for (int i=0; i<init.size(); ++i)
    {
	if (data[i]=='R')
	{
	    distance = chamber_length-1-i;
	    steps = distance / speed + 1;
	    for (int j=1; j<steps; ++j)
	    {
		states.set(j*chamber_length+i+j*speed);
	    }
	}
	else if (data[i]=='L')
	{
	    distance = i;
	    steps = distance / speed + 1;
	    for (int j=1; j<steps; ++j)
	    {
		states.set(j*chamber_length+i-j*speed);
	    }
	}

    }
}

void OutputAnimation(int length, int num, std::bitset<BITSETSIZE>& states)
{
    for (int i=0; i<num; i++)
    {
	for (int j=0; j<length; j++)
	{
	    if (states[i*length+j])
	    {
		cout<<"X";
	    }
	    else
	    {
		cout<<".";
	    }
	}
	cout<<endl;
    }
}

void Animation(int speed, string initial)
{
    int chamber_length = initial.size();
    int max_num_step = CalculateMaxNumSteps(speed, initial);
    cout<<max_num_step<<endl;
    //empty chamber 
    if (max_num_step==0)
    {
	cout<<initial<<endl;
	return;
    }

    std::bitset<BITSETSIZE> states;
    RunAnimation(speed, initial, states);
    // +1 the initial state
    OutputAnimation(chamber_length, max_num_step+1, states);
}

void RunAnimation()
{
    int speed1 = 2;
    string init1 = "..R....";
    Animation(speed1, init1);

    int speed2 = 3;
    string init2 = "RR..LRL";
    Animation(speed2, init2);

    int speed3 = 2;
    string init3 = "LRLR.LRLR";
    Animation(speed3, init3);

    int speed4 = 1;
    string init4 = "...";
    Animation(speed4, init4);

    int speed5 = 1;
    string init5 = "LRRL.LR.LRR.R.LRRL.";
    Animation(speed5, init5);

}
