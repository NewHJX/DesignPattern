#ifndef MEDIATOR_PATTERN_CONCRETECOLLEAGUEA_H_
#define MEDIATOR_PATTERN_CONCRETECOLLEAGUEA_H_
#include "Mediator.h"
#include "Colleague.h"
class ConcreteColleagueA :public Colleague {
public:
	virtual void sendmsg(int toWho, std::string str);
	virtual void receivemsg(std::string str);
	virtual void setMediator(Mediator *mediator);
private:
	Mediator *m_pMediator;
};

#endif
