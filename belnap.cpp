#include <iostream>
#include <functional>

namespace belnap {

	enum State {
		Neither = -1,
		False = 0,
		True = 1,
		Both = 2,
	};

	// Prefer use of these constants to mimic the way booleans are declared
	constexpr short both = State::Both;
	constexpr short neither = State::Neither;

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

		void operator = (T state) {
			this->state = (State)state;
		}

		friend std::ostream& operator<<(std::ostream& out, Belnap belnap) {
			out << static_cast<short>(belnap.state);

			return out;
		}

		friend Belnap operator&&(Belnap arg1, Belnap arg2) {

			char andTable[5][5] = {
			{' ', 'N', 'F', 'T', 'B'},
			{'N', 'N', 'F', 'N', 'F'},
			{'F', 'F', 'F', 'F', 'F'},
			{'T', 'N', 'F', 'T', 'B'},
			{'B', 'F', 'F', 'B', 'B'},
			};

			auto andOperator = createOperator(andTable);

			return andOperator(arg1, arg2);

		}

		friend Belnap operator||(Belnap arg1, Belnap arg2) {

			char orTable[5][5] = {
			{' ', 'N', 'F', 'T', 'B'},
			{'N', 'N', 'N', 'T', 'T'},
			{'F', 'N', 'F', 'T', 'B'},
			{'T', 'T', 'T', 'T', 'T'},
			{'B', 'T', 'B', 'T', 'B'},
			};

			auto orOperator = createOperator(orTable);

			return orOperator(arg1, arg2);

		}

		// Creates a new Belnap binary operator (there are 2^32 possible operators)
		static std::function<Belnap(Belnap, Belnap)> createOperator(char table[5][5]) {

			State values[4][4];

			for (int i = 0; i <= 5; i++) {

				if (i == 0) {
					continue;
				}

				for (int j = 0; j <= 5; j++) {

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

			return [=](Belnap arg1, Belnap arg2) {
				return values[arg1.getState() + 1][arg2.getState() + 1];
			};

		}
	};

}

int main() {
}