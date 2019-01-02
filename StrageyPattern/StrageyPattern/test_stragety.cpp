#include"Context.h"
#include"ConcreteStragety.h"
int main() {
	Context *context = new Context();
	ConcreteStragetyA *stragetya = new ConcreteStragetyA();
	ConcreteStragetyB *stragetyb = new ConcreteStragetyB();
	context->set_Strategy(stragetya);
	context->algorithm();
	context->set_Strategy(stragetyb);
	context->algorithm();
	getchar();
	return 0;
}