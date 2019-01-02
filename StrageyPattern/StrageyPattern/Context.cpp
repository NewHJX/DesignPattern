#include"Context.h"
Context::Context() {

}
Context::~Context() {

}
void Context::algorithm() {
	m_pStrategy->algorithm();
}
void Context::set_Strategy(Stragety *st) {
	m_pStrategy = st;
}