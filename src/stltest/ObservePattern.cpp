#include <iostream>
#include "ObservePattern.h"
using namespace std;

void Observer::SubscribeService(shared_ptr<Observeable>& obs)
{
    m_subscribedService = obs;
}


void Observeable::NotifyObservers()
{
    for (auto itr = m_observerList.begin(); itr != m_observerList.end(); ++itr)
    {
	(*itr)->UpdateInfo();
    }
}

void Observeable::RegisterObservers(shared_ptr<Observer>& obs)
{
    m_observerList.push_back(obs);
}

void Test_Observe_Pattern()
{
    unique_ptr<System> system(new System("Central Server"));
    unique_ptr<SystemView> firstview(new SystemView("First View"));
    unique_ptr<SystemView> secondView(new SystemView("Second View"));

    cout<<"Start Observe Pattern Test"<<endl;
}
