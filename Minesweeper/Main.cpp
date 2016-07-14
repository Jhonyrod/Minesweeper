#include "Headers.hpp"
#include "Board.hpp"

using namespace std;

void ArgErr(char *argv[])
{
	cout << "Usage: " << argv[0] << " -s [number of rows] [number of columns] -n [number of bombs] (--seed [seed])." << endl;
	exit(0);
}

int main(int argc, char *argv[])
{
	uint8_t row, col, bct;
	unsigned *seed = nullptr;

	if (argc > 1)
	{
		for (uint8_t i = 1; i < argc;++i)
			if (argv[i] == "-s" || argv[i] == "--size")
				if (atoi(argv[++i]) < 0xFF)
				{
					row = static_cast<uint8_t>(atoi(argv[i]));
					if (atoi(argv[++i]) < 0XFF)
						col = static_cast<uint8_t>(atoi(argv[i]));
					else ArgErr(argv);
				}
				else ArgErr(argv);
			else if (argv[i] == "-n" || argv[i] == "--number-of-bombs")
				if (atoi(argv[++i]) < 0XFF)
				{
					bct = static_cast<uint8_t>(atoi(argv[i]));
				}
				else ArgErr(argv);
			else if (argv[i] == "--seed")
				if (atoi(argv[++i]) < 0XFFFFFFFF)
				{
					seed = new unsigned{ static_cast<unsigned>(atoi(argv[i])) };
				}
				else ArgErr(argv);
			else ArgErr(argv);
	}
	else ArgErr(argv);

	Board *board;

	if (seed)
		board = new Board{ row, col, bct, *seed };
	else
		board = new Board{ row, col, bct };
}