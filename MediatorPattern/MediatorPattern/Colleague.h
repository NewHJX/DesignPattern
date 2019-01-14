#ifndef MEDIATOR_PATTERN_COLLEAGUE_H_
#define MEDIATOR_PATTERN_COLLEAGUE_H_
#include<string>
class Mediator;
class Colleague {
public:
	virtual void sendmsg(int toWho, std::string str) = 0;
	virtual void receivemsg(std::string str) = 0;
	virtual void setMediator(Mediator *mediator) = 0;
};

#endif