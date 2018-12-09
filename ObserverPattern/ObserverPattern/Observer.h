#pragma once
#include<iostream>
using namespace std;

class Observer {
public:
	int val;
	virtual void update(float tmp, float humidity, float pressure) {};
};
class Subject {
public:
	virtual void registerObserver(Observer *o) {};
	virtual void removeObserver(Observer *o) {};
	virtual void notifyObserver() {};
};
class DisplayElement {
public:
	virtual void display() {};
};