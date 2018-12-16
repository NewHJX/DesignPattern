#include <iostream>
#include "singleton.h"
using namespace std;
Singleton::Singleton() {
}
Singleton::~Singleton() {}
Singleton *Singleton::single = NULL;
std::mutex Singleton::g_mutex;
Singleton *Singleton::getInstance() {
	if (single == NULL) {
		lock_guard<std::mutex> lock(g_mutex);
		if(single == NULL)
		single = new Singleton();
	}
	return single;
}
void Singleton::singletonOperation() {
	cout << "singleton Operation" << endl;
}

int main() {
	Singleton *single = Singleton::getInstance();
	single->singletonOperation();
	getchar();
	return 0;
}