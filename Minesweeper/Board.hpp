#pragma once

#include "Headers.hpp"
#include <ctime>

class Board
{
private:
	unsigned	seed;
	uint8_t		nrow,
				ncol;

	struct Cell
	{
		bool	res : 1,
				hid : 1,
				flg : 1,
				flt : 1,
				bmb : 1;
		uint8_t	val : 3;
	}			**tbl;

	void Init	();
	void Gen	(const uint8_t&);
	char Disp	(const uint8_t&, const uint8_t&);

public:
	void SetFlag(const uint8_t&, const uint8_t&, const uint8_t&);
	bool Probe	(const uint8_t&, const uint8_t&);

	Board		(const uint8_t&, const uint8_t&, const uint8_t&, const unsigned& = time(nullptr));
	friend std::ostream& operator<<(std::ostream&, Board&);
	~Board		();
};