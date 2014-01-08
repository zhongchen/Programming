#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Observeable;

class Observer
{
public:
    Observer(string name) : m_observerName(name) {}
    virtual ~Observer(){ cout<< "Observer Base Destructor" <<endl;}
    virtual void UpdateInfo(){ m_hasReceivedUpdates = true;}
    void SubscribeService(shared_ptr<Observeable>&);
    string GetObserverName() const { return m_observerName; }

private:
    shared_ptr<Observeable> m_subscribedService; 
    string m_observerName;
    bool m_hasReceivedUpdates;
};

class Observeable
{
public:
    Observeable(string name) : m_serviceName(name) {}
    virtual ~Observeable(){ cout<< "Observeable Base Destructor" <<endl;}
    bool HasNewUpdate() { return m_status; }
    void RegisterObservers( shared_ptr<Observer>&);
    void NotifyObservers();
    void SetStatus(bool status) { m_status = status; NotifyObservers();}
    string GetServiceName() const { return m_serviceName; }

private:
    vector<shared_ptr<Observer>> m_observerList;
    bool m_status;
    string m_serviceName;
};

class System : public Observeable 
{
public:
    System(string name) : Observeable(name) {}
    ~System() { cout<<"System Destructor"<<endl; }

};

class SystemView : public Observer
{
public:
    SystemView(string name) :Observer(name) {}
    ~SystemView() { cout<<"System View Destructor"<<endl; }

};

void Test_Observe_Pattern();
