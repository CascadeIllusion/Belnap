#include <cassert>
#include "belnap.h"
#include "tests.h"

void runTests() {

	testNot();
	testAnd();
	testOr();

}

void testNot() {
	for (int i = 0; i <= 3; i++) {
		Belnap arg = i - 1;
		assert(Belnap::charToState(TableNOT[1][i]) == !arg);
	}
}

void testAnd() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			Belnap arg1 = i - 2;
			Belnap arg2 = j - 2;
			assert(Belnap::charToState(TableAND[i][j]) == (arg1 && arg2));
		}
	}

}

void testOr() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			Belnap arg1 = i - 2;
			Belnap arg2 = j - 2;
			assert(Belnap::charToState(TableOR[i][j]) == (arg1 || arg2));
		}
	}

}