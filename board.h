#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

using namespace std;
struct move{
	int col_idx;
	int row_idx;
};

class tic{
	
	public:
		char **board;
		int row_size;
		int col_size;
		move *moves;
		char player;
		bool user_first;
		
		tic();
		void possible_move();
		void display();
		bool is_win();
		bool is_empty();
		tic& operator=(tic &t);
};

#endif
