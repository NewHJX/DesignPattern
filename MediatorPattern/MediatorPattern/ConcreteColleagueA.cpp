#include"ConcreteColleagueA.h"

void ConcreteColleagueA::sendmsg(int toWho, std::string str) {
	printf("send msg from ConcreteColleagueA,to:%d\n", toWho);
	m_pMediator->operation(toWho, str);
}
void ConcreteColleagueA::receivemsg(std::string str) {
	printf("ConcreteColleagueA receivemsg:%s\n", str.c_str());
}

void ConcreteColleagueA::setMediator(Mediator *mediator) {
	m_pMediator = mediator;
}