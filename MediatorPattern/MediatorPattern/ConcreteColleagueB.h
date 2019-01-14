#ifndef MEDIATOR_PATTERN_CONCRETECOLLEAGUEB_H_
#define MEDIATOR_PATTERN_CONCRETECOLLEAGUEB_H_
#include "Mediator.h"
#include "Colleague.h"
class ConcreteColleagueB :public Colleague {
public:
	virtual void sendmsg(int toWho, std::string str);
	virtual void receivemsg(std::string str);
	virtual void setMediator(Mediator *mediator);
private:
	Mediator *m_pMediator;
};

#endif
