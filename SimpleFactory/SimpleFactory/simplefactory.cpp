#include<iostream>
#include<string>
using namespace std;
class Pizza {
public:
	virtual void prepare() { cout << "prepare" << endl; }
	virtual void bake() { cout << "bake" << endl; }
	virtual void cut() { cout << "cut" << endl; }
	virtual void box() { cout << "box" << endl; }
};
class CheesePizza : public Pizza {
	void prepare() { cout << "cheese pizza prepare" << endl; }
	void bake() { cout << "cheese pizza bake" << endl; }
	void cut() { cout << "cheese pizza cut" << endl; }
	void box() { cout << "cheese pizza box" << endl; }
};
class SimplePizzaFactory {
public:
	Pizza* createPizza(string type) {
		Pizza* pizza = NULL;
		if (type.compare("cheese") == 0) {
			pizza = new CheesePizza();
		}
		return pizza;
	}
};

class PizzaStore {
public:
	SimplePizzaFactory *factory;
	PizzaStore(SimplePizzaFactory *f) {
		factory = f;
	}
	Pizza* orderPizza(string type) {
		Pizza *pizza = factory->createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}
};

int main() {
	SimplePizzaFactory *factory = new SimplePizzaFactory();
	PizzaStore *store = new PizzaStore(factory);
	store->orderPizza("cheese");
	getchar();
	return 0;
}