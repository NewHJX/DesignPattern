#pragma once
#include <mutex>
class Singleton {
private:
	Singleton();
	static Singleton *single;
	static std::mutex g_mutex;
public:
	~Singleton();
	static Singleton *getInstance();
	void singletonOperation();
};