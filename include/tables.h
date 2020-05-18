// Unary truth tables

// Logical NOT
constexpr char TableNOT[2][4] = {
	{'N', 'F', 'T', 'B'},
	{'N', 'T', 'F', 'B'},
};

// Binary truth tables

// Logical AND
constexpr char TableAND[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'F', 'N', 'F'},
	{'F', 'F', 'F', 'F', 'F'},
	{'T', 'N', 'F', 'T', 'B'},
	{'B', 'F', 'F', 'B', 'B'},
};

// Logical OR
constexpr char TableOR[5][5] = {
	{' ', 'N', 'F', 'T', 'B'},
	{'N', 'N', 'N', 'T', 'T'},
	{'F', 'N', 'F', 'T', 'B'},
	{'T', 'T', 'T', 'T', 'T'},
	{'B', 'T', 'B', 'T', 'B'},
};