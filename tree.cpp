#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "tree.h"
#include "board.h"

using namespace std;



tree::tree(){
	
	
	value=-1;
	tree_board=new tic();
	children_num=tree_board->col_size;
	children=new tree*[children_num];
	for(int i=0;i<children_num;i++){
		children[i]=NULL;
	}
	
	
}


void tree::add_children(){
	for(int i=0;i<children_num;i++){
	
		//children creation
		children[i]=new tree;
		*(children[i]->tree_board)=*(tree_board);
		
		if(tree_board->player=='O') children[i]->tree_board->player='X';
		else if(tree_board->player=='X') children[i]->tree_board->player='O';
				
		//children move
		children[i]->tree_board->possible_move();
		
		int r,c;
		r=children[i]->tree_board->moves[i].row_idx;
		c=children[i]->tree_board->moves[i].col_idx;
		
		if(r!=-1&&c!=-1) children[i]->tree_board->board[r][c]=children[i]->tree_board->player;
		
	}
}


bool tree::is_deep(int d){
	if(d==8){
		
		return true;
	}
	else{
		this->add_children();
		return false;
	}
}


int tree::calc_value(char player){
	

	int r=tree_board->row_size;
	int c=tree_board->col_size;
	int score=0;
	
	//horizon check
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(j+3>=c) continue;
			
			char c1=tree_board->board[i][j];
			char c2=tree_board->board[i][j+1];
			char c3=tree_board->board[i][j+2];
			char c4=tree_board->board[i][j+3];
			
			//3 horizon
			if(player==c1&&c1==c2&&c2==c3&&c4==' ') score+=100000;
			else if(player==c1&&c1==c2&&c2==c4&&c3==' ') score+=100000;
			else if(player==c1&&c1==c3&&c3==c4&&c2==' ') score+=100000;
			else if(player==c2&&c2==c3&&c3==c4&&c1==' ') score+=100000;
			
			//2 horizon
			if(player==c1&&c1==c2&&c3==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c3&&c2==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c4&&c2==' '&&c3==' ') score+=1000;
			else if(player==c2&&c2==c3&&c1==' '&&c4==' ') score+=1000;
			else if(player==c2&&c2==c4&&c1==' '&&c3==' ') score+=1000;
			else if(player==c3&&c3==c4&&c1==' '&&c2==' ') score+=1000;
			
		}
	}
	
	//vertical check
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			
			if(i+3>=r) continue;
			
			char c1=tree_board->board[i][j];
			char c2=tree_board->board[i+1][j];
			char c3=tree_board->board[i+2][j];
			char c4=tree_board->board[i+3][j];
			
			//3 vertical
			if(player==c1&&c1==c2&&c2==c3&&c4==' ') score+=100000;
			else if(player==c1&&c1==c2&&c2==c4&&c3==' ') score+=100000;
			else if(player==c1&&c1==c3&&c3==c4&&c2==' ') score+=100000;
			else if(player==c2&&c2==c3&&c3==c4&&c1==' ') score+=100000;
			
			
			//2 vertical
			if(player==c1&&c1==c2&&c3==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c3&&c2==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c4&&c2==' '&&c3==' ') score+=1000;
			else if(player==c2&&c2==c3&&c1==' '&&c4==' ') score+=1000;
			else if(player==c2&&c2==c4&&c1==' '&&c3==' ') score+=1000;
			else if(player==c3&&c3==c4&&c1==' '&&c2==' ') score+=1000;			
		}
	}
	
	//left diagonal check
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			
			if(i+3>=r) continue;
			if(j+3>=c) continue;
			
			char c1=tree_board->board[i][j];
			char c2=tree_board->board[i+1][j+1];
			char c3=tree_board->board[i+2][j+2];
			char c4=tree_board->board[i+3][j+3];
			
			//3 left diagonal
			if(player==c1&&c1==c2&&c2==c3&&c4==' ') score+=10000;
			else if(player==c1&&c1==c2&&c2==c4&&c3==' ') score+=10000;
			else if(player==c1&&c1==c3&&c3==c4&&c2==' ') score+=10000;
			else if(player==c2&&c2==c3&&c3==c4&&c1==' ') score+=10000;
			
			//2 left diagonal
			if(player==c1&&c1==c2&&c3==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c3&&c2==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c4&&c2==' '&&c3==' ') score+=1000;
			else if(player==c2&&c2==c3&&c1==' '&&c4==' ') score+=1000;
			else if(player==c2&&c2==c4&&c1==' '&&c3==' ') score+=1000;
			else if(player==c3&&c3==c4&&c1==' '&&c2==' ') score+=1000;
		}
	}
	
	//right diagonal check
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i-3<0) continue;
			if(j+3>=c) continue;
			
			char c1=tree_board->board[i][j];
			char c2=tree_board->board[i-1][j+1];
			char c3=tree_board->board[i-2][j+2];
			char c4=tree_board->board[i-3][j+3];
			
			//3 right diagonal
			if(player==c1&&c1==c2&&c2==c3&&c4==' ') score+=10000;
			else if(player==c1&&c1==c2&&c2==c4&&c3==' ') score+=10000;
			else if(player==c1&&c1==c3&&c3==c4&&c2==' ') score+=10000;
			else if(player==c2&&c2==c3&&c3==c4&&c1==' ') score+=10000;

			//2 right diagonal
			if(player==c1&&c1==c2&&c3==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c3&&c2==' '&&c4==' ') score+=1000;
			else if(player==c1&&c1==c4&&c2==' '&&c3==' ') score+=1000;
			else if(player==c2&&c2==c3&&c1==' '&&c4==' ') score+=1000;
			else if(player==c2&&c2==c4&&c1==' '&&c3==' ') score+=1000;
			else if(player==c3&&c3==c4&&c1==' '&&c2==' ') score+=1000;
		}
	}
	
	return score;
	
	
	
	
}
