#include"Stragety.h"
class ConcreteStragetyA :public Stragety {
public:
	ConcreteStragetyA();
	virtual ~ConcreteStragetyA();
	void algorithm();
};

class ConcreteStragetyB :public Stragety {
public:
	ConcreteStragetyB();
	virtual ~ConcreteStragetyB();
	void algorithm();
};