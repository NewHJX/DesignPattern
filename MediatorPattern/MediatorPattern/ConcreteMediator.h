#ifndef MEDIATOR_PATTERN_CONCRETEMEDIATOR_H_
#define MEDIATOR_PATTERN_CONCRETEMEDIATOR_H_
#include "Mediator.h"
#include<map>
class ConcreteMediator :public Mediator {
public:
	virtual void operation(int nWho, std::string str);
	virtual void registered(int nWho, Colleague *aColleatue);

private:
	std::map<int, Colleague*> m_mpColleague;
};

#endif
