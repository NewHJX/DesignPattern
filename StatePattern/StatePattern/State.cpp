//#include"State.h"
//
//NoQuarterState::NoQuarterState(GumballMachine* gumball){
//	gumballMachine = gumball;
//}
//
//void NoQuarterState::insertQuarter() {
//	std::cout << "you are insertd a quarter" << std::endl;
//	gumballMachine->setState(gumballMachine->getHasQuarterState());
//}
//void NoQuarterState::ejectQuarter() {
//	std::cout << "you havent inserted a quarter" << std::endl;
//}
//void NoQuarterState::turnCrank() {
//	std::cout << "you turned,but there is no quarter" << std::endl;
//}
//void NoQuarterState::dispense() {
//	std::cout << "you need to pay first" << std::endl;
//}
//
//SoldOutState::SoldOutState(GumballMachine* gumball) {
//	gumballMachine = gumball;
//}
//void SoldOutState::insertQuarter() {
//	std::cout << "sold out,cant insert a quarter" << std::endl;
//}
//void SoldOutState::ejectQuarter() {
//	std::cout << "you havent inserted a quarter" << std::endl;
//}
//void SoldOutState::turnCrank() {
//	std::cout << "you turned,but there is no quarter" << std::endl;
//}
//void SoldOutState::dispense() {
//	std::cout << "you need to pay first" << std::endl;
//}
//
//HasQuarterState::HasQuarterState(GumballMachine* gumball) {
//	gumballMachine = gumball;
//}
////这是此状态不恰当的动作
//void HasQuarterState::insertQuarter() {
//	std::cout << "you cant insert another quarter" << std::endl;
//}
//void HasQuarterState::ejectQuarter() {
//	std::cout << "quarter returned" << std::endl;
//	gumballMachine->setState(gumballMachine->getNoQuarterState());
//}
//void HasQuarterState::turnCrank() {
//	std::cout << "you turned..." << std::endl;
//	gumballMachine->setState(gumballMachine->getSoldState());
//}
////这是此状态不恰当的动作
//void HasQuarterState::dispense() {
//	std::cout << "no gumball dispensed" << std::endl;
//}
//
//SoldState::SoldState(GumballMachine* gumball) {
//	gumballMachine = gumball;
//}
////这是此状态不恰当的动作
//void SoldState::insertQuarter() {
//	std::cout << "please wait,we are already giving you a gumball" << std::endl;
//}
////这是此状态不恰当的动作
//void SoldState::ejectQuarter() {
//	std::cout << "sorry,you already turned the crank" << std::endl;
//}
////这是此状态不恰当的动作
//void SoldState::turnCrank() {
//	std::cout << "turing twice dont get you another gumball" << std::endl;
//}
//void SoldState::dispense() {
//	gumballMachine->releaseBall();
//	if (gumballMachine->getBallCount() > 0) {
//		std::cout << "gumball!!" << std::endl;
//		gumballMachine->setState(gumballMachine->getNoQuarterState());
//	}
//	else {
//		std::cout << "oops,out of gumball" << std::endl;
//		gumballMachine->setState(gumballMachine->getSoldOutState());
//	}
//
//}