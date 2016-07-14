#include "Board.hpp"

inline void Board::Init()
{
	tbl = new Cell*[nrow];

	for (size_t i = 0; i < nrow; ++i)
	{
		tbl[i] = new Cell[ncol]{ 0 };
	}
}

inline void Board::Gen(const uint8_t &bct)
{
	size_t ri, rc;

	for (size_t i = 0; i < bct;)
	{
		ri = rand() % nrow;
		rc = rand() % ncol;
		if (!tbl[ri][rc].bmb)
		{
			tbl[ri][rc].bmb = true;
			++i;
		}
	}
}

char Board::Disp(const uint8_t &row, const uint8_t &col)
{
	return 0;
}

void Board::SetFlag(const uint8_t &row, const uint8_t &col, const uint8_t &flag = 0)
{
	switch (flag)
	{
	case 0:
		tbl[row][col].flg = false;
		tbl[row][col].flt = false;
		break;
	case 1:
		tbl[row][col].flg = true;
		tbl[row][col].flt = false;
		break;
	case 2:
		tbl[row][col].flg = true;
		tbl[row][col].flt = true;
	default:
		break;
	}
}

bool Board::Probe(const uint8_t &row, const uint8_t &col)
{
	if (tbl[row][col].bmb)
		return true;
	else
		return false;
}

Board::Board(const uint8_t &row, const uint8_t &col, const uint8_t &bct, const unsigned &seed)
{
	this->nrow = row;
	this->ncol = col;

	Init();
	srand(this->seed = seed);
	Gen(bct);
}

Board::~Board()
{
	for (size_t i = 0; i < nrow; ++i)
		delete[] tbl[i];

	delete[] tbl;
}

std::ostream& operator<<(std::ostream &out, Board &board)
{
	return out;
}