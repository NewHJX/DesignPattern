#ifndef MEDIATOR_PATTERN_MEDIATOR_H_
#define MEDIATOR_PATTERN_MEDIATOR_H_
#include<string>
class Colleague;
class Mediator {
public:
	virtual void operation(int nWho, std::string str) = 0;
	virtual void registered(int nWho, Colleague *aColleague) = 0;
};

#endif