#pragma once
#include"Stragety.h"
class Context {
public:
	Context();
	virtual ~Context();
	void algorithm();
	void set_Strategy(Stragety *st);
private:
	Stragety *m_pStrategy;
};