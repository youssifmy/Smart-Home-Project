#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class IObserver {
public:
    virtual void update(const string& event, const string& sourceName) = 0;
    virtual ~IObserver() {}
};

class ISubject {
private:
    vector<IObserver*> observers;
public:
    void subscribe(IObserver* observer) {
        observers.push_back(observer);
    }

    void unsubscribe(IObserver* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(const string& event, const string& sourceName) {
        for (auto observer : observers) {
            observer->update(event, sourceName);
        }
    }

    virtual ~ISubject() {}
};

#endif