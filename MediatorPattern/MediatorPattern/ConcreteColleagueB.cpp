#include"ConcreteColleagueB.h"

void ConcreteColleagueB::sendmsg(int toWho, std::string str) {
	printf("send msg from ConcreteColleagueB,to:%d\n", toWho);
	m_pMediator->operation(toWho, str);
}
void ConcreteColleagueB::receivemsg(std::string str) {
	printf("ConcreteColleagueB receivemsg:%s\n", str.c_str());
}

void ConcreteColleagueB::setMediator(Mediator *mediator) {
	m_pMediator = mediator;
}