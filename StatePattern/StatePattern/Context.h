//#pragma once
//#include "State.h"
//class GumballMachine {
//private:
//	IState *soldOutState = new SoldOutState(this);
//	IState *noQuarterState = new NoQuarterState(this);
//	IState *hasQuarterState = new HasQuarterState(this);
//	IState *soldState = new SoldState(this);
//	IState *state;
//	int count = 0;
//public:
//	GumballMachine() {}
//	GumballMachine(int count) {
//		count = count;
//		if (count > 0) {
//			state = noQuarterState;
//		}
//	}
//	void insertQuarter() {
//		state->insertQuarter();
//	}
//	void ejectQuarter() {
//		state->ejectQuarter();
//	}
//	void turnCrank() {
//		state->turnCrank();
//		state->dispense();
//	}
//	void setState(IState *s) {
//		state = s;
//	}
//	
//	IState* getSoldOutState() {
//		return soldOutState;
//	}
//
//	IState* getNoQuarterState() {
//		return noQuarterState;
//	}
//
//	IState* getHasQuarterState() {
//		return hasQuarterState;
//	}
//
//	IState* getSoldState() {
//		return soldState;
//	}
//	
//	void releaseBall() {
//		std::cout << "a gumball comes rooling out the slot" << std::endl;
//		if (count > 0) {
//			count = count - 1;
//		}
//	}
//	int getBallCount() {
//		return count;
//	}
//};