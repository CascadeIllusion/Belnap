#ifndef BELNAP_H
#define BELNAP_H

#include "tables.h"
#include <iostream>
#include <functional>

const enum State {
	BNeither = -1,
	BFalse = 0,
	BTrue = 1,
	BBoth = 2,
	BInvalid = 3,
};

constexpr State Neither = State::BNeither;
constexpr State False = State::BFalse;
constexpr State True = State::BTrue;
constexpr State Both = State::BBoth;
constexpr State Invalid = State::BInvalid;

class Belnap {

private:

	State state;

public:

	Belnap(State state);

	Belnap(int state);

	State getState();

	void operator= (State state);

	void operator= (int state);

	static State charToState(char state);

	friend std::ostream& operator<<(std::ostream& out, Belnap belnap);

	friend bool operator== (Belnap arg1, Belnap arg2);

	friend bool operator!= (Belnap arg1, Belnap arg2);

	// Creates a unary Belnap operator
	static std::function<Belnap(Belnap)> createOperator(const char table[2][4]);

	// Belnap NOT Gate
	friend Belnap operator!(Belnap arg);

	// Creates a binary Belnap operator
	static std::function<Belnap(Belnap, Belnap)> createOperator(const char table[5][5]);

	// Belnap AND Gate
	friend Belnap operator&&(Belnap arg1, Belnap arg2);

	// Belnap OR Gate
	friend Belnap operator||(Belnap arg1, Belnap arg2);

};

void testAnd();

#endif