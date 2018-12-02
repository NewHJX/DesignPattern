//#pragma once
//#include<iostream>
//class GumballMachine;
//class IState {
//public:
//	virtual void insertQuarter() = 0;
//	virtual void ejectQuarter() = 0;
//	virtual void turnCrank() = 0;
//	virtual void dispense() = 0;
//};
//
//class NoQuarterState :public IState {
//private:
//	GumballMachine* gumballMachine;
//public:
//	NoQuarterState(GumballMachine* gumball);
//	void insertQuarter();
//	void ejectQuarter();
//	void turnCrank();
//	void dispense();
//};
//
//class SoldOutState :public IState {
//private:
//	GumballMachine* gumballMachine;
//public:
//	SoldOutState(GumballMachine* gumball);
//	void insertQuarter();
//	void ejectQuarter();
//	void turnCrank();
//	void dispense();
//};
//
//class HasQuarterState :public IState {
//private:
//	GumballMachine* gumballMachine;
//public:
//	HasQuarterState(GumballMachine* gumball);
//	//这是此状态不恰当的动作
//	void insertQuarter();
//	void ejectQuarter();
//	void turnCrank();
//	//这是此状态不恰当的动作
//	void dispense();
//};
//
//class SoldState :public IState {
//private:
//	GumballMachine* gumballMachine;
//public:
//	SoldState(GumballMachine* gumball);
//	//这是此状态不恰当的动作
//	void insertQuarter();
//	//这是此状态不恰当的动作
//	void ejectQuarter();
//	//这是此状态不恰当的动作
//	void turnCrank();
//	void dispense();
//};