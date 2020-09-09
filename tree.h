#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include "board.h"
using namespace std;


class tree{
	public:
		int value;
		int children_num;
		tree ** children;
		tic * tree_board;
		int calc_value(char);
		void add_children();
		bool is_deep(int);
		tree();
	
		
		
};


#endif
