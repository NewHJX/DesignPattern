#include "ConcreteColleagueA.h"
#include "ConcreteMediator.h"
#include "ConcreteColleagueB.h"

int main() {
	ConcreteColleagueA *pa = new ConcreteColleagueA();
	ConcreteColleagueB *pb = new ConcreteColleagueB();
	ConcreteMediator *pm = new ConcreteMediator();
	pm->registered(1, pa);
	pm->registered(2, pb);
	pa->sendmsg(2, "hello,i am a");
	pb->sendmsg(1, "hello,i am b");
	delete pa, pb, pm;
	getchar();
	return 0;
}
