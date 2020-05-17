#include <iostream>
#include <functional>

#ifndef BELNAP_H
#define BELNAP_H

enum State {
	Neither = -1,
	False = 0,
	True = 1,
	Both = 2,
};

// Prefer use of these constants to mimic the way booleans are declared
constexpr int both = State::Both;
constexpr int neither = State::Neither;

template<class T>

class Belnap {

private:

	State state;

	enum class EvalContext {
		TowardsBoth, // Both = true; neither = false
		TowardsNeither, // Both = false; neither = true
		TowardsFalse, // Both and neither = false
		TowardsTrue, // Both and neither = true
		Error, // Throw an exception when attempting to evaluate
	};

public:

	Belnap(T state) {
		this->state = (State)state;
	}

	State getState() {
		return this->state;
	}

	void operator= (T state) {
		this->state = (State)state;
	}

	template <class T> friend std::ostream& operator<<(std::ostream& out, Belnap<T> belnap) {
		out << static_cast<int>(belnap.state);

		return out;
	}

	// Creates a unary Belnap operator
	static std::function<Belnap<T>(Belnap<T>)> createOperator(char table[2][4]) {

		State values[4];

		for (int i = 0; i <= 3; i++) {
			// Use the second row to ignore the input row
			switch (table[1][i]) {
			case 'N':
				values[i] = State::Neither;
				break;
			case 'F':
				values[i] = State::False;
				break;
			case 'T':
				values[i] = State::True;
				break;
			case 'B':
				values[i] = State::Both;
				break;
			default:
				// TODO: Exception
				break;
			}
		}

		return [=](Belnap<T> arg) {
			return values[arg.getState() + 1];
		};

	}

	// Belnap NOT Gate
	friend Belnap<T> operator!(Belnap<T> arg) {

		char Table[2][4] = {
		{'N', 'F', 'T', 'B'},
		{'N', 'T', 'F', 'B'},
		};

		auto Operator = createOperator(Table);

		return Operator(arg);

	}

	// Creates a binary Belnap operator
	static std::function<Belnap<T>(Belnap<T>, Belnap<T>)> createOperator(char table[5][5]) {

		State values[4][4];

		for (int i = 0; i <= 4; i++) {

			// Ignore the input row
			if (i == 0) {
				continue;
			}

			for (int j = 0; j <= 4; j++) {

				// Ignore the input column
				if (j == 0) {
					continue;
				}

				switch (table[i][j]) {
				case 'N':
					values[i - 1][j - 1] = State::Neither;
					break;
				case 'F':
					values[i - 1][j - 1] = State::False;
					break;
				case 'T':
					values[i - 1][j - 1] = State::True;
					break;
				case 'B':
					values[i - 1][j - 1] = State::Both;
					break;
				default:
					// TODO: Exception
					break;
				}

			}

		}

		return [=](Belnap<T> arg1, Belnap<T> arg2) {
			return values[arg1.getState() + 1][arg2.getState() + 1];
		};

	}

	// Belnap AND Gate
	friend Belnap<T> operator&&(Belnap<T> arg1, Belnap<T> arg2) {

		char Table[5][5] = {
		{' ', 'N', 'F', 'T', 'B'},
		{'N', 'N', 'F', 'N', 'F'},
		{'F', 'F', 'F', 'F', 'F'},
		{'T', 'N', 'F', 'T', 'B'},
		{'B', 'F', 'F', 'B', 'B'},
		};

		auto Operator = createOperator(Table);

		return Operator(arg1, arg2);

	}

	// Belnap OR Gate
	friend Belnap<T> operator||(Belnap<T> arg1, Belnap<T> arg2) {

		char Table[5][5] = {
		{' ', 'N', 'F', 'T', 'B'},
		{'N', 'N', 'N', 'T', 'T'},
		{'F', 'N', 'F', 'T', 'B'},
		{'T', 'T', 'T', 'T', 'T'},
		{'B', 'T', 'B', 'T', 'B'},
		};

		auto Operator = createOperator(Table);

		return Operator(arg1, arg2);

	}

};

void testAnd();

#endif