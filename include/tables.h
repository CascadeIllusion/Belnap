// Unary truth tables

// Blank unary table (Do not reference; copy-paste this for making new gates)
constexpr char TableBlankUnary[2][4] = {
	{'N', 'F', 'T', 'B'},
	{' ', ' ', ' ', ' '},
};

// Negation; Logical NOT
constexpr char TableNOT[2][4] = {
	{'N', 'F', 'T', 'B'},
	{'N', 'T', 'F', 'B'},
};

// Conflation
constexpr char TableConflation[2][4] = {
	{'N', 'F', 'T', 'B'},
	{'B', 'F', 'T', 'N'},
};

// Binary truth tables

// Blank binary table (Do not reference; copy-paste this for making new gates)
constexpr char TableBlankBinary[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', ' ', ' ', ' ', ' '},
	{'F', ' ', ' ', ' ', ' '},
	{'T', ' ', ' ', ' ', ' '},
	{'B', ' ', ' ', ' ', ' '},
};

// Conjunction; Logical AND
constexpr char TableAND[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'F', 'N', 'F'},
	{'F', 'F', 'F', 'F', 'F'},
	{'T', 'N', 'F', 'T', 'B'},
	{'B', 'F', 'F', 'B', 'B'},
};

// Disjunction; Logical OR
constexpr char TableOR[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'N', 'T', 'T'},
	{'F', 'N', 'F', 'T', 'B'},
	{'T', 'T', 'T', 'T', 'T'},
	{'B', 'T', 'B', 'T', 'B'},
};

// Exclusive Disjunction; Logical XOR
constexpr char TableXOR[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'N', 'N', 'F'},
	{'F', 'N', 'F', 'T', 'B'},
	{'T', 'N', 'T', 'F', 'B'},
	{'B', 'F', 'B', 'B', 'B'},
};

// Consensus
constexpr char TableConsensus[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'N', 'N', 'N'},
	{'F', 'N', 'F', 'N', 'F'},
	{'T', 'N', 'N', 'T', 'T'},
	{'B', 'N', 'F', 'T', 'B'},
};

// Gullibility
constexpr char TableGullibility[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'F', 'T', 'B'},
	{'F', 'F', 'F', 'B', 'B'},
	{'T', 'T', 'B', 'T', 'B'},
	{'B', 'B', 'B', 'B', 'B'},
};