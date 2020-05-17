#include "belnap.h"
#include "tests.h"

Belnap::Belnap(State state) {
	this->state = state;
}

State Belnap::getState() {
	return this->state;
}

void Belnap::operator=(State state) {
	this->state = state;
}

std::ostream& operator<<(std::ostream& out, Belnap belnap) {
	out << static_cast<int>(belnap.state);

	return out;
}

bool operator==(Belnap arg1, Belnap arg2) {
	return arg1.getState() == arg2.getState();
}

std::function<Belnap(Belnap)> Belnap::createOperator(char table[2][4]) {
	State values[4];

	for (int i = 0; i <= 3; i++) {
		// Use the second row to ignore the input row
		switch (table[1][i]) {
		case 'N':
			values[i] = Neither;
			break;
		case 'F':
			values[i] = False;
			break;
		case 'T':
			values[i] = True;
			break;
		case 'B':
			values[i] = Both;
			break;
		default:
			// TODO: Exception
			break;
		}
	}

	return [=](Belnap arg) {
		return values[arg.getState() + 1];
	};
}

Belnap operator!(Belnap arg) {

	char Table[2][4] = {
		{'N', 'F', 'T', 'B'},
		{'N', 'T', 'F', 'B'},
	};

	auto Operator = Belnap::createOperator(Table);

	return Operator(arg);
}

std::function<Belnap(Belnap, Belnap)> Belnap::createOperator(char table[5][5]) {

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
				values[i - 1][j - 1] = Neither;
				break;
			case 'F':
				values[i - 1][j - 1] = False;
				break;
			case 'T':
				values[i - 1][j - 1] = True;
				break;
			case 'B':
				values[i - 1][j - 1] = Both;
				break;
			default:
				// TODO: Exception
				break;
			}

		}

	}

	return [=](Belnap arg1, Belnap arg2) {
		return values[arg1.getState() + 1][arg2.getState() + 1];
	};

}

Belnap operator&&(Belnap arg1, Belnap arg2) {
	char Table[5][5] = {
		{' ', 'N', 'F', 'T', 'B'},
		{'N', 'N', 'F', 'N', 'F'},
		{'F', 'F', 'F', 'F', 'F'},
		{'T', 'N', 'F', 'T', 'B'},
		{'B', 'F', 'F', 'B', 'B'},
	};

	auto Operator = Belnap::createOperator(Table);

	return Operator(arg1, arg2);
}

Belnap operator||(Belnap arg1, Belnap arg2) {

	char Table[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'N', 'T', 'T'},
	{'F', 'N', 'F', 'T', 'B'},
	{'T', 'T', 'T', 'T', 'T'},
	{'B', 'T', 'B', 'T', 'B'},
	};

	auto Operator = Belnap::createOperator(Table);

	return Operator(arg1, arg2);

}

int main() {
	testAnd();
}