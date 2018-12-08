
#pragma once
#include<iostream>

//状态接口
class IState {
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
};

class GumballMachine;
class NoQuarterState :public IState {
private:
	GumballMachine * gumballMachine;
public:
	NoQuarterState(GumballMachine* gumball);
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};
//已售完状态
class SoldOutState :public IState {
private:
	GumballMachine * gumballMachine;
public:
	SoldOutState(GumballMachine* gumball);
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};
//已投币状态
class HasQuarterState :public IState {
private:
	GumballMachine * gumballMachine;
public:
	HasQuarterState(GumballMachine* gumball);
	//这是此状态不恰当的动作
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	//这是此状态不恰当的动作
	void dispense();
};
//售卖状态
class SoldState :public IState {
private:
	GumballMachine * gumballMachine;
public:
	SoldState(GumballMachine* gumball);
	//这是此状态不恰当的动作
	void insertQuarter();
	//这是此状态不恰当的动作
	void ejectQuarter();
	//这是此状态不恰当的动作
	void turnCrank();
	void dispense();
};

class GumballMachine {
private:
	IState * soldOutState = new SoldOutState(this);
	IState *noQuarterState = new NoQuarterState(this);
	IState *hasQuarterState = new HasQuarterState(this);
	IState *soldState = new SoldState(this);
	IState *state;
	int count = 0;
public:
	GumballMachine() {}
	GumballMachine(int c) {
		count = c;
		if (count > 0) {
			state = noQuarterState;
		}
	}
	void insertQuarter() {
		state->insertQuarter();
	}
	void ejectQuarter() {
		state->ejectQuarter();
	}
	void turnCrank() {
		state->turnCrank();
		state->dispense();
	}
	void setState(IState *s) {
		state = s;
	}

	IState* getSoldOutState() {
		return soldOutState;
	}

	IState* getNoQuarterState() {
		return noQuarterState;
	}

	IState* getHasQuarterState() {
		return hasQuarterState;
	}

	IState* getSoldState() {
		return soldState;
	}

	void releaseBall() {
		std::cout << "a gumball comes rooling out the slot" << std::endl;
		if (count > 0) {
			count = count - 1;
		}
	}
	int getBallCount() {
		return count;
	}
};

NoQuarterState::NoQuarterState(GumballMachine* gumball) {
	gumballMachine = gumball;
}

void NoQuarterState::insertQuarter() {
	std::cout << "you are insertd a quarter" << std::endl;
	gumballMachine->setState(gumballMachine->getHasQuarterState());
}
void NoQuarterState::ejectQuarter() {
	std::cout << "you havent inserted a quarter" << std::endl;
}
void NoQuarterState::turnCrank() {
	std::cout << "you turned,but there is no quarter" << std::endl;
}
void NoQuarterState::dispense() {
	std::cout << "you need to pay first" << std::endl;
}

SoldOutState::SoldOutState(GumballMachine* gumball) {
	gumballMachine = gumball;
}
void SoldOutState::insertQuarter() {
	std::cout << "sold out,cant insert a quarter" << std::endl;
}
void SoldOutState::ejectQuarter() {
	std::cout << "you havent inserted a quarter" << std::endl;
}
void SoldOutState::turnCrank() {
	std::cout << "you turned,but there is no quarter" << std::endl;
}
void SoldOutState::dispense() {
	std::cout << "you need to pay first" << std::endl;
}

HasQuarterState::HasQuarterState(GumballMachine* gumball) {
	gumballMachine = gumball;
}
//这是此状态不恰当的动作
void HasQuarterState::insertQuarter() {
	std::cout << "you cant insert another quarter" << std::endl;
}
void HasQuarterState::ejectQuarter() {
	std::cout << "quarter returned" << std::endl;
	gumballMachine->setState(gumballMachine->getNoQuarterState());
}
void HasQuarterState::turnCrank() {
	std::cout << "you turned..." << std::endl;
	gumballMachine->setState(gumballMachine->getSoldState());
}
//这是此状态不恰当的动作
void HasQuarterState::dispense() {
	std::cout << "no gumball dispensed" << std::endl;
}

SoldState::SoldState(GumballMachine* gumball) {
	gumballMachine = gumball;
}
//这是此状态不恰当的动作
void SoldState::insertQuarter() {
	std::cout << "please wait,we are already giving you a gumball" << std::endl;
}
//这是此状态不恰当的动作
void SoldState::ejectQuarter() {
	std::cout << "sorry,you already turned the crank" << std::endl;
}
//这是此状态不恰当的动作
void SoldState::turnCrank() {
	std::cout << "turing twice dont get you another gumball" << std::endl;
}
void SoldState::dispense() {
	gumballMachine->releaseBall();
	if (gumballMachine->getBallCount() > 0) {
		std::cout << "gumball!!" << std::endl;
		gumballMachine->setState(gumballMachine->getNoQuarterState());
	}
	else {
		std::cout << "oops,out of gumball" << std::endl;
		gumballMachine->setState(gumballMachine->getSoldOutState());
	}

}
int main() {
	//放入50颗糖果
	GumballMachine* gumballMachine = new GumballMachine(50);
	gumballMachine->insertQuarter();
	gumballMachine->turnCrank();
	getchar();
	return 0;
}