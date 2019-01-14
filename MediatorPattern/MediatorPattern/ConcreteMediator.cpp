#include "ConcreteMediator.h"
#include "Colleague.h"

void ConcreteMediator::operation(int nWho, std::string str) {
	std::map<int, Colleague*>::const_iterator it = m_mpColleague.find(nWho);
	if (it == m_mpColleague.end()) {
		printf("not found this colleague!\n");
		return;
	}
	Colleague *pc = it->second;
	pc->receivemsg(str);
}
void ConcreteMediator::registered(int nWho, Colleague *aColleague) {
	std::map<int, Colleague*>::const_iterator it = m_mpColleague.find(nWho);
	if (it == m_mpColleague.end()) {
		m_mpColleague.insert(std::make_pair(nWho, aColleague));
		aColleague->setMediator(this);
	}
}