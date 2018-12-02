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
//	//���Ǵ�״̬��ǡ���Ķ���
//	void insertQuarter();
//	void ejectQuarter();
//	void turnCrank();
//	//���Ǵ�״̬��ǡ���Ķ���
//	void dispense();
//};
//
//class SoldState :public IState {
//private:
//	GumballMachine* gumballMachine;
//public:
//	SoldState(GumballMachine* gumball);
//	//���Ǵ�״̬��ǡ���Ķ���
//	void insertQuarter();
//	//���Ǵ�״̬��ǡ���Ķ���
//	void ejectQuarter();
//	//���Ǵ�״̬��ǡ���Ķ���
//	void turnCrank();
//	void dispense();
//};